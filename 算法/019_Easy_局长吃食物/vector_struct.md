# 019 局长吃食物

## 链接和考点

| 栏目           | 详细           |
| -------------- | -------------- |
| 爱奇艺编程测试 | 2018.09.15     |
| 考点           | vector，struct |
| 难度           | Easy           |

<br>

## 题意

局长有N种食物， 每种食物有Ai 份。

每天局长会吃一份食物，或者买一份食物（即每天只能进行吃或买其中的一种动作），这样过了M天

现在局长想知道M天后第p种食物的份数排名（从到小，相同算并列，例如3 3 2， 则排名为1 1 3）。

N,M,P <= 100, Ai <= 1000

**输入描述**：

>第一行分别是： N, M , P
>
>第二行： N 个 数Ai 
>
>接下来M行， 每行Ai 或者 Bi分别表示买一份食物i， 吃一份食物i

示例

```
3 4 2
5 3 1
B 1
A 2
A 2
A 3
```

**输出**

```
1
```



<br>

## 分析

1-  这个题比较简单，只要对其中的值每次吃或者买进行更新， 最后从大到小排序， 直到找到指定索引的食物， 这时候就能得到排名。

<br>

## 测试

A了100%

<br>

## 参考答案

代码如下，还没写完，

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

typedef struct node{
    int index;      // 所在的种类
    int value;      // 个数

    node(int index, int value): index(index), value(value){}
}node;

int cmp(node a,node b)	// 先按第一个 x 排序
{
//    if (a.value == b.value)  return a.y < b.y;
    return a.value > b.value;
}

int main(void)
{

    int N, M, P;
    cin >> N >> M >> P;

    vector<node> in;
    for( int i=0; i< N; i++ ){
        int tmp;
        cin >> tmp;
        node n_tmp(i+1, tmp);
        in.push_back(n_tmp);
    }

    for(int i=0; i < M; i++){
        char tmp;
        int index;
        cin >> tmp >> index;
        if( tmp == 'A' )
            in[index-1].value++;        						   // buy
        else if(tmp == 'B' &&  in[index-1].value > 0)              // eat
            in[index-1].value--;
    }

    sort(in.begin(), in.end(), cmp);

    int rank = 1;   // 初始
    for( int i = 0; i < in.size() ;i++ ){
        if( i > 0 && (in[i].value != in[i-1].value) ){
            rank = i+1;           // 否则， rank 不变
        }
        if( in[i].index == P ){
            cout << rank << endl;
            break;
        }
    }

    return 0;
}


```



