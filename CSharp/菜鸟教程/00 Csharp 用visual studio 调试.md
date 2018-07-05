# 00 Csharp 用visual studio 调试

参考： https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/inside-a-program/hello-world-your-first-program

### 创建并运行控制台应用程序

1. 启动 Visual Studio。

2. 在菜单栏上，依次选择“文件” 、“新建” 、“项目” 。

   **“新建项目”** 对话框随即打开。

3. 依次展开“已安装”、“模板”、“Visual C#”，然后选择“控制台应用程序”。

4. 在“名称”框中，指定项目名称，然后选择“确定”按钮。

   新项目将出现在“解决方案资源管理器”中。

5. 如果 Program.cs 未在“代码编辑器”中打开，则在“解决方案资源管理器”中打开“Program.cs”的快捷菜单，然后选择“查看代码”。

6. 将 Program.cs 的内容替换为以下代码。

   C#复制

   ```
   // A Hello World! program in C#.
   using System;
   namespace HelloWorld
   {
       class Hello 
       {
           static void Main() 
           {
               Console.WriteLine("Hello World!");
   
               // Keep the console window open in debug mode.
               Console.WriteLine("Press any key to exit.");
               Console.ReadKey();
           }
       }
   }
   ```

7. 选择 F5 键运行该项目。 将显示包含行 `Hello World!` 的命令提示符窗口

接下来，将检查此程序的重要部分。

## 注释

第一行包含一条注释。 字符 `//` 将该行的其余内容转换为一条注释。

C#复制

```
// A Hello World! program in C#.
```

还可以通过将文本块置于 `/*` 和 `*/` 字符之间，禁止对其的注释。 这在下面的示例中显示。

C#复制

```
/* A "Hello World!" program in C#.
This program displays the string "Hello World!" on the screen. */
```

## Main 方法

C# 控制台应用程序必须包含 `Main` 方法，控件在其中开始和结束。 在 `Main` 方法中，可以创建对象并执行其他方法。

`Main` 方法是驻留在类或结构中的[静态](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/keywords/static)方法。 在上一个“Hello World!” 示例中，该方法驻留在名为 `Hello` 的类中。 可以通过以下方式之一来声明 `Main` 方法：

- 它可返回 `void`。

  C#复制

  ```
  static void Main()
  {
      //...
  }
  ```

- 还可以返回一个整数。

  C#复制

  ```
  static int Main()
  {
      //...
      return 0;
  }
  ```

- 无论使用哪种返回类型，它都可以带有参数。

  C#复制

  ```
  static void Main(string[] args)
  {
      //...
  }
  ```

  或

  C#复制

  ```
  static int Main(string[] args)
  {
      //...
      return 0;
  }
  ```

`Main` 方法中定义的参数 `args` 是一个 `string` 类型的数组，该数组包含用于调用该程序的命令行自变量。 与 C++ 不同的是该数组不包括可执行 (exe) 文件的名称。

若要深入了解如何使用命令行参数，请参阅 [Main() 和命令行参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/main-and-command-args/index)与[如何：使用命令行创建和使用程序集](http://msdn.microsoft.com/library/70f65026-3687-4e9c-ab79-c18b97dd8be4)中的示例。

在调试模式下运行程序时，对 `Main` 方法末尾处 [ReadKey](https://docs.microsoft.com/zh-cn/dotnet/api/system.console.readkey) 的调用可以防止在有可能读取输出内容之前控制台窗口关闭，具体方法是按 F5 键。

## 输入和输出

C# 程序通常使用由 .NET Framework 的运行时库提供的输入/输出服务。 语句 `System.Console.WriteLine("Hello World!");` 使用 [WriteLine](https://docs.microsoft.com/zh-cn/dotnet/api/system.console.writeline) 方法。 这是运行时库中 [Console](https://docs.microsoft.com/zh-cn/dotnet/api/system.console) 类的输出方法之一。 该方法将在标准输出流中显示其字符串参数，后接新行。 其他 [Console](https://docs.microsoft.com/zh-cn/dotnet/api/system.console) 方法可用于不同的输入和输出操作。如果程序开头包含 `using System;` 指令，则可以直接使用 [System](https://docs.microsoft.com/zh-cn/dotnet/api/system) 类和方法，而不必进行完全限定。 例如，可以调用 `Console.WriteLine`，而非 `System.Console.WriteLine`：

C#复制

```
using System;
```

C#复制

```
Console.WriteLine("Hello World!");
```

有关输入/输出方法的详细信息，请参阅 [System.IO](https://docs.microsoft.com/zh-cn/dotnet/api/system.io)。

## 命令行编译和执行

通过使用命令行 而非 Visual Studio 集成开发环境 (IDE)，可以编译“Hello World!”程序。

#### 从命令提示符中编译并运行

1. 将上一过程的代码粘贴到任何文本编辑器中，然后将该文件保存为文本文件。 为 `Hello.cs` 文件命名。 C# 源代码文件使用 `.cs` 扩展。

2. 执行以下任一步骤以打开命令提示符窗口：

   - 在 Windows 10 的“开始”菜单上，搜索 `Developer Command Prompt`，然后点击或选择“VS 2017 开发人员命令提示”。

     将出现“开发人员命令提示”窗口。

   - 在 Windows 7 中，打开“启动”菜单，展开当前版本的 Visual Studio 的文件夹，打开“Visual Studio Tools”快捷菜单，然后选择“VS 2017 开发人员命令提示”。

     将出现“开发人员命令提示”窗口。

   - 从标准命令提示符窗口启用命令行生成。

     请参阅[如何：为 Visual Studio 命令行设置环境变量](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/how-to-set-environment-variables-for-the-visual-studio-command-line)。

3. 在命令提示窗口中，导航到包含 `Hello.cs` 文件的文件夹。

4. 输入以下命令以编译 `Hello.cs`。

   `csc Hello.cs`

   如果程序不存在编译错误，系统将创建名为 `Hello.exe` 的可执行文件。

5. 在命令提示窗口中，输入以下命令以运行该程序：

   `Hello`

有关 C# 编译器及其选项的详细信息，请参阅 [C# 编译器选项](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/compiler-options/index)。

## 请参阅

[C# 编程指南](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/index)
[在 C# 程序内部](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/inside-a-program/index)
[字符串](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/strings/index)
[C# 示例应用程序](http://msdn.microsoft.com/library/9a9d7aaa-51d3-4224-b564-95409b0f3e15)
[C# 参考](https://docs.microsoft.com/zh-cn/dotnet/csharp/language-reference/index)
[Main() 和命令行参数](https://docs.microsoft.com/zh-cn/dotnet/csharp/programming-guide/main-and-command-args/index)
[Visual C# 和 Visual Basic 入门](https://docs.microsoft.com/zh-cn/visualstudio/ide/getting-started-with-visual-csharp-and-visual-basic)