# 20180713 substring 的用法

## 函数原型

```cpp
 String.SubString(int index,int length)   
```

说明：

- index:开始位置，从0开始        
- length:你要取的子字符串的长度     

```csharp
using System;
using System.Collections.Generic;
using System.Text;

namespace str_sub
{
    class Program
    {
        static void Main(string[] args)
        {
            string myString = "Hello Word!";

            //Substring()在C#中有两个重载函数
            //分别如下示例 >>>

            string subString1 = myString.Substring(0);
            //如果传入参数为一个长整, 且大于等于0,
            //则以这个长整的位置为起始,
            //截取之后余下所有作为字串.
            //如若传入值小于0,
            //系统会抛出ArgumentOutOfRange异常
            //表明参数范围出界



            string subString2 = myString.Substring(0, 5);
            //如果传入了两个长整参数,
            //前一个为参数子串在原串的起始位置
            //后一个参数为子串的长度
            //如不合条件同样出现上述异常


            Console.WriteLine(subString1);
            Console.WriteLine(subString2);
            Console.ReadLine();
        }
    }
}
/*
Hello Word!
Hello
*/
```

