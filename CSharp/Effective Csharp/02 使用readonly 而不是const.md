# 02 使用readonly 而不是const

1- readonly: 运行时常量；

const: 编译时常量；

如下：

```csharp
// Compile time constant:
public const int Millennium = 2000;
// Runtime constant:
public static readonly int ThisYear = 2004;
```

上面的代码可以出现类或结构体的作用域（scope）中。==编译时常量还可以在方法体中声明==。运行时常量不能在方法体重声明。

编译时常量和运行时常量访问方式不同导致不同的行为。在目标代码中编译时常量会 ==被替换成常量值==。比如下面代码：

```csharp
// Compile time constant:
public const int Millennium = 2000;
// Runtime constant:
public static readonly int ThisYear = 2004;
```

会和下面写法的编译的 IL 代码是一样的：

```csharp
if (myDateTime.Year == 2000)
```

运行时常量的值是在运行时得到的。当你引用一个只读（read-only）常量， IL 会引用一个 ==readonly 变量==而不是直接使用值。

使用编译时常量和运行时常量还有不同的限制。编译时常量 ==只能在基本类型（内建整数和浮点数类型），枚举类型，或字符串==。编译时常量要求类能用有意义的常量赋值初始化。而只有基本类型才能在 IL 代码中使用常量（literal values）来替换。==不能使用使用 new 操作法初始化编译时常量==，即使它是一个值类型：

```csharp
// Does not compile, use readonly instead:
private const DateTime classCreation = new
    DateTime(2000, 1, 1, 0, 0, 0);
```

编译时常量==只能使用与数字和字符串==。

==只读（Read-only）变量也是常量，即不能在构造函数完成之后再修改==。但只读变量是在运行时赋值。这会比编译时常量更灵活。首先，==运行时常量可以是任何类型。你必须在构造函数或者直接初始化==。你可以让 DateTime 结构体变为 readonly 值；但不能使用 const 创建 DateTime 值。

readonly 值可以是实例类型（instance）常量，让一个类的实例存储不同值。而编译时常量则是被定义为 static 常量的。

只读变量最重要的不同在于运行时才确定值。当==你引用一个只读变量， IL 会为你产生一个指向只读变量的引用，而不是值==。这种差异将对维护上产生深远的影响。编译时常量产生的 IL 代码就跟直接使用数值变量时一样的，即使是跨程序集：一个程序集的常量在另一个程序集还是被替换为数值。

编译时常量和运行时常量的赋值方式会==影响运行时的兼容性==。假设你在程序集 Infrastructure 中同时定义了 const 和 readonly 域：

```csharp
public class UsefulValues 
{
    public static readonly int StartValue = 5; 
    public const int EndValue = 10;
}
```

在另外一个程序集，你引用这两个值：

```csharp
for (int i = UsefulValues.StartValue; 
    i < UsefulValues.EndValue; i++) 
    Console.WriteLine("value is {0}", i);
```

如果你运行这个简单的测试程序，很明显你会得到下面的输出：

```
Value is 5
Value is 6
...
Value is 9
```

一段时间后，你发布新版本的 Infrastructure 程序集并作下面的改动：

```csharp
public class UsefulValues 
{
    public static readonly int StartValue = 105; 
    public const int EndValue = 120;
}
```

你只发布程序集 Infrastructure 而 ==没有重新编译全部应用程序==。你希望得到下面的结果：

```
Value is 105
Value is 106
...
Value is 119
```

实际上，你不会得到任何输出。循环条件开始于105，结束于10。 C# 编译器  ==用10替换应用程序集的 const 变量而不是指向存储 EndValue 的引用==。 

StartValue 的情况趋势截然不同。因为它被声明为 readonly ：在运行时确定值。因此，应用程序集能不用重新编译就能充分利用新值；只要很简单地按照更新版本的 Infrastructure 程序集就可以改变使用该变量的值。更新 public const 变量的值应该当做接口的变化。更新只读常量的值只是实现的改变，兼容客户端的二进制代码。

另一方法，有时候某些值==的确需要是编译时常量==。例如：考虑使用 ==编译时常量标记对象的序列化版本==（查看原则27）。标记特定版本号的持久化值要使用编译时常量，它们决不会发生改变。但 ==当前的版本号应该是一个运行时常量==，随着版本不同而改变。

```csharp
private const int Version1_0 = 0x0100; 
private const int Version1_1 = 0x0101; 
private const int Version1_2 = 0x0102; 
// major release: 
private const int Version2_0 = 0x0200;
// check for the current version: 
private static readonly int CurrentVersion =
    Version2_0;
```

你会使用 ==运行时常量存储每个文件的当前版本号==：

```csharp
// Read from persistent storage, check 
// stored version against compile-time constant: 
protected MyType(SerializationInfo info,
    StreamingContext cntxt) 
{
    int storedVersion = info.GetInt32("VERSION"); 
    switch (storedVersion) 
    {
        case Version2_0: 
            readVersion2(info, cntxt); 
            break;
        case Version1_1: 
            readVersion1Dot1(info, cntxt); 
            break;
        // etc. 
    }
}
```

```csharp
// Write the current version: 
[SecurityPermissionAttribute(SecurityAction.Demand, SerializationFormatter = true)] 
void ISerializable.GetObjectData(SerializationInfo inf,
    StreamingContext cxt) 
{
    // use runtime constant for current version: 
    inf.AddValue("VERSION", CurrentVersion);
    // write remaining elements... 
}
```

相比 readonly ，使用 const 最后的一个优势就是性能：已知的常量值会比使用变量访问的 readonly 变量产生稍微高效的代码。然而，性能上甚微的收效和灵活性的减小应该做一个很好的权衡。放弃灵活性之前一定要剖析性能差异。可选参数的默认值会在调用时会像编译时变量（声明为 const 的变量）一样被替换成默认值。和使用 readonly 和 const 变量一样，你要非常认真对待可选参数值的不同。（查看原则10。）

当你使用命名（named）参数和可选（optial）参数时，你会遇到和使用运行时常量和编译时常量一样的权衡。

当在编译时期必须要获得变量的值时必须使用 const ：==特性（attribute）参数和枚举==定义，以及当你定义一个不随版本的变化而变化的值得罕见的时候。无论如何，更偏爱于只读常量的更强的灵活性。