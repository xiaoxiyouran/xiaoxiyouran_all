#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch11/04.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'


import multiprocessing
from multiprocessing import Pool, Process
import threading

def loop(i):
    x = 0
    print('Thread - ',i)
    while True:
        x = x ^ 1
        print('haha')

def proc(i, cpu_cout):
    print('Process: ',i)
    for i in range(cpu_cout*2):
        t = threading.Thread(target=loop, args=(i,))
        t.start()

if __name__ == '__main__':
    cpu_cout = multiprocessing.cpu_count()
    p = Pool(cpu_cout)
    for i in range(cpu_cout):
        p.apply_async(proc,args=(i, cpu_cout))
    p.close()
    p.join()
