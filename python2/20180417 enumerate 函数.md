# 20180417 enumerate 函数

1- 可以返回索引和内容的迭代对象，可以创建链表

2- 当计算文件的行数，文件比较大时，

```python
count = 0
for index, line in enumerate(open(filepath,'r'))： 
    count += 1
```



------

原文： http://www.runoob.com/python/python-func-enumerate.html

## 描述

enumerate() 函数用于将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列，同时列出数据和数据下标，一般用在 for 循环当中。

Python 2.3. 以上版本可用，2.6 添加 start 参数。

### 语法

以下是 enumerate() 方法的语法:

```Python
enumerate(sequence, [start=0])
```



### 参数

- sequence -- 一个序列、迭代器或其他支持迭代对象。
- start -- 下标起始位置。

### 返回值

**返回 enumerate(枚举) 对象。**



## 举例

```python
>>>seasons = ['Spring', 'Summer', 'Fall', 'Winter']
>>> list(enumerate(seasons))
[(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')]
>>> list(enumerate(seasons, start=1))       # 小标从 1 开始
[(1, 'Spring'), (2, 'Summer'), (3, 'Fall'), (4, 'Winter')]
```

普通的for循环

```python
>>>i = 0
>>> seq = ['one', 'two', 'three']
>>> for element in seq:
...     print i, seq[i]
...     i +=1
... 
0 one
1 two
2 three
```

 for 循环使用 enumerate

```python
>>>seq = ['one', 'two', 'three']
>>> for i, element in enumerate(seq):
...     print i, seq[i]
... 
0 one
1 two
2 three
>>
```



------

原文链接： https://blog.csdn.net/churximi/article/details/51648388

##enumerate()说明	

- enumerate()是python的内置函数

- enumerate在字典上是枚举、列举的意思

- 对于一个可迭代的（iterable）/可遍历的对象（如列表、字符串），enumerate将其组成一个索引序列，利用它可以同时获得索引和值

- enumerate多用于在for循环中得到计数

- 例如对于一个seq，得到：

  ```python
  (0, seq[0]), (1, seq[1]), (2, seq[2])
  ```

  enumerate()返回的是一个enumerate对象，例如： 

```Python
seq = ['a','b','c']
print enumerate(seq)
<enumerate object at 0x10db6ab90>
```



## enumerate()使用

- 如果对一个列表，既要遍历索引又要遍历元素时，首先可以这样写：

```python
list1 = ["这", "是", "一个", "测试"]
for i in range (len(list1)):
    print i ,list1[i]
```

- 上述方法有些累赘，利用enumerate()会更加直接和优美：

```python
list1 = ["这", "是", "一个", "测试"]
for index, item in enumerate(list1):
    print index, item
>>>
0 这
1 是
2 一个
3 测试
```

- enumerate还可以接收第二个参数，用于指定索引起始值，如：

```python 
count = len(open(filepath, 'r').readlines())
```

这种方法简单，但是可能比较慢，当**文件比较大**时甚至不能工作。

可以利用enumerate()：

```python
count = 0
for index, line in enumerate(open(filepath,'r'))： 
    count += 1
```







