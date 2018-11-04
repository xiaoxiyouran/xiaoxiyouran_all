#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch09/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'
import  logging


from functools import reduce

def str2num(s):
    # return int(s)
    s = s.split('.')
    if len(s) == 1:
        return int(s[0])
    else:
        return int(s[0]) + float(s[1]) / 10**len(s[1])

def calc(exp):
    ss = exp.split('+')
    ns = map(str2num, ss)
    return reduce(lambda acc, x: acc + x, ns)

def main():
    r = calc('100 + 200 + 345')
    print('100 + 200 + 345 =', r)
    r = calc('99 + 88 + 7.6')
    print('99 + 88 + 7.6 =', r)


if __name__ == '__main__':
    main()