#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch09/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'
import logging
logging.basicConfig(level=logging.INFO)	#得添加 logging 的配置, level 的等级：debug，info，warning，error


if __name__ == '__main__':
    s = '0'
    n = int(s)
    logging.info('n = %d' % n)
    print(10 / n)

