# Convert ToDouble 和 Double Parse 的区别

## Convert.ToDouble 和 Double.Parse 的区别

**实际上 Convert.ToDouble内部调用了 Double.Parse：**

(1)对于参数为null的时候：

-  Convert.ToDouble参数为 ==null 时，返回 0.0==；
-  Double.Parse 参数为 null 时，==抛出异常==。

(2)对于参数为""的时候：

-  Convert.ToDouble参数为 "" 时，抛出异常；
-  Double.Parse 参数为 "" 时，抛出异常。

(3)其它区别：

-  Convert.ToDouble可以==转换的类型较多==；
-  Double.Parse ==只能==转换数字类型的字符串。
-  Double.TryParse 与 Double.Parse 又较为类似，但它==不会产生异常==，转换成功返回 true，转换失败返回 false。最后一个参数为输出值，如果==转换失败，输出值为 0.0==。

附测试代码：

```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                //string a = "0.2";
                //string a = null;
                string a = "";
                try
                {
                    double d1 = Double.Parse(a);
                }
                catch (Exception err)
                {
                    Console.WriteLine("d1转换出错:" + err.Message);
                }

                try
                {
                    double d2 = Convert.ToDouble(a);
                }
                catch (Exception err)
                {
                    Console.WriteLine("d2转换出错:" + err.Message);

                }
                
                try
                {
                    double d3;
                    Double.TryParse(a,out d3);
                }
                catch (Exception err)
                {
                    Console.WriteLine("d3转换出错:" + err.Message);
                }
            }
            finally
            {
                Console.ReadKey();
            }

        }
    }
}
```

< br>

## Convert.ToInt32() 与int.Parse() 的区别

没搞清楚Convert.ToInt32和int.Parse()的细细微区别时千万别乱用，否则可能会产生无法预料的结果，举例来说：假如从url中取一个参数page的值，我们知道这个值是一个int，所以即可以用`Convert.ToInt32(Request.QueryString["page”])`，也可以用,`int.Parse(Request.QueryString["page”])`，但是如果page这个参数在url中不存在，那么前者将返回0，0可能是一个有效的值，所以你不知道url中原来根本就没有这个参数而继续进行下一下的处理，这就可能产生意想不到的效果，而用==后一种办法的话没有page这个参数会抛出异常==，我们可以捕获异常然后再做相应的处理，比如==提示用户缺少参数，而不是把参数值当做0来处理==。

**(1)这两个方法的最大不同是它们对null值的处理方法：**

==Convert.ToInt32(null)会返回0==而不会产生任何异常，但==int.Parse(null)则会产生异常==。

**(2)对数据进行四舍五入时候的区别**

`a.Convert.ToInt32(double value)`

如果 value 为两个整数中间的数字，则返回==二者中的偶数==；即 3.5转换为4，4.5 转换为 4，而 5.5 转换为 6。 不过4.6可以转换为5，4.4转换为4

b. int.Parse("4.5")

直接报错:"==输入字符串的格式不正确==".

c. int(4.6) = 4

Int转化其他数值类型为Int时==没有四舍五入，强制转换==

**(3)对被转换类型的区别**

int.Parse 是==转换 String为int==

Convert.ToInt32是==转换继承自Object的对象为int的==(可以有很多其它类型的数据).

你得到一个==object对象,你想把它转换为int,用int.Parse就不可以==,要用Convert.ToInt32.

