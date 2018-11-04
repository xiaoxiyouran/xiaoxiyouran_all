# collections

collections是Python内建的一个集合模块，提供了许多有用的集合类。

<br>

## namedtuple

我们知道`tuple`可以表示==不变集合==，例如，一个点的二维坐标就可以表示成：

```python
>>> p = (1, 2)
```

但是，看到`(1, 2)`，很难看出这个`tuple`是用来表示一个坐标的。

定义一个class又小题大做了，这时，`namedtuple`就派上了用场：

```python
>>> from collections import namedtuple
>>> Point = namedtuple('Point', ['x', 'y'])
>>> p = Point(1, 2)
>>> p.x
1
>>> p.y
2
```

==`namedtuple`是一个函数，它用来创建一个自定义的`tuple`对象，并且规定了`tuple`元素的个数，并可以用属性而不是索引来引用`tuple`的某个元素。==

这样一来，我们用`namedtuple`可以很方便地==定义一种数据类型，它具备tuple的不变性，又可以根据属性来引用==，使用十分方便。

可以验证创建的`Point`对象是`tuple`的一种子类：

```python
>>> isinstance(p, Point)
True
>>> isinstance(p, tuple)
True
```

类似的，如果要用坐标和半径表示一个圆，也可以用`namedtuple`定义：

```python
# namedtuple('名称', [属性list]):
Circle = namedtuple('Circle', ['x', 'y', 'r'])
```

<br>

## deque

使用`list`存储数据时，按索引访问元素很快，但是插入和删除元素就很慢了，因为`list`是线性存储，数据量大的时候，插入和删除效率很低。

deque是为了高效实现插入和删除操作的==双向列表==，适合用于队列和栈：

```python
>>> from collections import deque
>>> q = deque(['a', 'b', 'c'])
>>> q.append('x')
>>> q.appendleft('y')
>>> q
deque(['y', 'a', 'b', 'c', 'x'])
```

`deque`除了实现list的`append()`和`pop()`外，还支持`appendleft()`和`popleft()`，这样就可以非常高效地往头部添加或删除元素。

<br>

## defaultdict

使用`dict`时，如果引用的Key不存在，就会抛出`KeyError`。如果==希望key不存在时，返回一个默认值==，就可以用`defaultdict`：

```python
>>> from collections import defaultdict
>>> dd = defaultdict(lambda: 'N/A')
>>> dd['key1'] = 'abc'
>>> dd['key1'] # key1存在
'abc'
>>> dd['key2'] # key2不存在，返回默认值
'N/A'
```

注意默认值是调用函数返回的，而函数在创建`defaultdict`对象时传入。

==除了在Key不存在时返回默认值，`defaultdict`的其他行为跟`dict`是完全一样==的。

<b4>

## OrderedDict

使用`dict`时，Key是无序的。在对`dict`做迭代时，我们无法确定Key的顺序。

如果==要保持Key的顺序，可以用`OrderedDict`：==

```python
>>> from collections import OrderedDict
>>> d = dict([('a', 1), ('b', 2), ('c', 3)])
>>> d # dict的Key是无序的
{'a': 1, 'c': 3, 'b': 2}
>>> od = OrderedDict([('a', 1), ('b', 2), ('c', 3)])
>>> od # OrderedDict的Key是有序的
OrderedDict([('a', 1), ('b', 2), ('c', 3)])
```

注意，`OrderedDict`的Key会==按照插入的顺序排列，不是Key本身排序：==

```python
>>> od = OrderedDict()
>>> od['z'] = 1
>>> od['y'] = 2
>>> od['x'] = 3
>>> list(od.keys()) # 按照插入的Key的顺序返回
['z', 'y', 'x']
```

`OrderedDict`可以实现==一个FIFO（先进先出）的dict，当容量超出限制时，先删除最早添加的Key==：

```python
from collections import OrderedDict

class LastUpdatedOrderedDict(OrderedDict):

    def __init__(self, capacity):
        super(LastUpdatedOrderedDict, self).__init__()
        self._capacity = capacity

    def __setitem__(self, key, value):
        containsKey = 1 if key in self else 0
        if len(self) - containsKey >= self._capacity:
            last = self.popitem(last=False)
            print('remove:', last)
        if containsKey:
            del self[key]
            print('set:', (key, value))
        else:
            print('add:', (key, value))
        OrderedDict.__setitem__(self, key, value)
```

<br>

## ChainMap

`ChainMap`可以把一组`dict`串起来并组成一个逻辑上的`dict`。==`ChainMap`本身也是一个dict，但是查找的时候，会按照顺序在内部的dict**依次查找** 【这个依次查找很重要】。==

什么时候使用`ChainMap`最合适？举个例子：应用程序往往都需要传入参数，参数可以通过命令行传入，可以通过环境变量传入，还可以有默认参数。我们可以==用`ChainMap`实现参数的优先级查找，即先查命令行参数，如果没有传入，再查环境变量，如果没有，就使用默认参数。==

下面的代码演示了如何查找`user`和`color`这两个参数：

```python
from collections import ChainMap
import os, argparse

# 构造缺省参数:
defaults = {
    'color': 'red',
    'user': 'guest'
}

# 构造命令行参数:
parser = argparse.ArgumentParser()
parser.add_argument('-u', '--user')
parser.add_argument('-c', '--color')
namespace = parser.parse_args()
command_line_args = { k: v for k, v in vars(namespace).items() if v }

# 组合成ChainMap:
combined = ChainMap(command_line_args, os.environ, defaults)	# 字典的集合

# 打印参数:
print('color=%s' % combined['color'])
print('user=%s' % combined['user'])
```

没有任何参数时，打印出默认参数：

```sh
$ python3 use_chainmap.py 
color=red
user=guest
```

当传入命令行参数时，优先使用命令行参数：

```sh
$ python3 use_chainmap.py -u bob
color=red
user=bob
```

同时传入命令行参数和环境变量，命令行参数的优先级较高：

```sh
$ user=admin color=green python3 use_chainmap.py -u bob
color=green
user=bob
```

<br>

## Counter

`Counter`是一个==简单的计数器==，例如，统计字符出现的个数：

```
>>> from collections import Counter
>>> c = Counter()
>>> for ch in 'programming':
...     c[ch] = c[ch] + 1		# 按照键值统计个数， 觉得像是一个hashmap
...
>>> c
Counter({'g': 2, 'm': 2, 'r': 2, 'a': 1, 'i': 1, 'o': 1, 'n': 1, 'p': 1})
```

`Counter`实际上==也是`dict`的一个子类==，上面的结果可以看出，字符`'g'`、`'m'`、`'r'`各出现了两次，其他字符各出现了一次。

<br>

## 小结

`collections`模块提供了一些有用的集合类，可以根据需要选用。

<br>

## 问题1

看了评论，大家对：

```
if len(self) - containsKey >= self._capacity:
```

不是很理解： 其实我感觉是为了代码更安全更严谨吧，实际上如果只是实现FIFO，这些逻辑本身就是多余的。 直接用就可以了

```
if len(self) >= self._capacity:
```

解答：

如果没有这段代码，但同时把<code>del self[key]</code>去掉，是可以重复设置的，不然就报错了。
这段代码的意义在于：超过容量设置属性需要把最新设置的属性删除，而**重复设值是把已有的key值先删除（这个删除值不一定就是最先进入的值）**，所以需要区分。

<hr/>

解答2：

他们说的都是片面的，这段是这个思路，如果我包含这个键的时候我删除再加进来就可以了，没有必要判断长度来删除其他的键，而不包含且长度达到最大的时候是需要移除一个的，所以直接

```python
 if containsKey:
            del self[key]
            print('set:', (key, value))
        else:
            if len(self) >= self._capacity:
                last = self.popitem(last=False)
                print('remove:', last)
            print('add:', (key, value))
```

就可以了.

<br>

解答3：

#### [3.6开始不是dict默认有序了](https://www.liaoxuefeng.com/discuss/001409195742008d822b26cf3de46aea14f2b7378a1ba91000/0015369817135186acb8669b3f5425e8f7d56be8e50800b000)

The order-preserving aspect of this new implementation is considered an implementation detail and should not be relied upon (this may change in the future, but it is desired to have this new dict implementation in the language for a few releases before changing the language spec to mandate order-preserving semantics for all current and future Python implementations; this also helps preserve backwards-compatibility with older versions of the language where random iteration order is still in effect, e.g. Python 3.5).

<https://docs.python.org/3.6/whatsnew/3.6.html#new-dict-implementation>

<br>

## 问题2

借楼问一下popitem括号里的last=false是啥意思？

```python
class fifo_dict(OrderedDict):
    def __init__(self, capacity):
        super().__init__()
        self.__capacity = capacity

    def __setitem__(self, k, v):
        # 如果当前key没有存在于当前字典并且长度已经抵达容量阈值, 则删除F
        if k not in self and len(self) >= self.__capacity:
            last = self.popitem(last=False)
            print('remove:', last)

        super().__setitem__(k, v)
```

解答：

- last = true: 采用LIFO；
- last = flase: 采用FIFO

在补充一点,首先这里的popitem,并不是单纯的dict的那个方法，{}.popitem(last=False)是会报错的。这里的popitem是OrderedDict里的方法，用help(OrderedDict.popitem)可以查到。希望能帮到大家！

<br>

## 问题3

直接调用Counter('programming')也可以，看了下官方文档，元素作key，出现次数是value。所以c[ch]的初始值都是0吗？

```python
from collections import Counter
c = Counter()
for ch in 'programming':
...     c[ch] = c[ch] + 1
...
c
Counter({'g': 2, 'm': 2, 'r': 2, 'a': 1, 'i': 1, 'o': 1, 'n': 1, 'p': 1})
```

<br>

## 问题4

如下程序中：

```python
from collections import OrderedDict

class LastUpdatedOrderedDict(OrderedDict):
  def __init__(self,capacity):
    super(LastUpdatedOrderedDict,self).__init__()
    self._capacity = capacity

  def __setitem__(self,key,value):
    #如果key在dict中存在containsKey为1，不存在containsKey为0
    containsKey = 1 if key in self else 0
    '''
    如果当前元素不在dict中，此时dict的长度已经大于等于自身容量时需要将第一个元素删除
    如果当前元素存在于dict中，此时dict的长度已经大于等于自身容量，但减去1就不满足该条件了
    所以这种情况下会将原来存在的元素给覆盖掉而不是去删除第一个元素。
    '''
    if len(self) - containsKey >= self._capacity:
      last = self.popitem(last=False)
      print('remove',last)
    if containsKey:
      #del self[key]
      print('set:',(key,value))
    else:
      print('add:',(key,value))

    OrderedDict.__setitem__(self,key,value)

if __name__=='__main__':
  luod = LastUpdatedOrderedDict(3)
  luod['x'] = 1
  luod['x'] = 2
  luod['a'] = 1
  luod['b'] = 2
  luod['c'] = 3
```

请问为什么**init**下面有个 `super(LastUpdatedOrderedDict,self).__init__()`，以及最后一行的``OrderedDict.__setitem__(self,key,value)``，这两个地方能解答一下吗?

super是获取父类的方法，相当于 `OrderedDict.__init__()` ;

` OrderedDict.__setitem__(key, value)`就是将`（key,value）`添加到Dict中，这也是继承了父类的方法。















