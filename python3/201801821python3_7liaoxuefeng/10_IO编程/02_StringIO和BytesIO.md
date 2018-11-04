# StringIO和BytesIO

## StringIO

很多时候，数据读写不一定是文件，也可以==在内存中读写==。

StringIO顾名思义就是==在内存中读写str==。

要把str写入StringIO，我们需要先创建一个StringIO，然后，像文件一样写入即可：

```python
>>> from io import StringIO
>>> f = StringIO()
>>> f.write('hello')
5
>>> f.write(' ')
1
>>> f.write('world!')
6
>>> print(f.getvalue())
hello world!
```

==`getvalue()`方法用于获得写入后的str==。

要读取StringIO，可以==用一个str初始化StringIO，然后，像读文件一样读取==：

```python
>>> from io import StringIO
>>> f = StringIO('Hello!\nHi!\nGoodbye!')
>>> while True:
...     s = f.readline()
...     if s == '':
...         break
...     print(s.strip())
...
Hello!
Hi!
Goodbye!
```

<br>

## BytesIO

StringIO操作的只能是str，如果==要操作二进制数据，就需要使用BytesIO==。

BytesIO实现了==在内存中读写bytes==，我们创建一个BytesIO，然后写入一些bytes：

```python
>>> from io import BytesIO
>>> f = BytesIO()
>>> f.write('中文'.encode('utf-8'))
6
>>> print(f.getvalue())
b'\xe4\xb8\xad\xe6\x96\x87'
```

请注意，写入的不是str，而是**经过UTF-8编码的bytes**。

和StringIO类似，==可以用一个bytes初始化BytesIO，然后，像读文件一样读取==：

```python
>>> from io import BytesIO
>>> f = BytesIO(b'\xe4\xb8\xad\xe6\x96\x87')
>>> f.read()
b'\xe4\xb8\xad\xe6\x96\x87'
```

<br>

## 练习

```python
from io import StringIO;

f = StringIO();
f.write('Hello World');
s = f.readline();
print s;
```

上面这种方法无论如何都读不出f的内容,使用readlines和循环也不行

上面是文中介绍的先初始化一个stringIO流,然后readline读取内容,这样就可以

为什么会这样呢?

是因为the stream position的原因，当你用：

```python
d = StringIO('Hello World')
```

其stream position为0（可以通过d.tell()获得），而后执行

```python
d.readline()
```

stream position移动到11.因此在执行此方法时，返回的是空字符串。

类似的，使用

```python
f = StringIO()
```

stream position也为0，而执行

```python
f.write('Hello World')
```

stream position就移动到11了，因此你再执行readline时返回的依旧是空字符串，若你需要返回'Hello World'可以通过

```python
f.seek(0)
```



调整stream position即可。

完整测试如下：

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch10/02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

from io import StringIO

if __name__ == '__main__':
    # 测试:
    # 创建一个实例：
    d = StringIO('Hello World')
    print(d.tell())         # 0
    print(d.readline())     # Hello World

    print(d.tell())         # 11

    f = StringIO()
    f.write('Hello World')
    print(f.tell())         # 11
    f.seek(0)
    print(f.readline())     # Hello World

```

<br>

## 总结

StringIO和BytesIO

stringIO 比如说，这时候，你需要对获取到的数据进行操作，但是你并不想把数据写到本地硬盘上，这时候你就可以用stringIO

```python

from io import StringIO
from io import BytesIO
def outputstring():
    return 'string \nfrom \noutputstring \nfunction'

s = outputstring()

# 将函数返回的数据在内存中读
sio = StringIO(s)
# 可以用StringIO本身的方法
print(sio.getvalue())
# 也可以用file-like object的方法
s = sio.readlines()
for i in s:
    print(i.strip())


# 将函数返回的数据在内存中写
sio = StringIO()
sio.write(s)
# 可以用StringIO本身的方法查看
s=sio.getvalue()
print(s)
```

如果你用file-like object的方法查看的时候，你会发现数据为空

```python
sio = StringIO()
sio.write(s)
for i in sio.readlines():
    print(i.strip())
```

这时候我们需要修改下文件的指针位置

我们发现可以打印出内容了

```python
sio = StringIO()
sio.write(s)
sio.seek(0,0)
print(sio.tell())
for i in sio.readlines():
    print(i.strip())
```

这就涉及到了两个方法seek 和 tell

tell 方法获取当前文件读取指针的位置

seek 方法，用于移动文件读写指针到指定位置,有两个参数，**第一个offset: 偏移量，需要向前或向后的字节数，正为向后，负为向前；第二个whence: 可选值，默认为0，表示文件开头，1表示相对于当前的位置，2表示文件末尾**

用seek方法时，需注意，如果**你打开的文件没有用'b'的方式打开，则offset无法使用负值哦**

stringIO 只能操作str，如果要操作二进制数据，就需要用到BytesIO

上面的sio**无法用seek从当前位置向前移动**，这时候，我们用'b'的方式写入数据，就可以向前移动了

```python
bio = BytesIO()
bio.write(s.encode('utf-8'))
print(bio.getvalue())
bio.seek(-36,1)
print(bio.tell())
for i in bio.readlines():
    print(i.strip())
```



