# contextlib

在Python中，读写文件这样的资源要特别注意，必须在==使用完毕后正确关闭==它们。正确关闭文件资源的==一个方法是使用`try...finally`：==

```python
try:
    f = open('/path/to/file', 'r')
    f.read()
finally:
    if f:
        f.close()
```

写`try...finally`非常繁琐。Python的==`with`语句允许我们非常方便地使用资源==，而不必担心资源没有关闭，所以上面的代码可以简化为：

```python
with open('/path/to/file', 'r') as f:
    f.read()
```

并不是只有`open()`函数返回的fp对象才能使用`with`语句。实际上，==任何对象，只要正确实现了上下文管理，就可以用于`with`语句。==

<br>

## 上下文管理

实现==上下文管理是通过`__enter__`和`__exit__`这两个方法实现的==。例如，下面的class实现了这两个方法：

```python
class Query(object):
    def __init__(self, name):
        self.name = name

    def __enter__(self):
        print('Begin')
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        if exc_type:
            print('Error')
        else:
            print('End')

    def query(self):
        print('Query info about %s...' % self.name)
```

这样我们就可以把自己写的资源对象用于`with`语句：

```python
with Query('Bob') as q:
    q.query()
```

<br>

## @contextmanager

编写`__enter__`和`__exit__`仍然很繁琐，因此Python的标准库`contextlib`提供了更简单的写法，上面的代码可以改写如下：

```python
from contextlib import contextmanager

class Query(object):

    def __init__(self, name):
        self.name = name

    def query(self):
        print('Query info about %s...' % self.name)

@contextmanager
def create_query(name):
    print('Begin')
    q = Query(name)
    yield q
    print('End')
```

`@contextmanager`这个decorator**接受一个generator**，用`yield`语句把`with ... as var`把变量输出出去，然后，`with`语句就可以正常地工作了：

```python
with create_query('Bob') as q:
    q.query()
```

很多时候，我们希望在某段代码==执行前后自动执行特定代码==，也可以用`@contextmanager`实现。例如：

```python
@contextmanager
def tag(name):
    print("<%s>" % name)
    yield
    print("</%s>" % name)

with tag("h1"):
    print("hello")
    print("world")
```

上述代码执行结果为：

```python
<h1>
hello
world
</h1>
```

代码的执行顺序是：

1. `with`语句==首先执行`yield`之前的语句，因此打印出`<h1>`；==
2. `yield`调用==会执行`with`语句内部的所有语句==，因此打印出`hello`和`world`；
3. ==最后执行`yield`之后的语句，打印出`</h1>`。==

因此，`@contextmanager`让我们==通过编写generator来简化上下文管理。==

<br>

## @closing

如果一个对象没有实现上下文，我们就不能把它用于`with`语句。这个时候，可以**用`closing()`来把该对象变为上下文对象**。例如，用`with`语句使用`urlopen()`：

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/09.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

from contextlib import closing
from urllib.request import urlopen

with closing(urlopen('https://www.python.org')) as page:
    for line in page:
        print(line)

```

如果要爬 https， 需要加context 参数：

```python
import ssl

with closing(urlopen('https://www.python.org',context=ssl._create_unverified_context())) as page:
```

`closing`也是一个经过@contextmanager装饰的generator，这个generator编写起来其实非常简单：

```python
@contextmanager
def closing(thing):
    try:
        yield thing
    finally:
        thing.close()
```

它的作用就是**把任意对象变为上下文对象**，并支持`with`语句。

`@contextlib`还有一些其他decorator，便于我们编写更简洁的代码。

<br>

## 总结

例如：

```python
with context_expression [as target(s)]:     
	with-body，
```

它的执行顺序是这样的

1.执行 context_expression，生成上下文管理器 context_manager

2.调用上下文管理器的 `__enter__()` 方法；如果使用了 as 子句，则将  `__enter__()`  方法的**返回值赋值给 as 子句中的 target(s)** 

3.执行语句体 with-body 

4.不管是否执行过程中是否发生了异常，执行上下文管理器的 `__exit__()` 方法，`__exit__()` 方法负责执行“清理”工作，如释放资源等。

- 如果执行过程中没有出现异常，或者语句体中执行了语句 break/continue/return，则以 None 作为参数调用`__exit__((None, None, None) `；

- 如果执行过程中出现异常，则使用 sys.exc_info 得到的异常信息为参数调用 `__exit__(exc_type, exc_value, exc_traceback)`

5.出现异常时，如果 `__exit__(type, value, traceback) `返回 False，则会重新抛出异常，让with 之外的语句逻辑来处理异常，这也是通用做法；如果返回 True，则忽略异常，不再对异常进行处;





