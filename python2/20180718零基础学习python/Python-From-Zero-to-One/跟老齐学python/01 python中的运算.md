# 01 python中的运算

## 数值类型

1- 一般将python的中的数据类型分为==三类==：

- Int: 整型
- float： 浮点型
- 字符串

```python
>>>4+2
6
>>>4.0 + 2
6.0		# 注意这里是浮点数
```



<br>

## 大数相乘

对于大整数计算，一般都要用某种方法转化，否则会溢出。但是python无此担忧了。

Python支持**“无限精度”的整数，**一般情况下不用考虑整数溢出的问题，而且Python Int类型与任意精度的Long整数类可以无缝转换，超过Int 范围的情况都将转换成Long类型。

例如：

```python
>>> 2899887676637907866*1788778992788348277389943

5187258157415700236034169791337062588991638L
```

注意：前面的==“无限精度”是有引号的。事实上也是有限制的，对于32位的机器，其上限是：2^32-1。真的足够大了。==

为什么Python能够做到呢？请有兴趣刨根问底的去看Python的有关源码。本文不赘述。

在其它语言中，通常用“分治法”解决大整数相乘问题。

但是，这里提供一个非常有意思的计算两个整数相乘的方法，算是做为大整数相乘的演示。

两个整数相乘：**阿拉伯乘法**。

解决（Python）

```python
#!/usr/bin/env python
#coding:utf-8

#阿拉伯乘法
def arabic_multiplication(num1,num2):
    num_lst1 = [int(i) for i in str(num1)]  #将int类型的123，转化为list类型的[1,2,3]，每个元素都是int类型
    num_lst2 = [int(i) for i in str(num2)]

    #两个list中整数两两相乘
    int_martix = [[i*j for i in num_lst1] for j in num_lst2]
    
    #将上述元素为数字的list转化为元素类型是str，主要是将9-->'09'
    str_martix = [map(convert_to_str,int_martix[i]) for i in range(len(int_martix))]
    
    #将上述各个list中的两位数字分开：['01','29','03']-->[0,2,0],[1,9,3]
    martix = [[int(str_martix[i][j][z]) for j in range(len(str_martix[i]))] for i in range(len(str_martix)) for z in range(2)]
    
    #计算阿拉伯乘法表的左侧开始各项和
    sum_left = summ_left(martix)

    #计算阿拉伯乘法表的底部开始各项和
    sum_end = summ_end(martix)

    #将上述两个结果合并后翻转
    sum_left.extend(sum_end)
    sum_left.reverse()

    #取得各个和的个位的数字（如果进位则加上）
    result = take_digit(sum_left)
    
    #翻转结果并合并为一个结果字符串数值
    result.reverse()
    int_result = "".join(result)
    print "%d*%d="%(num1,num2)
    print int_result


#将int类型转化为str类型，9-->'09'

def convert_to_str(num):
    if num<10:
        return "0"+str(num)
    else:
        return str(num)


#计算阿拉伯乘法表格左侧开始的各项之和
def summ_left(lst):
    summ = []
    x = [i for i in range(len(lst))]
    y = [j for j in range(len(lst[0]))]
    sx = [i for i in x if i%2==0]
    for i in sx:
        s=0
        j=0
        while i>=0 and j<=y[-1]:
            s = s+ lst[i][j]
            if i%2==1:
                j = j+1
            else:
                j = j
            i = i-1
        summ.append(s)
    return summ



#计算阿拉伯乘法表格底部开始的各项之和
def summ_end(lst):
    summ=[]
    y = [j for j in range(len(lst[0]))]
    ex = len(lst)-1
    for m in range(len(y)):
        s = 0
        i=ex
        j=m
        while i>=0 and j<=y[-1]:
            s= s+lst[i][j]
            if i%2==1:
                j = j+1
            else:
                j=j
            i = i-1
        summ.append(s)
    
    return summ

#得到各个元素的个位数，如果是大于10则向下一个进位
def take_digit(lst):
    tmp = 0
    digit_list = []
    for m in range(len(lst)):
        lstm = 0
        lstm = lst[m]+tmp
        if lstm<10:
            tmp = 0
            digit_list.append(str(lstm))
        else:
            tmp = lstm/10
            mm = lstm-tmp*10
            digit_list.append(str(mm))
    return digit_list


if __name__=="__main__":
    arabic_multiplication(469,37)
```

<br>

## type()

1- 可以用一个命令： type(object) 来检测一个数的类型：

```python
>>> type(4)
<type 'int'>
```

<br>

## 常用的几个函数

### abs()

求绝对值

```python
>>> abs(-10)
10
```

### round()

四舍五入, 默认保留1位小数。 可以通过第二个arg设置保留的小数位（精度）：

```python
>>> round(1.234)
1.0
>>> round(1.234,2)
1.23
```

有时候并非是四舍五入，但这个不是bug， 而是十进制小数很难精确表达

```python
>>> round(1.2345,3)  # 应该是1.235
1.234
>>> round(2.235, 2)	 # 应该是2.24
2.23
```

<br>

### help()

通过help(function name) 来查看函数的帮助信息：

```python
>>> help(round)
Help on built-in function round in module __builtin__:

round(...)
    round(number[, ndigits]) -> floating point number
    
    Round a number to a given precision in decimal digits (default 0 digits).
    This always returns a floating point number.  Precision may be negative.
```

### pow()

幂函数，

```python
>>> pow(2,3)	# 2 的 3 次方
8
```

### import math

math 模块

### math.floor()

```python
>>> import math
>>> math.floor(32.8)	# 向下取整
32.0
```

<br>

### math.sqrt()

```python
>>> math.sqrt(4)		# 开平方
2.0
```

<br>

## 整数除法

在 python2.x 中 整数除以整数还是整数（得到商，==并不是得到小数后再舍弃小数==），而在python3.x 会有所变化。

```python
>>> 2/5
0
>>> 5/2
2
```

### 浮点数和整数除法

如果被除数或者除数有个浮点数的话，其结果就是小数：

```python
>>> 10.0/3
3.3333333333333335		# 无限循环小数的终结并非是四舍五入
```

### python3 中的整数除法

Python3 中的整数除以整数统一起来是小数，但可用地板除得到整数：

```python
>>> 9//2
4
```

<br>

### 引用模块解决除法

python 中的模块很多（轮子），使用起来就很方便了。

引用模块==两种方式==：

- 形式1： import module-name, 例如 import os；
- 形式2： from module1 import sub-module, module1 是一个大模块，如果只想用其中的一个子模块就使用这种方式；

引入模块之后，不管什么情况，得到的都是浮点数的结果。

```python
>>> from __future__ import division
>>> 5/2
2.5
```

<br>

### 求余

和大多数语言一样，使用 `%` 来取得两个数相除的余数。

`% ` 可以是整数也可以是浮点数：

```python
>>> 5%2
1
>>> 5.0 % 2
1.0
>>> 5.1%2
1.0999999999999996
```

<br>

### 对除法保留指定位数的小数

```python
>>> round(10.0/3, 4)	# 对除法结果保留四位小数
3.3333	
```



