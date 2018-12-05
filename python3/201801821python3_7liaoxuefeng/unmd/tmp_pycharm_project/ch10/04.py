#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch10/04.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import os


def searchfunc(key,path):
    for f in os.listdir(path):
        #应当传入完整路径到isfile和isdir函数中进行判断
        FilePath = os.path.abspath(os.path.join(path, f))
        if os.path.isfile(FilePath):
            if key in str(FilePath[:FilePath.find('.')]):
                print(FilePath)

        elif os.path.isdir(FilePath):
            searchfunc(key,FilePath)

def main():
    index = input('请输入检索名称：')
    path=os.path.abspath('.')
    searchfunc(index, path)


if __name__ == '__main__':
    main()