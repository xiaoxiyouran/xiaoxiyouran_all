# datetime

datetime是Python处理日期和时间的标准库。

<br>

## 获取当前日期和时间

我们先看如何获取当前日期和时间：

```python
>>> from datetime import datetime
>>> now = datetime.now() # 获取当前datetime
>>> print(now)
2015-05-18 16:28:07.198690
>>> print(type(now))
<class 'datetime.datetime'>
```

注意到==`datetime`是模块，`datetime`模块还包含一个`datetime`类，==通过`from datetime import datetime`导入的才是`datetime`这个类。

如果仅导入`import datetime`，则必须引用全名`datetime.datetime`。

`datetime.now()`返回当前日期和时间，其类型是`datetime`。

<br>

## 获取指定日期和时间

要指定某个日期和时间，我们直接用参数构造一个`datetime`：

```python
>>> from datetime import datetime
>>> dt = datetime(2015, 4, 19, 12, 20) # 用指定日期时间创建datetime
>>> print(dt)
2015-04-19 12:20:00
```

<br>

## datetime转换为timestamp

在计算机中，时间实际上是用数字表示的。我们把1970年1月1日 00:00:00 UTC+00:00时区的时刻称为epoch 【时代，时期，纪元】time，记为`0`（1970年以前的时间timestamp为负数），当前时间就是相对于epoch time的秒数，称为timestamp。

你可以认为：

```
timestamp = 0 = 1970-1-1 00:00:00 UTC+0:00
```

对应的北京时间是：

```python
timestamp = 0 = 1970-1-1 08:00:00 UTC+8:00
```

可见timestamp的值与时区毫无关系，因为timestamp一旦确定，其UTC时间就确定了，转换到任意时区的时间也是完全确定的，这就是为什么计算机存储的当前时间是以timestamp表示的，因为全球各地的计算机在任意时刻的timestamp都是完全相同的（假定时间已校准）。

把一个`datetime`类型转换为timestamp只需要简单调用`timestamp()`方法：

```python
>>> from datetime import datetime
>>> dt = datetime(2015, 4, 19, 12, 20) # 用指定日期时间创建datetime
>>> dt.timestamp() # 把datetime转换为timestamp
1429417200.0
```

注意Python的timestamp是一个浮点数。如果有小数位，小数位表示毫秒数。

某些编程语言（如Java和JavaScript）的==timestamp使用整数表示毫秒数，这种情况下只需要把timestamp除以1000就得到Python的浮点表示方法。==

<br>

## timestamp转换为datetime

要把timestamp转换为`datetime`，使用`datetime`提供的`fromtimestamp()`方法：

```python
>>> from datetime import datetime
>>> t = 1429417200.0
>>> print(datetime.fromtimestamp(t))
2015-04-19 12:20:00
```

注意到timestamp是一个浮点数，它**没有时区的概念，而datetime是有时区**的。上述转换是在timestamp和本地时间做转换。

**本地时间是指当前操作系统设定的时区**。例如北京时区是东8区，则本地时间：

```python
2015-04-19 12:20:00
```

实际上就是**UTC+8:00时区的时间**：

```python
2015-04-19 12:20:00 UTC+8:00
```

而此刻的格林威治标准时间与北京时间差了8小时，也就是UTC+0:00时区的时间应该是：

```sh
2015-04-19 04:20:00 UTC+0:00
```

timestamp也可以直接被转换到**UTC标准时区**的时间：

```python
>>> from datetime import datetime
>>> t = 1429417200.0
>>> print(datetime.fromtimestamp(t)) # 本地时间
2015-04-19 12:20:00
>>> print(datetime.utcfromtimestamp(t)) # UTC时间
2015-04-19 04:20:00
```

<br>

## str转换为datetime

很多时候，用户输入的日期和时间是字符串，要处理日期和时间，首先**必须把str转换为datetime**。转换方法是通过`datetime.strptime()`实现，需要一个日期和时间的格式化字符串：

```python
>>> from datetime import datetime
>>> cday = datetime.strptime('2015-6-1 18:19:59', '%Y-%m-%d %H:%M:%S')
>>> print(cday)
2015-06-01 18:19:59
```

字符串`'%Y-%m-%d %H:%M:%S'` **规定了日期和时间部分的格式**。详细的说明请参考[Python文档](https://docs.python.org/3/library/datetime.html#strftime-strptime-behavior)。

注意转换后的datetime是没有时区信息的。

<br>

## datetime转换为str

如果已经有了datetime对象，要**把它格式化为字符串显示给用户，就需要转换为str**，转换方法是通过`strftime()`实现的，同样需要一个日期和时间的格式化字符串：

```
>>> from datetime import datetime
>>> now = datetime.now()
>>> print(now.strftime('%a, %b %d %H:%M'))
Mon, May 05 16:28
```

<br>

## datetime加减

对日期和时间进行加减实际上就是把datetime往后或往前计算，得到新的datetime。加减可以直接用`+`和`-`运算符，不过需要导入`timedelta`这个类：

```python
>>> from datetime import datetime, timedelta
>>> now = datetime.now()
>>> now
datetime.datetime(2015, 5, 18, 16, 57, 3, 540997)
>>> now + timedelta(hours=10)
datetime.datetime(2015, 5, 19, 2, 57, 3, 540997)
>>> now - timedelta(days=1)
datetime.datetime(2015, 5, 17, 16, 57, 3, 540997)
>>> now + timedelta(days=2, hours=12)
datetime.datetime(2015, 5, 21, 4, 57, 3, 540997)
```

可见，使用`timedelta`你可以很容易地算出前几天和后几天的时刻。

<br>

## 本地时间转换为UTC时间

本地时间是指系统设定时区的时间，例如北京时间是UTC+8:00时区的时间，而UTC时间指UTC+0:00时区的时间。

一个`datetime`类型有一个时区属性`tzinfo`，但是默认为`None`，所以无法区分这个`datetime`到底是哪个时区，除非强行给`datetime`设置一个时区：

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

from datetime import datetime, timedelta, timezone

tz_utc_8 = timezone(timedelta(hours=8)) # 创建时区UTC+8:00
now = datetime.now()
print(now)          # 2018-10-25 16:34:25.281069

dt = now.replace(tzinfo=tz_utc_8)
print(dt)           # 2018-10-25 16:34:25.281069+08:00
```

如果系统时区恰好是UTC+8:00，那么上述代码就是正确的，否则，不能强制设置为UTC+8:00时区。

<br>

## 时区转换

我们可以先通过`utcnow()`拿到当前的UTC时间，再转换为任意时区的时间：

```python
# 拿到UTC时间，并强制设置时区为UTC+0:00:
>>> utc_dt = datetime.utcnow().replace(tzinfo=timezone.utc)
>>> print(utc_dt)
2015-05-18 09:05:12.377316+00:00
            
# astimezone()将转换时区为北京时间:
>>> bj_dt = utc_dt.astimezone(timezone(timedelta(hours=8)))
>>> print(bj_dt)
2015-05-18 17:05:12.377316+08:00
            
# astimezone()将转换时区为东京时间:
>>> tokyo_dt = utc_dt.astimezone(timezone(timedelta(hours=9)))
>>> print(tokyo_dt)
2015-05-18 18:05:12.377316+09:00
            
# astimezone()将bj_dt转换时区为东京时间:
>>> tokyo_dt2 = bj_dt.astimezone(timezone(timedelta(hours=9)))
>>> print(tokyo_dt2)
2015-05-18 18:05:12.377316+09:00
```

时区转换的关键在于，**拿到一个`datetime`时，要获知其正确的时区，然后强制设置时区，作为基准时间。**

**利用带时区的`datetime`，通过`astimezone()`方法，可以转换到任意时区。**

注：不是必须从UTC+0:00时区转换到其他时区，任何带时区的`datetime`都可以正确转换，例如上述`bj_dt`到`tokyo_dt`的转换。

<br>

## 小结

`datetime`表示的时间**需要时区信息才能确定一个特定的时间，否则只能视为本地时间**。

如果要存储`datetime`，最佳方法是将其转换为timestamp再存储，因为timestamp的值与时区完全无关。

<br>

## 练习

假设你获取了用户输入的日期和时间如`2015-1-21 9:01:30`，以及一个时区信息如`UTC+5:00`，均是`str`，请编写一个函数将其转换为timestamp：

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

from datetime import datetime, timedelta, timezone
import re

def to_timestamp(dt_str, tz_str):
    time = datetime.strptime(dt_str,'%Y-%m-%d %H:%M:%S')
    print(time)  #输出：2015-06-01 08:10:30

    time1 = int(re.match(r'^(UTC)([+-]\d+)\:(00)$', tz_str).group(2))
    print(time1)  #输出：7

    time2 = time + timedelta(hours=8-time1)                 # 本地时区就是8
    print(time2)   #输出：2015-06-01 09:10:30

    time3 = time2.timestamp()
    print(time3)  #输出：1433121030.0

    return time3


def to_timestamp2(dt_str, tz_str):

    # 提取时区
    tz = re.match(r'UTC([+-]\d+):\d+', tz_str).group(1)
    print(tz)

    # str转datetime
    dt = datetime.strptime(dt_str, '%Y-%m-%d %H:%M:%S')
    print(dt)

    # 本地时间转换为UTC时间
    replaced_tz = timezone(timedelta(hours=int(tz)))        # 根据当前的时区和提取的时区对比
    replaced_dt = dt.replace(tzinfo=replaced_tz)
    print(replaced_dt)

    #datetime转timestamp
    return replaced_dt.timestamp()


if __name__ == '__main__':
    # dt_str = '2015-6-1 08:10:30'
    # tz_str = 'UTC+7:00'
    # to_timestamp(dt_str, tz_str)
    # to_timestamp2(dt_str, tz_str)

    # 测试:
    t1 = to_timestamp('2015-6-1 08:10:30', 'UTC+7:00')
    assert t1 == 1433121030.0, t1

    print('----------------------------------')

    t2 = to_timestamp2('2015-5-31 16:10:30', 'UTC-09:00')
    assert t2 == 1433121030.0, t2

    print('ok')
```

timestamp指的是当前时间距离1970-1-1 00:00的时间,这个timestamp好像只要知道你当前时间和时区就可以计算当前据1970-1-1的时间.

而且只要**在同一时间,不管你在哪个时区,比如说东8区和东10区,它们的timestamp好像是一样的**,不会因为相差两个时区就改变,timestamp是个基准时间,只要你没穿越时空,我们的timestamp都是一样的 

