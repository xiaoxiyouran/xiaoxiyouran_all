#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch14/04.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import chardet

data='天王盖地虎,小鸡炖蘑菇'.encode('GBK')
print (chardet.detect(data) )
# {'language': 'Chinese', 'confidence': 0.7407407407407407, 'encoding': 'GB2312'}

data='天王盖地虎'.encode('GBK')
print( chardet.detect(data) )
# {'language': None, 'confidence': 0.0, 'encoding': None}
