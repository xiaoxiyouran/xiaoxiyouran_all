#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch02/02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

s1 = 72
s2 = 85
r = (s2 - s1)/s1 * 100
print('%.1f%%' % r)         # 小数点后1位小数
print('{:.1f}%'.format(r))
print('{0:.1f}%'.format(r))

# 18.1%