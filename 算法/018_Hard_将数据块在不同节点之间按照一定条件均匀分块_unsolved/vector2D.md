# 016 判断是否是完全多部图 

## 链接和考点

| 栏目         | 详细       |
| ------------ | ---------- |
| 阿里编程测试 | 2018.09.07 |
| 考点         | vector2D   |
| 难度         | Hard       |

<br>

## 题意

大数据，需要将一些数据块在不同节点之间备份。 一份数据块有3份备份， 且相同的数据块不要放在一个节点上。

现在有N个节点， M个数据块， 为了使每个节点上的数据尽可能的均匀， 规定每个节点上的数据总量 和 平均值之间的绝对值不能相差L大小， 否则， 就需要将一些数据块调整到其它节点上。

**输入描述**：

>第一行分别是： N（节点数）， M（数据块个数）， L（为了使数据均衡， 每个节点和平均值之间的绝对值不能相差L）
>
>第二行： M个数据块各自的大小
>
>后面的N行， 分别是N个节点上村的数据， 没行第一个数是存的数据块个数， 后面依次是数据块的索引号

示例

```
5 6 100
100 110 120 130 140 150
6 0 1 2 3 4 5
5 0 1 2 3 4
4 0 1 2 3
2 4 5
1 5 
```

那么， 为了使数据均衡，且满足题目中的分配要求， 最少要移动的节点数是：

**输出**

```
3
```



<br>

## 分析 

1-  可以先求出均值，然后将每个节点与平均值之差计算出来， 可以得到，超过的多少，作为一个负数；

如果不够的，用一个正数表示能容纳多少数据量。

<br>

## 测试

A了x

<br>

## 参考答案

代码如下，还没写完，

```java
#include "GlobalHead.h"
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;
struct Node{
    int index;
    int value;
};

double average(vector<int>& in, int Node){
    int sum = 0;
    for( int i=0; i< in.size(); i++ ){
        sum += in[i];
    }

    sum = sum * 3;
    return sum/Node;
}

bool difference( vector<int>& per_node,  vector<int>& partition, int& D, int average ){
    int sum = 0;
    for( int i=0; i < per_node.size(); i++ ){
        sum += partition[per_node[i]];
    }


    if(  abs(sum - average) < D )
        return true;
    else
        return false;
}

bool exist(vector<int>& per_node, int index ){
//    if(  )
}

void process(vector<vector<int>>& node_replica_table, vector<int>& partition, int& D, int& average, int& N, vector<Node>& vec_Node ){
    for( int i=0; i< N; i++ ){
        vector<int> pp_out;
        while ( difference(node_replica_table[i], partition, D, average) ){
            pp_out.push_back( node_replica_table[i][ node_replica_table[i].size()-1]);
            node_replica_table[i].pop_back();
        }
//        for( int j = i; j < N; j++ ){
//            for( int t = 0; t < pp_out.size(); t++ ){
//                if( node_replica_table  vec_Node[0].index )
//            }
//        }

    }
}

// 每个节点的和
int node_sum(vector<int>& node_replica_table, vector<int>& partition){
    int sum = 0;
    for( int i=0; i< node_replica_table.size(); i++ ){
        sum += partition[node_replica_table[i]];
    }
    return sum;
}



bool Cmpare(const Node &a, const Node &b)            //const必须加，不然会错，目前不懂为啥。当return的是ture时，a先输出，所以示例中是升序
{
    return a.value < b.value;
}


vector<vector<pair<int, int>> extract(int index, vector<double>& vec/*contains*/, vector<int>& partition, vector<unordered_map <int, int>>& myvecz){
    // 一个组合问题，求满足条件有多少种方法....

};

void combination( double val,int D, vector<int>& partition, vector<int>& index, vector<int>& path, vector<vector<int>>& res){
    if( val > 0 && val < D ){
        
    }

}

int dfs( vector<double>& vec/*contains*/, vector<int>& partition, vector<unordered_map <int, int>>& myvec){
    if(check_all()){
        return count;   //
    }


    vector<vector<vector<pair<int, int>> > > getout;
    for( int i=0; i < vec.size(); i++  ){
        if ( vec[i] <=0 ){
            getout.push_back();
        }

    }
}

int main() {
    int N, M, D;
    cin >> N;
    cin >> M;
    cin >> D;

    vector<int> partition; // 分区的大小
    for( int i =0; i < M; i++ ){
        int tmp;
        cin >> tmp;
        partition.push_back(tmp);
    }

    vector<vector<int>> NN;


//    general::print_Vec2D(node_replica_table);
    double all_average = average(partition, N);
    vector<unordered_map <int, int>> myvec;
    for( int i=0; i< N; i++ ){
        vector<int> tmp;
        int cnt;
        cin >> cnt;
        unordered_map<int, int> hash;
        for( int j=0; j < cnt; j++ ){
            int val;
            cin >> val;
            tmp.push_back(val);
            hash[val] = val;
        }
        NN.push_back(tmp);
        myvec.push_back(hash);
    }

    vector<double> contains;
    for(int i=0; i< N; i++){
        int av = node_sum(NN[i], partition);
        if( av > (all_average+D) )
            contains.push_back(all_average+D-av);
        else
            contains.push_back(all_average+D - av);
    }

    general::print_Vec1D(contains);


    return 0;
}
```



