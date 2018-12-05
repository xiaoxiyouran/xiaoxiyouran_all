# 022 判断小朋友能否分成两个班

## 链接和考点

| 栏目              | 详细       |
| ----------------- | ---------- |
| 小红书app编程测试 | 2018.09.15 |
| 考点              |            |
| 难度              | Easy       |

<br>

## 题意

幼儿园一个大班要分成两个小班，有些小朋友不希望自己和其它某几位小朋友同班。园长向大家收集了不希望同班的要求， 然后视情况将一个大班的小朋友分成两个班。 请你开发一个程序， 帮助园长快速判断是否所有小朋友的不同班请求都可以满足。

**输入描述**：

>输入分为三部分， 第一个部分是一个int， 代表这个班里小朋友的总数。 第二部分是一个int， 代表园长采集到的小朋友们的请求数。第三部分是小朋友们的请求， 每个请求由两个int组成， 第一个int代表提请求的小朋友， 第二个int代表他不希望同班的另一位小朋友。

**输出描述：**

> 如果所有小朋友们的请求都可以被满足， 输出1， 否则， 输出0.

示例1 输入输出示例仅供调试， 后台判断数据一般不包含

```
5
5
1 2
1 3
1 4
1 5
2 3
```

**输出**

```
0
```

<br>

## 分析

1-  和上一次那个二分图简单些， 只要将提请求的， 如果没有划分组的， 第一次划分组，如果已经划分组的， 检查是否在同一个组即可。

<br>

## 测试

A了100%

<br>

## 参考答案

C++ 程序：

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

struct  node{
    int value;
    int group;
     node(int value, int group): value(value), group(group){}
};

int main(void)
{

    int n, req;
    cin >> n >> req;

    vector<node> all;
    for( int i=0; i < n; i++ ){
        node one(i, 0);
        all.push_back(one);
    }

    bool flag = true;
    for( int i=0; i < req; i++ ){
        int t1, t2;
        cin >> t1 >> t2;
        if( all[t1-1].group == 0 )
            if( all[t2-1].group == 0  )
                all[t1-1].group = 1;
            else
                all[t1-1].group = 0 - all[t2-1].group;	// 划分到对面组

        if ( all[t2-1].group == 0 )
            all[t2-1].group = 0 - all[t1-1].group;

        if( all[t1-1].group == all[t2-1].group ){		// 如果组已经划分好了，直接检查
            flag = false;
            break;
        }

    }

    cout << flag << endl;

    return 0;
}


```

