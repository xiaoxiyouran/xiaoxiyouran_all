# if else 的简写

如果是普通的三元，if else 正常的结构让人看到有一些冗余，下面有三种方法：

```python
a, b, c = 1, 2, 3
```

<br>

# 第一种： 值1 if 条件 else 值2

示例如下：

```python
a, b, c = 1, 2, 3
c = a if a>b else b
print c   # 2
```

<br>

## 第二种：用两个列表

- 如果 `a>b` 为False，就拿列表第一个位置a;

- 如果是 Ture，就拿列表的第二位置b;

列表第一个位置为list[0],  第二个位置为list[1]

```python
a, b, c = 1, 2, 3
c = [a, b][a > b]
print c   # 1
```

<br>

## 第三种: (c and [a] or [b])[0]

(c and [a] or [b])[0]  当c为真时走a,当c为假时走b

这个有点吊，之前听说c= a>b and a or b 会由bug，当 `a>b `为假的时候，会输出b, 当把a变成列表形式[a]，可以排除这种例外,因为列表有元素a，并不是空列表~

例外如下：

```python
>>> c = ''
>>> a = ''
>>> b = '我是有东西的'
>>> d = c and a or b
>>> print d
我是有东西的
```

另一种情形就是：

```python
>>> c = ''
>>> # a = ''
... a = '我是由东西的'
>>> b = '我是有东西的'
>>> d = c and a or b
>>> print d
我是有东西的
```

也就是a为False，'',None就不行

改成 `` (c and [a] or [b])[0]`` ，可以杜绝列外.

```python
a, b, c = 1, 2, 3
c = (a > b and [a] or [b] )[0]
print c   # 2
```

<br>

## 参考

1- [python if else的简写](https://blog.csdn.net/zm429438709/article/details/80213414) 







