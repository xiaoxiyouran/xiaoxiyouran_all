#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch03/04.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

def move(n, a, b, c):
    if n == 1:
        print(a, '-->' , c)
    else:
        move(n-1, a, c, b)          # 把上面的n-1个盘子移到b后
        # print(a, '-->', c)          # 将剩下一个盘子移到c
        # or
        move(1, a, b, c)
        move(n-1, b, a, c)          # 剩下的n-1个盘子子B上（相当于刚开始的a）, 需要移到c上

move(3, 'A', 'B', 'C')

# A --> C
# A --> B
# C --> B
# A --> C
# B --> A
# B --> C
# A --> C




