#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch14/05.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import chardet


def check_char(content):
    return chardet.detect(content)

# 默认只接受byte_str，否则返回TypeError
print("bytes", check_char(b"hello world"))  # bytes {'encoding': 'ascii', 'confidence': 1.0, 'language': ''}
# print("str", check_char("hello world"))  # TypeError: Expected object of type bytes or bytearray, got: <class 'str'>


# gbk编码：英文是ascii，中文是GB2312(GBK的上一版中文字符集)，language字段指出的语言是'Chinese'
print("str1", check_char("hello world".encode("gbk")))  # str1 {'encoding': 'ascii', 'confidence': 1.0, 'language': ''}
print("str2", check_char("老子回来啦".encode("gbk")))  # str2 {'encoding': 'GB2312', 'confidence': 0.99, 'language': 'Chinese'}


# utf-8编码: 英文还是ascii，中文是utf-8了，但是language没有指出，是因为utf-8适用的太多了
print("str3", check_char("hello world".encode("utf-8")))  # str3 {'encoding': 'ascii', 'confidence': 1.0, 'language': ''}
print("str4", check_char("老子回来啦".encode("utf-8")))  # str4 {'encoding': 'utf-8', 'confidence': 0.9690625, 'language': ''}