#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch12/02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'


import re


def name_of_email(addr):
    m = re.split(r'[<>@]+', addr)  # []： 可选的分隔符
    if m[0] == '':
        return m[1]
    return m[0]

# 测试:
assert name_of_email('<Tom Paris> tom@voyager.org') == 'Tom Paris'
assert name_of_email('tom@voyager.org') == 'tom'
print('ok')

