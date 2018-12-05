# 用于调试的宏DEBUG

Visual Studio定义 ==`_DEBUG`何时指定`/MTd`或`/MDd`选项==，==`NDEBUG`禁用标准C断言==。在适当的时候使用它们，即`_DEBUG`如果您希望您的调试代码与[MS CRT调试技术](http://msdn.microsoft.com/en-us/library/zh712wwf%28VS.80%29.aspx)一致，并且`NDEBUG`您希望与之保持一致`assert()`。

如果您定义自己的调试宏（并且您没有破解编译器或C运行时），请避免使用下划线开始名称，因为这些是保留的。

使用哪个预处理器定义来指定代码的调试部分？

使用`#ifdef _DEBUG`或者`#ifndef NDEBUG`有没有更好的方法来做到这一点，==例如`#define MY_DEBUG`？== 

> 是NDEBUG标准吗？

是的，它是一个标准宏，具有C89，C99，C ++ 98，C ++ 2003，C ++ 2011，C ++ 2014标准的语义“Not Debug”。`_DEBUG`标准中没有宏。

在`<assert.h>` 中， 并没有定义 NDEBUG 宏， 如果定义了， 那么断言将使用如下简单定义：

```cpp
 #define assert(ignore) ((void)0)
```

如果不同的程序有不同的调试模式，可以很容易和自己的习惯契合：

```cpp
#ifdef THEIRDEBUG
	#define MYDEBUG
#endif //and vice-versa
```

<br>

## 定义自己的调试宏

```cpp
#define DEBUG(x) do { std::cerr << x << std::endl; } while (0)

DEBUG("Foo's address") 
DEBUG(&Foo)		// 使用
```

有人想在 Debug模式下，自动输出日志信息；

在Release模式下， 自动屏蔽掉日志信息：

```cpp
#ifndef _DEBUG // works in VS
	#define DEBUG(x) 
#else
	#define DEBUG(x) do { std::cerr << x << std::endl; } while (0)
#endif
```

控制发行版本：

```cpp
需要设计构建过程以在调试版本中包含类似的内容（例如$(CC) ... -D_DEBUG ...）
```

检测发布和调试的便携版本是：

```cpp
#ifdef NDEBUG
#define DEBUG(x) 
#else
#define DEBUG(x) do { std::cerr << x << std::endl; } while (0)
#endif
```

有人认为日志很重要， 如果是在机器上， 直接console 输出。 如果是在用户端，则希望将日志输出到 log 文件。

代码就像

> ```cpp
> DEBUG("Foo's address") 
> DEBUG(&Foo)
> ```

应该替换为：

```cpp
Log("Foo's address");
Log(std::to_string(&Foo));
```

然后在你的`Log`函数内部，可能有一个签名`void Log(std::string const& message)`，你可以检查你的`DEBUG`宏并采取相应的行动：

```cpp
    void Log(std::string const& message)
    {
#ifdef DEBUG
        // write message to std::cerr
#else
        // write message to log file
#endif
    }
```

当然，`DEBUG`现在**不是标准的宏**（不像`NDEBUG`，它打开`assert`和关闭）。它没有隐含的定义。您必须在调用编译器时自己定义它。例如，`/DDEBUG`使用MSVC或`-DDEBUG`GCC。有可能你的IDE添加了这样一个标志，或类似于`-D_DEBUG`运行编译器的东西，但仍然是，这不是标准的，也不是编译器本身的一部分。（实际上，如果你打算像这样使用它，你可能会考虑使用宏的不同名称`LOG_TO_CONSOLE`。）

无论如何，这只是为了给你一个做什么的灵感。您可能更喜欢`std::ostream`基于a 的方法而不是采用a的函数`std::string`。关于这一点，Stackoverflow上有很多问题和答案。

重要的一点是：在软件发布后您不需要它的假设下，不要丢弃有价值的日志信息。会有错误和模糊的错误描述。



