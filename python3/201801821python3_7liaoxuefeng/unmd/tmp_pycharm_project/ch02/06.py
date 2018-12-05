#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch02/06.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

tup = (1, 2, 3)
dt = {}
dt[tup] = "123"
print(dt)
# {(1, 2, 3): '123'}


tu = (1, [2, 3])
dt[tu] = "123"
print(dt)

#     dt[tu] = "123"
# TypeError: unhashable type: 'list'

