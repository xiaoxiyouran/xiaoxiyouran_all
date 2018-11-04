#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch11/03.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import threading, multiprocessing

def loop():
    x = 0
    while True:
        x = x ^ 1

for i in range(multiprocessing.cpu_count()):
    t = threading.Thread(target=loop)
    t.start()
