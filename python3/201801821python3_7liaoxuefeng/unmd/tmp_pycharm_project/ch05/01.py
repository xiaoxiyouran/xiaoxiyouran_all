#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch05/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-
from functools import reduce


############################################################
# 第一个测试
def normalize(name):
    return name[:1].upper() + name[1:].lower()

# 测试:
L1 = ['adam', 'LISA', 'barT']
L2 = list(map(normalize, L1))
print(L2)


############################################################
# 第二个测试
def prod(L):
    return reduce(lambda x, y: x*y, L)


print('3 * 5 * 7 * 9 =', prod([3, 5, 7, 9]))
if prod([3, 5, 7, 9]) == 945:
    print('测试成功!')
else:
    print('测试失败!')


############################################################
# 第三个测试

def str2float(s):
    DIGITS = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '.': '.'}
    lm = list(map(lambda n: DIGITS[n], s))

    i = lm.index('.')
    lm.pop(i)
    q = 10 ** (len(lm)-i)

    olm = reduce(lambda x, y: x * 10 + y, lm)
    olm = olm / q
    return olm


print('str2float(\'123.456\') =', str2float('123.456'))
if abs(str2float('123.456') - 123.456) < 0.00001:
    print('测试成功!')
else:
    print('测试失败!')