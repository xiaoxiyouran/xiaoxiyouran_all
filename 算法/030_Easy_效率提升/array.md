# 030 效率提升

## 链接和考点

| 栏目             | 详细       |
| ---------------- | ---------- |
| 美团机器学习笔试 | 2018.10.22 |
| 考点             | Array      |
| 难度             | Easy       |

<br>

## 题意

**时间限制：**C/C++语言 1000MS；其他语言 3000MS
**内存限制：**C/C++语言 65536KB；其他语言 589824KB

**题目描述：**

环正建筑公司承包了Z市的一条道路的翻新工作。新来的小张实习生将整个工程分为了n道工序，按顺序进行每一步工序，每一步工序都是将某一段区间 [Li, Ri] 的路段进行整修。作为经理的你发现了小张的安排存在问题，许多工序是不必要的。但是因为人员分配已经安排下去了，考虑到多方面的因素，当工序x在工序y之前执行且工序y的区间完全包含了工序x的区间（x<y且Ly≤Lx<Rx≤Ry），那么你可以撤销工序x。请问你最多能撤销掉多少步工序。

**输入**

第一行一个数n，表示工序的数量。（1≤n≤100000）

接下来n行，每行两个数Li，Ri，表示工序的负责区间 [Li, Ri]。（1≤Li≤Ri≤100000）

**输出**

一个数，最多能撤销掉的工序数。

<br>

**样例输入**

```
5
1 5
2 4
2 3
1 4
2 5
```

样例输出

```
2
```

Hint

```
工序2、3被工序4包含，可以撤销。
```

<br>

## 分析

1-  从后往前，依次找比它范围小的， 满足条件撤销的，标记一下，后面就不用处理了；

像冒泡排序，时间复杂度 O(n^2);

<br>

## 测试

A了100%

<br>

## 参考答案

C++ 程序：

```cpp
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
#include <numeric>
using namespace std;


//主函数
int main()
{
    int n;
    cin >> n;
    vector<int> Left, Right;
    vector<int> flag(n, 0);
    for( int i=0; i< n; i++ ){
        int l , r;
        cin >> l;
        cin >> r;
        Left.push_back(l);
        Right.push_back(r);
    }

    int sum = 0;
    for( int i= n-1; i >= 1; i-- ){
        if(flag[i]) continue;		// 没这个加速，只A了
        for( int j = i-1; j>=0; j-- ){
            if( Left[i]<= Left[j] && Right[i] >= Right[j] && flag[j] == 0  ) {
                sum++;
                flag[j] = 1;
            }

        }
    }

    cout << sum << endl;

    return  0;
}
```







