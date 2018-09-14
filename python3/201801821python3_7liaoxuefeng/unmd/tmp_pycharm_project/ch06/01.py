#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch06/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-
__author__ = 'xi'

import os
import sys

if __name__ == '__main__':
    print(os.getcwd())      # 获得当前工作目录
    print(sys.path)
    sys.path.append('../')
    print(sys.path)

