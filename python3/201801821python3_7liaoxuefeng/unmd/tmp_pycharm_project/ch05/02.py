#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch05/02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-
from functools import reduce

def is_palindrome(n):
    k = str(n)
    return k == k[::-1]

# 测试:
output = filter(is_palindrome, range(1, 1000))
print('1~1000:', list(output))
if list(filter(is_palindrome, range(1, 200))) == [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191]:
    print('测试成功!')
else:
    print('测试失败!')


