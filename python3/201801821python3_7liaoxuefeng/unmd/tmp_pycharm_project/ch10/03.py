#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch10/03.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import os
import time

def listdir(path) :
    curPath = os.path.abspath(path)
    print('   createTime   ', 'size ', 'fileName')
    for fn in os.listdir(curPath):
        absfile = os.path.join(path, fn)
        fileinfo = os.stat(absfile)
        createTime = time.strftime("%Y-%m-%d %X", time.localtime(fileinfo.st_ctime))
        filesize = ''
        if os.path.isfile(absfile):
            filesize += str(os.path.getsize(absfile))
        print(createTime, filesize, fn)

if __name__ == '__main__':
    # 测试:
    # 创建一个实例

    for entry in os.scandir('../'):
      print(entry.name.encode('utf-8'))

    listdir(r'.')
