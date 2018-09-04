#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch04/02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

def findMinAndMax(L):
    if not L:
        return None, None
    min_value = L[0]
    max_value = L[0]
    for v in L[1:]:
        min_value = v < min_value and v or min_value
        max_value = v > max_value and v or max_value

    return min_value, max_value

# 测试
if findMinAndMax([]) != (None, None):
    print('测试失败!')
elif findMinAndMax([7]) != (7, 7):
    print('测试失败!')
elif findMinAndMax([7, 1]) != (1, 7):
    print('测试失败!')
elif findMinAndMax([7, 1, 3, 9, 5]) != (1, 9):
    print('测试失败!')
else:
    print('测试成功!')


