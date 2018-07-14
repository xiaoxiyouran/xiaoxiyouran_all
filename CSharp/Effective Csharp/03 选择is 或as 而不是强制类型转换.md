# 03 选择is 或as 而不是强制类型转换

当你使用 C# ，你就应该知道它是强类型语言。大多时候，这总是一个好事。==强类型意味着编译器==可以发现你的代码中的类型是否匹配。也可以减少运行时的类型检查。但是有些时候，类型检查是不可避免的。很多时候，函数的调用参数是 object ，因为在框架中定义好了函数原型。你很有可能要进行强制类型转换（cast）为其他类型的类或接口。你可以用两种选择：使用 as 操作符或者强制类型转换。在转换之前，你需要进行变量类型防护：使用 ==is 进行类型判断，然后再用 as 进行转换或者强制类型转换==。

==无论什么时候都应该选择 as 操作符==，因为它比盲目的强制类型转换更安全且运行时更高效。 as 和 is 不会执行任何用户自定义的转换。只有当目标类型和运行时类型匹配时才会成功转换；它不会构造一个新对象去满足需求。

看一个例子。你需要些一段代码将任意类型的对象转换为 MyType 的实例。你可能会这样写：

```csharp
object o = Factory.GetObject();
// Version one:
MyType t = o as MyType;
if (t != null) 
{
	// work with t, it's a MyType. 
} 
else 
{
	// report the failure. 
}
```

或者，你会这样写：

```csharp
object o = Factory.GetObject();
// Version two: 
try 
{
    MyType t; 
    t = (MyType)o; 
    // work with T, it's a MyType.
} 
catch (InvalidCastException) 
{
	// report the conversion failure. 
}
```

你会觉得第一个版本的写法简单而可读性强。它没有 try/catch 代码块，所以可以同时避免性能开销和代码量。注意到 ==强制类型转换除了要捕捉异常之外还要坚持是否为 null== 。null 类型可以强制转换为任意引用类型，但 as 操作符会返回 null 。所以强制类型转换要检查 null 和捕捉异常。而==使用 as ，你只要很简单检查返回引用是否为 null== 。

强制类型转换和 as 操作符转换最大的区别在于 ==如何看待用户自定义的类型转换==。 as 和 is 操作符在运行时要转换对象的类型，不会进行额外的操作。如果一个类型不是转换要求的类型或者是其子类的话，转换就会失败。然而，强制类型转换可以使用转换操作符转换一个对象到需要的类型。这就包括了内建数据类型的转换。强制转换一个 long 整数到 short 整数会丢失信息。

同样的问题也会在你自定义的类型中出现。考虑下面的类型：

```csharp
public class SecondType 
{
    private MyType _value;
    // other details elided 
    // Conversion operator. 
    // This converts a SecondType to 
    // a MyType, see item 9\. 
    public static implicit operator MyType(SecondType t) 	// SecondType 是当前类型，MyType 是返回类型
    {
         return t._value; 
    }
}
```

假设， Factory.GetObject() 会返回上一段代码的 SecondType 的对象：

```csharp
object o = Factory.GetObject();
// o is a SecondType:
MyType t = o as MyType; // Fails. o is not MyType
if (t != null) 
{
	// work with t, it's a MyType. 
} 
else 
{
	// report the failure. 
}

// Version two: 
try 
{
    MyType t1; 
    t1 = (MyType)o; // Fails. o is not MyType 
    // work with t1, it's a MyType.
} 
catch (InvalidCastException) 
{
	// report the conversion failure. 
}
```

两种版本的代码都会失败。但是强制类型转换执行的是用户自定义的转换。你应该会觉得会成功的。你是对的——是会成功的，如果按你想的方式。但是还是失败了——因为编译器产生的代码是基于编译时的对象类型， o 。编译器对运行时 o 的类型一无所知； o 只是 object 的对象。编译器没有找到用户定义的从 object 转换为 MyType 的方法。它只是检查了 object 和 MyType 的类型定义。编译器没有发现用户定义的类型转换，会产生在运行时检查 o 的类型是否是 MyType 的代码。因为 o 是 SecondType 对象，所以会失败。编译器不会检查 o 的实际运行时类型是否可以转换为 MyType 对象。

下面代码块==可以==成功将 SecondType 转换为 MyType ：

```csharp
object o = Factory.GetObject();
// Version three:
SecondType st = o as SecondType; 
try 
{
    MyType t; 
    t = (MyType)st; 
    // work with T, it's a MyType.
} 
catch (InvalidCastException) 
{
	// report the failure. 
}
```

你应该杜绝写这么糟糕的代码，但这确实解决一个常见的问题。虽然不应该这样写代码，但可以用 object 参数来实现正确的转换：

```csharp
object o = Factory.GetObject(); 
DoStuffWithObject(o);

private static void DoStuffWithObject(object o) 
{
    try 
    {
        MyType t; 
        t = (MyType)o; // Fails. o is not MyType 
        // work with T, it's a MyType.
    } 
    catch (InvalidCastException) 
    {
    	// report the conversion failure. 
    }
}
```

只需记住 ==用户自定义的类型转换只针对编译时期的类型，而不会对运行时类型起作用==。这不会影响 o 运行时类型和 MyType 转换的存在。编译器并不会知道和在意。下面语句会有不同的行为根据 st 不同的声明类型：

```csharp
t = (MyTpe)st
```

下面语句无论 st 声明是什么类型得到的结果都是一样的。所以，应该更偏向使用 as 而不是强制类型转换——它得到的结果更一致。实际上，这次类型没有继承关系，而且用户自定义转换存在，下面的语句会产生一个编译错误：

```csharp
t = st as MyType;
```

既然你知道使用尽可能使用 as ，下面我们讨论什么时候是不能使用的。 as 操作符是 ==不能再值类型上使用的==。这条语句不能通过编译：

```csharp
object o = Factory.GetValue(); 
int i = o as int; // Does not compile.
```

这是因为 ==int 是值类型，不能赋为 null== 。那如果 o 不是整数 int 变量 i 会取什么值。无论取什么值都是无效的整数。因此， as 不能使用，==只有使用强制类型转换语法。这实际是一个装箱（boxing）或拆箱（unboxing）的转换（查看原则45）==。

```csharp
object o = Factory.GetValue(); 
int i = 0; 
try 
{
	i = (int)o; 
} 
catch (InvalidCastException) 
{
	i = 0; 
}
```

流控制机制的异常是一个非常糟糕的做法。但你又不得不使用强制类型转换的行为。你可以  ==使用 is 语句去掉可能引起的异常或转换==：

```csharp
object o = Factory.GetValue(); 
int i = 0; 
if (o is int)
	i = (int)o;
```

如果 o 不是可以转换为 int 的其他类型，比如 double ，上面的 is 操作会返回 false。参数为 null ， is 总是返回 false 。

==is 操作符只应该用于无法使用 as 来转换的情况。否则只是多余==：

```csharp
// correct, but redundant: 
object o = Factory.GetObject();
MyType t = null; 
if (o is MyType)
	t = o as MyType;
```

上面的代码和下面写的代码是一样的：

```csharp
// correct, but redundant: 
object o = Factory.GetObject();

MyType t = null; 
if ((o as MyType)) != null)
	t = o as MyType;
```

这是低效并且多余的。如果你打算用  ==as 转换类型， is 类型检查简单但却没有必要的==。检查 as 的返回值是否为 null ，更简单。

既然掌握了 is ， as 和强制类型转换的区别了，那么哪个操作应该在 foreach 循环中使用？

foreach 循环可以操作==非泛型 IEnumerable 序列和内建强制类型转换为迭代器==（iteration）。（你应该尽可能使用类型安全泛型版本。非泛型版本的存在处于历史目的和支持晚绑定情况）。

```csharp
public void UseCollection(IEnumerable theCollection) 
{
    foreach (MyType t in theCollection)
    t.DoStuff( ); 
}
```

foreach 使用强制类型转换操作转换对象到循环体中使用的类型。 foreach 语句几乎等同于下面手动实现的版本：

```csharp
public void UseCollectionV2(IEnumerable theCollection) 
{
    IEnumerator it = theCollection.GetEnumerator(); 
    while (it.MoveNext()) 
    {
        MyType t = (MyType)it.Current;
        t.DoStuff(); 
    }
}
```

foreach 的强制类型转换需要同时支持 值类型和引用类型。因为使用强制类型转换，foreach 语句呈现的一样的行为，无论目标类型是什么。因为使用了强制类型转换， foreach 循环会引起并抛出 InValidCastException 异常。

你为 IEnumerator.Current 返回的是 System.Object 类型，没有任何转换操作，上面的测试是不合格的。 SecondType 的对象集合不能使用在上面的 UseCollection 函数，因为依你所见强制类型转换会失败。 foreach 语句（使用强制类型转换）不会检查集合中强制类型转换的对象的运行时类型。只是检查 System.Object 类（ IEnumerator.Current 返回的类型）和声明的循环变量类型（在上面例子中的 MyType ）转换是否可行。

最后，有时你想知道对象的具体类型，而不只是当前类型能不能转换为目的类型。 is 操作符使用在==任何继承==自目标类型的对象都会返回 ture 。GetType() 方法可以获得对象的==运行时类型==。它提供了比 is 和 as 更严格的类型测试。 GetType() 返回一个对象的类可以拿来和指定的类型比较。

再次考虑这个函数：

```csharp
public void UseCollectionV3(IEnumerable theCollection) 
{
    foreach (MyType t in theCollection)
    t.DoStuff(); 
}
```

如果你创建一个继承 MyType 的类 NewType ， NewType 的集合可以在 UnseConllection 函数上正确工作：

```csharp
public class NewType : MyType 
{
	// contents elided. 
}
```

如果你想要写一个函数使得所有 MyType 对象都能工作，上面的方法已经可以了。如果你想要这个方法只对 MyType 对象正常工作，你应该使用精确类型比较。这里你可以在 foreach 循环中实现。很多时候，精确的运行时类型对于相等测试是非常重要的（查看原则6）。很多其他比较， as 和 is 提供的 .isinst 指令在语意上是正确的。

.NET 继承类库（BCL）包含一个使用  ==相同类型操作转换序列中元素的方法： `Enumerble.Cast<T>() `转换支持实现 IEnumerale 接口的类的序列的每个元素==。

```csharp
IEnumerable collection = new List<int>() 
{1,2,3,4,5,6,7,8,9,10};

var small = from int item in collection 
where item < 5 
select item;

var small2 = collection.Cast<int>().Where(item => item < 5). 
Select(n => n);
```

上面代码的最后一行的查询产生相同方法调用。这两个例子， ==`Cast<T> ` 方法都是转换序列中每个元素到目标类型==。 `Enumerable.Cast<T>` 方法使用的是旧的强制类型转换而不是 as 操作符。旧的强制类型转换说明 `Cast<T> `不需要包含类型约束。使用 as 操作符会会有限制，为了不用实现不同的 `Cast<T>` 方法， BCL 团队选择使用了旧的强制类型转换操作来只产生一个方法。

这时你在写代码是需要权衡的。当你需要==转换一个泛型参数的对象时，你需要权衡类型约束必要性和强制类型转换的不同行为==。

在 C# 4.0，类型系统可以通过使用动态类型或运行时检查来规避。这也是第5章的目的，“ C# 动态编程”。有很多方法可以预期知道对象的行为而不需要知道对象实现的类或接口。你将要学习什么时候该使用这些技术什么时候该避免。

好的面向对象实践告诉我们应该避免使用类型转换，但是有时候却别无选择。如果你不能避免使用类型转换，使用语言提供的 as 和 is 操作符来清晰地表达你的用意。不同方式的强制类型转换有不同的规则。 is 和 as 操作符几乎总是正确的语义，只有当测试的对象是正确的类型才会成功。选择这些语句来转换类型而不是强制类型转换，因为能返回你期望的成功或失败，而不会有异常产生。