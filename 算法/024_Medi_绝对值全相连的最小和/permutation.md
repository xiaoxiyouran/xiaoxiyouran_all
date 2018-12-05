# 024 绝对值全相连的最小值

## 链接和考点

| 栏目         | 详细        |
| ------------ | ----------- |
| ？？编程测试 | 2018.09.19  |
| 考点         | permutation |
| 难度         | Medi        |

<br>

## 题意

有N个数， 然后选出K个数，作为一组A, 其中的数据为 `[a0,a1,..., ai, ... aK-1]`， 剩下的作为另一组B, 	其中的数据为 `[b0, b1, b2, ..., bj,...]`。 下列公式定义一个距离：

$$ f = \sum_{i \in A}\sum_{j \in B} |a_i - b_j|$$ 

求f的最小值

**输入描述**：

>输入包括2行，
>
>第一行包括 N 和 K， N是总共的数字， K是选的数字
>
>第二行是N个数的值

**输出描述：**

> 输出一个数，能让f最小的情形

**输入：**

```
4 1
3 3 3 1
```

**输出**

```
2
```

**说明**： 选一个数， 选3， 最小f的值为2

<br>

## 分析

1-  根据题目，先求出所有可能的组合， 然后依次求绝对值即可。

<br>

## 测试

A了？ ，没来的及测试就提交了

<br>

## 参考答案

C++ 程序：

```java
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
//#include "GlobalHead.h"

using namespace std;
typedef int ElemType;

void get_pailie(vector<vector<int>>& pailie, vector<int>& path, int start,  int K, int N){
    if( path.size() == K ){
//        general::print_Vec1D(path);
        pailie.push_back(path);
        return;
    }

    for( int i=start; i< N; i++ ){
        path.push_back(i);
        get_pailie(pailie, path, i+1, K, N );
        path.pop_back();
    }
}

int process(vector<int> & one1, vector<int>& org){
   int res = 0;

    for(int i=0; i< one1.size(); i++){
        int value = org[one1[i]];
        for(int j=0; j< org.size();j++){
            if(find(one1.begin(), one1.end(), j) == one1.end() ){
               res += abs( value - org[j] );
            }
        }
    }

    return res;

}

//主函数
int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> in;
    for( int i=0; i< N ; i++ ){
        int tmp;
        cin >> tmp;
        in.push_back(tmp);
    }

    vector<vector<int>> pailie;
    vector<int> path;
    get_pailie(pailie, path, 0,   K,  N);
//    general::print_Vec2D(pailie);

    int res = INT_MAX;
    for( int i=0; i< pailie.size(); i++ ){
         int tmp =   process( pailie[i], in);
        res = (res > tmp)? tmp: res;
    }

    cout << res << endl;
    return  0;
}
```



