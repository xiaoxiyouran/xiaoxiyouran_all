#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch02/05_01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

L = ['Bart', 'Lisa', 'Adam']
for name in L:
    print("Hello, %s" % name)

# Hello, Bart
# Hello, Lisa
# Hello, Adam

########################################################
# version for while
a=len(L)
while a>0:
    print('Hello, %s'%L[-a])
    a=a-1
print('\n')