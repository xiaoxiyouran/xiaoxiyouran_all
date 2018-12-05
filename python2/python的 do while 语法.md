# python的 do while 语法

[Python](http://d.hatena.ne.jp/keyword/Python)不支持do〜while语法、while（无限循环）和break组合起来替换 do ~ while
p.87

```python

>>> n = 0
>>> while True:   #无限循环
...     print n,
...     n += 1
...     if n == 10:
...             break
... 

```