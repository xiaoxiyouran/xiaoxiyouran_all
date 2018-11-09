#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch10/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

if __name__ == '__main__':
    # 测试:
    # 创建一个实例：
    fpath = r'hellowrold.txt'

    with open(fpath, 'r') as f:
        s = f.read()
        print(s)
