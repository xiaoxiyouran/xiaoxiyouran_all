#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch11/02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

from multiprocessing import  Process, Queue, Pool
import  os, time, random

def say(msg):
    print('msg: %s' % msg)
    time.sleep(3)
    print('end')

if __name__ == '__main__':
    # 测试:
    # 创建一个实例：
    print('开始执行主进程')
    start_time = time.time()

    # 使用线程池建立三个子进程
    pool = Pool(3)
    print('开始执行三个子进程')

    for i in range(3):
        # pool.apply(say, [i])
        pool.apply_async(say, [i])

    pool.close()
    pool.join()

    print('主进程结束  耗时 %s ' % (time.time() - start_time))

