# 029 输出更正血清后最长的几种血清

## 链接和考点

| 栏目         | 详细       |
| ------------ | ---------- |
| 百度编程测试 | 2018.09.26 |
| 考点         | string     |
| 难度         | Hard       |

<br>

## 题意

改变血清，对于医学家的很多血清，有`1` 和 `0` 两种， 0 表示高于平均值的血清，1 表示低于平均值的血清。比如有以下血清，`101101`, `01100`, `11100` , `01110` 几种血清， 医学家能针对指定次数 count 改变血清种类， 例如，将`101101` 中的一个0 变成1，表示更改了一次。 假设count = 1, 即允许改变一次，那么输出连起来1最多的几种血清。 例如count = 1， 输出 `101101`, `11100`,  `01110`  三种血清，因为它们经过改整后， 最长长度都是4.

<br>

## 分析

1-  感觉是一个滑动窗口问题，还没解决。。。

<br>

## 测试

A了？

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

```



