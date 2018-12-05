# chardet

字符串编码一直是令人非常头疼的问题，尤其是我们在处理一些不规范的第三方网页的时候。虽然Python提供了==Unicode表示的`str`和`bytes`两种数据类型==，并且可以==通过`encode()`和`decode()`方法转换==，但是，在不知道编码的情况下，对`bytes`做`decode()`不好做。

对于==未知编码的`bytes`，要把它转换成`str`，需要先“猜测”编码==。猜测的方式是先收集各种编码的特征字符，根据特征字符判断，就能有很大概率“猜对”。

当然，我们肯定==不能从头自己写这个检测编码的功能，这样做费时费力==。chardet这个第三方库正好就派上了用场。==用它来检测编码，简单易用==。

<br>

## 安装chardet

如果安装了Anaconda，chardet就已经可用了。否则，需要在命令行下通过pip安装：

```python
$ pip install chardet
```

如果遇到Permission denied安装失败，请加上sudo重试。

<br>

## 使用chardet

当我们拿到一个`bytes`时，就可以对其检测编码。用==chardet检测编码，只需要一行代码==：

```python
>>> chardet.detect(b'Hello, world!')
{'encoding': 'ascii', 'confidence': 1.0, 'language': ''}
```

检测出的编码是`ascii`，注意到还有个`confidence`字段，表示==检测的概率是1.0（即100%）==。

我们来试试检测GBK编码的中文：

```python
>>> data = '离离原上草，一岁一枯荣'.encode('gbk')
>>> chardet.detect(data)
{'encoding': 'GB2312', 'confidence': 0.7407407407407407, 'language': 'Chinese'}
```

检测的编码是`GB2312`，注意到GBK是GB2312的超集，两者是同一种编码，检测正确的概率是74%，`language`字段指出的语言是`'Chinese'`。

对UTF-8编码进行检测：

```python
>>> data = '离离原上草，一岁一枯荣'.encode('utf-8')
>>> chardet.detect(data)
{'encoding': 'utf-8', 'confidence': 0.99, 'language': ''}
```

我们再试试对日文进行检测：

```python
>>> data = '最新の主要ニュース'.encode('euc-jp')
>>> chardet.detect(data)
{'encoding': 'EUC-JP', 'confidence': 0.99, 'language': 'Japanese'}
```

可见，用chardet检测编码，==使用简单。获取到编码后，再转换为`str`，==就可以方便后续处理。

chardet支持检测的编码列表请参考官方文档[Supported encodings](https://chardet.readthedocs.io/en/latest/supported-encodings.html)。

<br>

## 小结

使用chardet检测编码非常容易，chardet支持检测中文、日文、韩文等多种语言。

<br>

## 练习

经试验，和字数有关系，字数越多越容易识别出来

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch14/04.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import chardet

data='天王盖地虎,小鸡炖蘑菇'.encode('GBK')
print (chardet.detect(data) )
# {'language': 'Chinese', 'confidence': 0.7407407407407407, 'encoding': 'GB2312'}

data='天王盖地虎'.encode('GBK')
print( chardet.detect(data) )
# {'language': None, 'confidence': 0.0, 'encoding': None}
```

<br>

## 练习2

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch14/05.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import chardet


def check_char(content):
    return chardet.detect(content)

# 默认只接受byte_str，否则返回TypeError
print("bytes", check_char(b"hello world"))  
# bytes {'encoding': 'ascii', 'confidence': 1.0, 'language': ''}
# print("str", check_char("hello world"))  
# TypeError: Expected object of type bytes or bytearray, got: <class 'str'>


# gbk编码：英文是ascii，中文是GB2312(GBK的上一版中文字符集)，language字段指出的语言是'Chinese'
print("str1", check_char("hello world".encode("gbk")))  
# str1 {'encoding': 'ascii', 'confidence': 1.0, 'language': ''}
print("str2", check_char("老子回来啦".encode("gbk")))  
# str2 {'encoding': 'GB2312', 'confidence': 0.99, 'language': 'Chinese'}


# utf-8编码: 英文还是ascii，中文是utf-8了，但是language没有指出，是因为utf-8适用的太多了
print("str3", check_char("hello world".encode("utf-8")))  
# str3 {'encoding': 'ascii', 'confidence': 1.0, 'language': ''}
print("str4", check_char("老子回来啦".encode("utf-8")))  
# str4 {'encoding': 'utf-8', 'confidence': 0.9690625, 'language': ''}
```



