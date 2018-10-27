# 020 求连续阶乘的乘积末尾0的个数

## 链接和考点

| 栏目              | 详细       |
| ----------------- | ---------- |
| 小红书app编程测试 | 2018.09.15 |
| 考点              | Num        |
| 难度              | Easy       |

<br>

## 题意

输入一个自然数n，求表达式 $f(n) = 1! \times 2! \times 3!  \times … \times n!$ 的结果末尾有几个连续的0？

**输入描述**：

>自然数n

示例

```
11
```

**输出**

```
9
```

<br>

## 分析

1-  先看一个数的阶乘有多少个0， 例如100!, [参考](https://blog.csdn.net/TommyZht/article/details/46309563)，

一般类似的题目都会蕴含某种规律或简便方法的阶乘末尾一个零表示一个进位，则相当于乘以10而10 是由2*5所得，在1~100当中，可以产生10的有：0 2 4 5 6 8 结尾的数字，显然2是确定的，因为4、6、8当中都含有因子2，所以都可看当是2，那么关键在于5的数量了那么该问题的实质是要求出1~100含有多少个5由特殊推广到一般的论证过程可得： 
1、 每隔5个，会产生一个0，比如 5， 10 ，15，20.。。 
2 、每隔 5×5 个会多产生出一个0，比如 25，50，75，100 
3 、每隔 5×5×5 会多出一个0，比如125.

上面的怎么理解呢， $25 = 5 \times 5$, 也就是一个25里面有两个5， 第一步计算了一次， 第二步再计算一次， 所以就是2次。

所以100！末尾有多少个零为：100/5+100/25=20+4=24那么1000！末尾有多少个零呢？同理得： 1000/5+1000/25+1000/125=200+40+8=248 
到此，问题解决了，但我们在学习过程中应当学会发散思维、举一反三。

接着，请问N！的末尾有多少个零呢？ 
其实 也是同理的 
N/5+N/25+…… 
如计算 2009! 的末尾有多少个0:2009/5 = 401 
1~2009之间有 401 个数是 5 的倍数(余数省略).401/5 = 80 
1~2009 之间有 80 个数是 25 的倍数.80/5 = 16 
1~2009 之间有 16 个数是 125 的倍数. 16/5 = 3 
1~2009 之间有 3个数是 625 的倍数. 3/5 = 0 
1~2009 之间有 0 个数是 3125 的倍数. 
所以, 2009！ 的末尾有 401 + 80 + 16 + 3 = 500 个0.

<br>

2- 将第一步写成算法：

```cpp
int CountZero(int N)
{
    int ret =0;
    while(N)
    {
        ret+=N/5;
        N/=5;
    }
    return ret;
}
```

<br>

3- 另一种方法是， 记录数字里5的个数即可， 例如10 = 2 * 5，  有一个5， 25 = 5*5， 有两个5.

由于题目是阶乘的连乘， 只需要计算新增的数里有多少个5， 然后加上前一个数阶乘的基数就行。

<br>

## 测试

A了100%

<br>

## 参考答案

第一种方法：

```java
//#pragma warning(disable:4786)

#include<map>
#include<iostream>
#include <vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<functional>
#include<queue>
#include<set>
#include<string>
#include<unordered_map>
#include<map>
#include<array>
#include<algorithm>
#include<stack>
using namespace std;

using namespace std;

int CountZero(int N)
{
    int ret =0;
    while(N)
    {
        ret+=N/5;
        N/=5;
    }
    return ret;
}

int main(void)
{

    int n;
    cin >> n;

    int res2 = 0;
    for(int i=1; i <= n; i++ ){		// 把所有数的阶乘累加
        res2 += CountZero(i);

    }

    cout << res2 << endl;
    return 0;
}


```

第二种方法：

```cpp
//#pragma warning(disable:4786)

#include<map>
#include<iostream>
#include <vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<functional>
#include<queue>
#include<set>
#include<string>
#include<unordered_map>
#include<map>
#include<array>
#include<algorithm>
#include<stack>
using namespace std;

using namespace std;

int get_5(int num){      // 能进来的肯定是能第一次被5整除的
    int res = 0;
    while( 1 ){
        num = num / 5;
        res++;
        if( num % 5 != 0 )		// 如果下一次不能被5整除直接跳出循环，例如30 = 5 * 6, 下一次跳出。
            break;
    }
    return res;
}

int process_each(int k){
// 去掉注释，就是计算一个数的阶乘后面有多少个0了。
    int num_5 = 0;
//    for( int i= 1; i <= k; i++ ){
        if( k % 5 == 0 )
            num_5 += get_5(k);
//    }
    return num_5;
}

int main(void)
{

    int n;
    cin >> n;

    int res = 0;
    int tmp = 0;
    for(int i=1; i <= n; i++ ){
        tmp += process_each(i);		// 计算新的一轮有多少个5
        res += tmp; //CountZero(i);
    }

    cout << res << endl;
    return 0;
}
```



