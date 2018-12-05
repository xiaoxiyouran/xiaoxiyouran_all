# 01 使用属性Property 代替public 直接访问数据成员
## 检查 name 不能设置为空
```csharp
public class Customer 
{
    private string name; 
    public string Name 
    {
        get { return name; } 
        set 
        {
            if (string.IsNullOrEmpty(value))
                throw new ArgumentException("Name cannot be blank", "Name"); 
            name = value;
        } 
        // More Elided.
    } 
}
```


## 多线程

因为属性是用方法实现的，增加多线程的支持是很容易的。你可以加强 get 和 set 访问器（accessors）的实现来提供数据访问的同步。 

```csharp
public class Customer 
{
    private object syncHandle = new object();
    
    private string name; 
    public string Name 
    {
        get 
        {
            lock (syncHandle) 
            return name;
        } 
        set 
        {
            if (string.IsNullOrEmpty(value)) 
                throw new ArgumentException(
            	"Name cannot be blank", 
            	"Name");
            lock (syncHandle) 
            name = value;
        } 
    } 
    // More Elided.
}
```

属性==有所有方法的语言特性。属性可以是 virtual==：

这个例子使用 C# 3.0 的隐式属性语法。创建属性包裹一个备份存储（backing store）是一个常见的模式。一般，你不需要验证逻辑在属性的 getters 或 setters 。 C# 语言支持最简化的==隐式属性== 语法来极大减少需要作为属性来暴露简单域的打字功夫。编译器会创建一个 private 成员域（通常被称作备份存储）并且实现 get 和 set 放弃的逻辑。 

```csharp
public class Customer 
{
    public virtual string Name 	
    {
        get;
        set; 
    }
    
    // 相当于
    private string m_name;
    public string Name{
        get{return m_name;}
        set{m_name = value;}
    }
}
```

可以使用简化的隐式属性拓展属性为 abstract 和定义属性作为接口的一部分。下面的例子演示了在泛型接口（generic interface）定义了属性。可以注意到下面定义的接口没有包含任何实现并且 ==语法和隐式属性是一致的== 。每个实现这个接口的类都要实现这个规范。

```csharp
public interface INameValuePair<T> 
{
    string Name 
    {
        get; 
    }
    T Value 
    {
        get; 
        set;
    } 
}
```

可以指定 get 和 set 访问器不同访问修饰符。这让你可以很好控制通过属性暴露数据成员的可访问性:

```csharp
public class Customer 
{
    public virtual string Name 
    {
        get; 
        protected set;
    } 
// remaining implementation omitted
}
```

属性的语法扩展远超过简单的数据域。如果你的类包含 ==可索引项（indexed items）作为它的接口==，你可以使用索引器（indexers）（参数化属性（parameterized properties））。创建属性实现返回序列（sequence）中的项是非常有用的：

值得注意的是所有索引器必须使用 this 关键字声明。在 C# 中你不能自己命名索引器。所以一个类型的索引器必须有不同的参数列表来避免歧义。几乎==所有的属性的功能都适用索引器。索引器可以是 virtual 或 abstract ；索引器的 setters 和 getters 可以不同的访问限制==。不过，你不能像创建隐式属性一样创建隐式索引器。 

```csharp
public int this[int index] 		// 相当于实现了运算符重载 int operator[](int index){}
{
    get { return theValues[index]; } 
    set { theValues[index] = value; }
}

// Accessing an indexer: 
int val = someObject[i];
```

属性的功能都非常好，是一个非常不错的改进。如果你还蠢蠢欲动使用数据成员的初始实现，然后等到你需要使用到属性的优势的时候，再用属性替换数据成员。这听起来像是一个合理的策略——但这是错误的。考虑下面的类的定义：

```csharp
// using public data members, bad practice: 
public class Customer 
{
    public string Name;
    // remaining implementation omitted 
}
```

类 Customer 有一个数据成员 Name 。你可以使用熟悉的成员记号（member notation） get 或 set 这个 Name ：

```csharp
string name = customerOne.Name; 
customerOne.Name = "This Company, Inc.";
```

这个简单有直观。你会觉得你以后使用属性替换数据成员 Name ，而且代码不做改动能照常工作。好吧，确实是那样的。属性就是访问起来跟数据成员一样。这个语法的目的就在于此。但是==属性不是数据。属性访问和数据访问会产生不同的微软中间语言（Microsoft Intermediate Language）指令==。

尽管属性和数据成员在代码上兼容的。但==在二进制上是不兼容的==。一个很明显的案例，当你把一个 public 数据成员改为等同的 public 属性，意味着你要重新编译所有使用这个 public 数据成员的代码。 C# 把二进制程序集（assemblies）看做“第一类公民”。语言的一个目的就是你可以发布单一更新的程序集，而不要更新整个应用。把数据成员改为属性这么简单的行为却破坏二进制的兼容性。这个行为使得部署更新单一程序集变得更困难。

如果你看了 IL 的属性实现，你可能很想知道属性和数据成员的相对性能。==属性并不比数据成员快，但也不会慢多少==。 JIT 编译器对属性的访问器做了 inline 的优化。如果 JIT 编译器做了 inline 属性访问器优化， 数据成员和属性的性能是一样的。即使没有属性访问器没有置为 inline ，性能差别也只是可以忽略不计的一个函数调用话费。这差别只有在少数情况下才可以被测量出来。

属性是像数据一样被调用的方法。调用者就会有一些访问权限期望。他们==把访问属性当做数据访问==。毕竟，那就是属性。你的属性访问器要能满足这些期望。 Get 访问器不能有其他作用。 Set 访问器改变了状态，调用者要能看到改变。

属性访问器同时满足使用者的性能期望。属性访问跟数据域访问很类似。这不能导致属性和简单数据访问有着显著不同的性能特点。==属性访问不能在长计算，或跨平台调用（比如执行数据库查询），或其他长操作和使用者期望保持一致==。

无论什么时候，你要在类中==暴露数据作为 public或 protected 接口，请使用属性==。对于序列或 dictionaries 是使用索引器。所有数据成员应该无一例外地使用 private 修饰符。你会立即在数据绑定得到支持，而且在以后会很容易方法中的实现。把变量封装在属性里所有的打字功夫加起来就一到两分钟。你会发现在使用属性替换之前的设计会花费数小时。现在花一点时间，以后节约你大量时间。

