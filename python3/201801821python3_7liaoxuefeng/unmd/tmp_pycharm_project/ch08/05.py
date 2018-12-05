#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch08/05.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'



print("-"*10)
class UpperAttrMetaclass(type):
    print("1============")
    def __new__(cls, name, bases, dct):
        print("2============")
        attrs = ((name, value) for name, value in dct.items() if not name.startswith('__'))
        uppercase_attr  = dict((name.upper(), value) for name, value in attrs)  # 把自定义的属性名字大写
        return type.__new__(cls, name, bases, uppercase_attr)

class Foo(metaclass=UpperAttrMetaclass):
    print("3============")
    bar = 'bip'

print("-"*10)
print(hasattr(Foo, 'bar'))
# 输出: False
print(hasattr(Foo, 'BAR'))
print(dir(Foo))
