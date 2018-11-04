#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch10/02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

from io import StringIO

if __name__ == '__main__':
    # 测试:
    # 创建一个实例：
    d = StringIO('Hello World')
    print(d.tell())         # 0
    print(d.readline())     # Hello World

    print(d.tell())         # 11

    f = StringIO()
    f.write('Hello World')
    print(f.tell())         # 11
    f.seek(0)
    print(f.readline())     # Hello World
