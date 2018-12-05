# 05 总是提供ToString 方法

在 .NET 环境中 `System.Object.ToString() `是最常使用方法之一。你应该为客户端代码的 ==所有类写一个合理的版本==。否则，你要强迫每个使用你代码的使用者使用你创建可读的说明的属性。字符串说明很容易被用来向使用者说明对象的信息：在 WPF （Windows Presentation Foundation）框架中， Silverlight 框架中， Web Forms 或控制台输出。

==字符串说明也能被用来调试==。你创建的每个类型都应该重写（override）这个方法。当你创建更复杂的类型，你应该实现更复杂的 `IFormattable.ToString()` 。必须承认：如果你没有重写这个方法，或者写了得很糟糕，你的客户会强制为你修复这个问题。

System.Object 的版本会 **返回类型的全限定名字**。这个信息很少有用：“ System.Drawing.Rect ”，“ MyNamespace.Point ”，“SomeSample.Size ” 不是我们要向客户展示的信息。这就是你没有重写 ToString() 获得的信息。你一个类只写一次，但是你的客户使用很多次。当你的写类多付出一点工作，会从你使用者那里得到回报的。

我们考虑最简单的需求：重写 ` System.Object.ToString()` 。你创建的类你需要重写 ToString 为了提供最常用的文本说明。下面的自定义的类，提供三个 public 属性：

```csharp
 public class Customer 
{
    public string Name 
    {
        get; 
        set;
    } 
    public decimal Revenue 
    {
        get; 
        set;
    } 
    public string ContactPhone 
    {
        get; 
        set;
    }
     
    public override string ToString() 
    {
        return Name; 
    }
}
```

继承的 Object.ToString() 版本会发挥 “ Custormer ”。这个信息对任何都没有作用。即使你使用 ToString() 只是为了调试，它应该比那更复杂些。

你应该重写 ToString() 方法，使之 ==返回最有可能是这个类的文本说明==。在 Customer 的例子里，就是 name：

```csharp
public override string ToString()
{
    retrun Name;
}
```

如果你不遵从这个原则的其他建议，按照上面的方法为你的类重写该方法。这会直接节省每个人的时间。当你提供了 Object.ToString() 方法的合理的实现，这个类的对象很容易添加到 WPF 控件， Siverlight 控件， Web Form 控件，或打印输出。 .NET BCL 使用在每个控件中使用重写的 Object.ToString() 来说明对象： combo boxes ， list boxes ， text boxes ， 以及其他控件。

在 WPF 或 Web Form 中，如果你创建 Customer 的对象列表，你可以通过 System.Console.WriteLine() 来输出System.String.Format() 或 ToString() 的 name 文本。

任何时候 .NET BCL 想要获取一个 Customer 的字符串说明，你的 Customer 类型要提供属性 Name 。上面简单的三行代码处理所有基本的需求。

C# 3.0 编译 ==为匿名类提供了默认的 ToString()== 。默认生成的 ToString() 会输出每个元素的属性值。属性的说明的序列是 LINQ 查询结果，会显示他们的类型信息而不是他们的值。看下面这段代码：

```csharp
 int[] list = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
var test = new { Name = "Me",
    Numbers = from l in list select l }; 
Console.WriteLine(test);
```

将会显示：

```
{ Name = Me, Numbers = System.Linq.Enumerable+WhereSelectArrayIterator`2 [System.Int32,System.Int32] }
```

甚至，编译器为匿名类产生的输出会比你自定义的类型更好，除非你重写了 ToString() 方法。你应该为使用者提供比编译器在方法作用域中为暂时类型做的更好支持。

之前定义的 Customer 类型有三个属性： Name ， Revenue 和 Phone。 重写的 System.ToString() 只使用了 Name 。你可以通过实现 IFormattalbe 接口来解决这个缺陷。 ==IFormattable 包含了一个重载的 ToString() 方法让你指定类的格式化输出信息==。当你需要创建不同格式的字符串输出是，你就需要这个接口。定义的类型是这个接口的对象。使用可以创建一个报表，以表格形式输出包含 Customer 的 Name 和去年的收入 Revenue 。IFormattalbe.ToString 就是提供这个作用，让你能 ==格式化类的输出字符串==。 IFormattable.ToString() 方法声明（signature）包含了一个要格式化的字符串和格式化提供器：

```csharp
string System.IFormattable.ToString(string format, IFormatProvider formatProvider)
```

你可以使用格式化字符串来指定类型自己的格式。你可以指定格式化字符的关键字符。在这个 Customer 的例子里，你可以指定 n 表示 Name ， r 表示 Revenue ， p 表示 Phone 。同时还可以向下面 IFormattable.ToString() 版本一样，指定组合关键字符：

```csharp
// supported formats: 
// substitute n for name. 
// substitute r for revenue 
// substitute p for contact phone. 
// Combos are supported: nr, np, npr, etc 
// "G" is general. 
string System.IFormattable.ToString(string format, IFormatProvider formatProvider) 
{
    if (formatProvider != null) 
    {
        ICustomFormatter fmt = formatProvider.GetFormat( this.GetType() ) as ICustomFormatter;
        if (fmt != null) 
        	return fmt.Format(format, this, formatProvider);
    }
    
    switch (format) 
    {
        case "r": 
        	return Revenue.ToString();
        case "p": 
        	return ContactPhone;
        case "nr": 
        	return string.Format("{0,20}, {1,10:C}", Name, Revenue); 
        case "np":
        	return string.Format("{0,20}, {1,15}", Name, ContactPhone); 
        case "pr":
        	return string.Format("{0,15}, {1,10:C}", ContactPhone, Revenue); 
        case "pn":
        	return string.Format("{0,15}, {1,20}", ContactPhone, Name); 
        case "rn":
        	return string.Format("{0,10:C}, {1,20}", Revenue, Name); 
        case "rp":
        	return string.Format("{0,10:C}, {1,20}", Revenue, ContactPhone); 
        case "nrp":
        	return string.Format("{0,20}, {1,10:C}, {2,15}", Name, Revenue, ContactPhone); 
        case "npr":
        	return string.Format("{0,20}, {1,15}, {2,10:C}", Name, ContactPhone, Revenue); 
        case "pnr":
        	return string.Format("{0,15}, {1,20}, {2,10:C}", ContactPhone, Name, Revenue); 
        case "prn":
        	return string.Format("{0,15}, {1,10:C}, {2,15}", ContactPhone, Revenue, Name); 
        case "rpn":
        	return string.Format("{0,10:C}, {1,15}, {2,20}", Revenue, ContactPhone, Name); 
        case "rnp":
        	return string.Format("{0,10:C}, {1,20}, {2,15}", Revenue, Name, ContactPhone);
        case "n": 
        case "G": 
        default:
        	return Name; 
    }
}
```

添加下面函数，让你客户代码能够指定 Customer 数据的显示：

```csharp
IFormattable c1 = new Customer(); 
Console.WriteLine("Customer record: {0}",c1.ToString("nrp", null));
```

针对不同的类，IFomrattable.ToString() 的实现特定的，但当你实现 IFormattable 接口，你必须实现某些情况。-

- 首先，你必须支持一般格式 “G”。

- 第二，你要支持空格式："" 和 null 。你重写的 Ojbect.ToString() 方法必须返回为这三个格式返回相同的字符串。 .NET 记录类库（BCL）为每个实现了 IFormattable 的类调用 IFormattable.ToString() 而不是 Object.ToString() 。
- .NET BCL 经常使用格式字符串 null 来调用 IFormattable.ToString() ，但很少使用格式字符 G 来格式化字符串。

如果添加了 IFormattable 接口去没有支持这个三个标准格式，你会打破 BCL 的字符串自动转换的规范。你会发现这个的 IFormattable 很快会失控。你不可能预料到你的类型需要支持所有可能的格式。大多时候，选择少数常见的格式。客户端代码应该弥补所有边界情况。

<br>

IFormattable.ToString() 的第二个参数需要是实现 IFormatProvider 接口的对象。这个对象可以提供你没有预料的到格式的支持。如果你浏览了前面 IFormattable.ToString() 的实现，毫无疑问你会发现数字格式的选项是没有提供的。提供数字的输出是理所当然的。无论你支持了多少种格式字符，使用者总有一天会发现一些格式是没有预料到的。那就是为什么方法中头几行去查看实现 IFormatProvider 的对象并委托操作给它定义的 ICustomFormatter 。

把角色从类的定义转移到类的使用者上去。你会发现你需要的格式没有被支持。举个例子，你的 Customer 的 Name的字符长度大于20，你需要修改格式为 Customer Name提供50个字长度的格式输出。

那就是为什么IFormatProvider 接口的产生。你创建的类可以通过实现 IFormatProvider 和一个实现 ICustomerProvider 的组合类来实现自定义的格式输出。 IFormatProvider 接口定义了一个方法： GetFormat() 。 GetFormat() 方法返回了实现了 ICustomFormatter 接口的对象。ICustomFormatter 接口指定了实际的输出格式的方法。下面两个类的创建，修改使用50列来输出 Customer Name 的输出：

```csharp
// Example IFormatProvider: 
public class CustomFormatter : IFormatProvider 
{
#region IFormatProvider Members 
// IFormatProvider contains one method. 
// This method returns an object that 
// formats using the requested interface. 
// Typically, only the ICustomFormatter 
// is implemented 
public object GetFormat(Type formatType) 
{
if (formatType == typeof(ICustomFormatte))
return new CustomerFormatProvider();
return null; 
} 
#endregion
// Nested class to provide the 
// custom formatting for the Customer class. 
private class CustomerFormatProvider :ICustomFormatter 
{
#region ICustomFormatter Members 
public string Format(string format, object arg, IFormatProvider formatProvider) 
{
Customer c = arg as Customer; 
if (c == null)
return arg.ToString(); 
return string.Format("{0,50}, {1,15}, {2,10:C}",c.Name, c.ContactPhone, c.Revenue); 
}
#endregion
}
}
```

GetForm 方法返回创建实现 ICustomFormatter 接口的对象。在所请求的方式中，ICustomFormatter.Format() 做的实际格式输出工作。你可以使用 ICustomFormatter.Format() 定义格式字符串，满足在一个历程中指定多个格式的需求。 格式提供器是从 GetFormat 方法返回的 ICustomFormatter 。

为了指定你定义的格式，你需要显示调用参数为 IFormatProvider 对象的 string.Format()：

```
Console.WriteLine(string.Format(new CustomFormatter(), "", c1));
```

现在把角色切回到类的定义者。重写 Object.ToString() 是一个非常简单的提供类的字符串说明的方式。当你定义一个类的时候，都应该重写这个方法。它是最明显和常用的类的说明。它不会太冗余。它会出现在控件，HTML 页，或其他人可读的地方。当罕见的类需要更复杂的输出信息的时候，你就可以充分利用 IFormattable 接口的实现。这可以提供标准方式去定义类的文本输出。如果你对此置若罔闻，你就需要自己实现的格式（formatter）。 这个解决方案需要更多的代码，因为使用者不会检查对象的内部状态。同样，实现这不可能预料所有潜在的格式。

最后，使用者会猜测你的类型的信息。会理解文本输出，所以你需要尽可能提供最简单的信息：所有的类都重写 ToString() 。使得 ToString() 输出的简短而合理。