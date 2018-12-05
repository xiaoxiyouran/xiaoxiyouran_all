# 025 输出频率最高的若干单词

## 链接和考点

| 栏目           | 详细       |
| -------------- | ---------- |
| 拼多多编程测试 | 2018.09.21 |
| 考点           | heap       |
| 难度           | Medi       |

<br>

## 题意

给定一个英文段落（1 <= length <= 1000）, 找出其中出现频率最多的“若干”单词。每个单词仅包含字母，且大小写不敏感。段落中除了包含字母、空格外， 仅包含 `!-?,:;.`等标点。输入保证“至少”有一个结果， 要求结果单词均以小写形式输出，各单词按字母顺序输出，以空格分割。

**输入描述**：

>输入一行，一个非空字符串，表示一个英文段落

**输出描述：**

> 输出一行，包含出现次数最多的单词以字母顺序输出以空格分隔。

示例1 输入输出示例仅供调试，后台判断数据一般不包含示例。

**输入：**

```
i buy an apple watch from the aPple store, by the way I also like eating apple. I
```

**输出**

```
apple:3
i:3
```

<br>

## 分析

1-  输出频次最高的，有可能有多个单词，频次都是最高的且一样，这种题一般用堆解决。

朋友用hashmap A了95%；

<br>

## 测试

A了？ ，没来的及测试就提交了

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
#include "GlobalHead.h"
using namespace std;

using namespace std;
typedef int ElemType;

void get_eachWord(string& in, int& start, int& next, int& fir, int& las){
    fir = start;
    for(int i=start; i<in.size();i++){
        if( i == start ){
            while (in[i] == ' ' || in[i] == '!' || in[i] == '-' || in[i] == '?' || in[i] == ',' ||
                   in[i] == ':' || in[i] == ';' || in[i] == '.' )
                i++;
            fir = i;
        }

        if( in[i] == ' ' || in[i] == '!' || in[i] == '-' || in[i] == '?' || in[i] == ',' ||
            in[i] == ':' || in[i] == ';' || in[i] == '.' ){
            las = i;
            break;
        }

        if( i == in.size()-1 ){
            las = i+1;    // 最后一个
        }
    }

    next = las + 1;     // next; 跳过空格后，新的开始	
}


/* 自定义数据类型：包含一个整数、一个浮点数 */
typedef struct DoubleIndex
{
    string                 id;             // index
    int                   val;            // value
    DoubleIndex(){}
    DoubleIndex(string _id, int _val): id(_id), val(_val){}
    /* 切记定义运算符重载 */
    bool operator < (const DoubleIndex &b) const {
//        if( val == b.val )
//            return id < b.id;
//        else
            return val < b.val; }
    bool operator > (const DoubleIndex &b) const {
//        if( val == b.val )
//            return id < b.id;
//        else
            return val > b.val; }
} DoubleIndex;

/* 比较函数 */
bool CompareDoubleIndex(const DoubleIndex &a, const DoubleIndex &b){
    if( a.val == b.val )
        return a.id < b.id;
    else
        return a.val > b.val;
}

vector<DoubleIndex> list;
unordered_map<string, int> pos;     // store the positiion
void process_each_word( string& word ){
    if( pos.find(word) == pos.end() ){
        pos[word] = list.size();
        DoubleIndex tmp(word, 1);
        list.push_back(tmp);
    }else{
        list[pos[word]].val++;
    }
}

//主函数
int main()
{
    string in;
    getline(cin, in);
    int next = 0, start = 0, fir = 0, las = 0;
    while( next < in.size()  ){
        get_eachWord( in, start, next,  fir,  las);
        start = next;
        string word = in.substr(fir, las-fir);
        transform(word.begin(), word.end(), word.begin(), ::tolower);
//        cout << word << endl;
        process_each_word(word);
    }

    make_heap(list.begin(), list.end(), CompareDoubleIndex);

    sort_heap(list.begin(), list.end(), CompareDoubleIndex);        // 这里必须传入自定义的函数，否则排序无效，我去

    for(auto iter=list.begin();iter!=list.end();++iter){
        cout<<(*iter).id << ":" << (*iter).val<<endl;
        if( (iter+1) != list.end() && (iter+1)->val != iter->val  ) // 下一个和当前不同，那肯定比当前少，就不输出了
            break;

    }
    cout<<endl;

    return  0;
}
```



