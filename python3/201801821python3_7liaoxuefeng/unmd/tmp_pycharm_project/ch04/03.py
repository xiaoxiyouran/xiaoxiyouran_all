#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch04/03.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

L1 = ['Hello', 'World', 18, 'Apple', None]

L2 = [s.lower() for s in L1 if isinstance(s, str)]
print(L2)
if L2 == ['hello', 'world', 'apple']:
    print('测试通过!')
else:
    print('测试失败!')
