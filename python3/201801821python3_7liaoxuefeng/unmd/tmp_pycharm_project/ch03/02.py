#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch03/02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

import math

def quadratic(a, b, c = 0):
    '''
    解 a*x^2 + b*x + c = 0 方程的根
    :param a:
    :param b:
    :param c:
    :return:
    '''
    args = locals().values()
    for var in args:
        if not isinstance(var, (int, float)):
            raise TypeError("a, b, c must be int or float type!!!")


    # print( locals().keys()  ,locals().values() )

    if a == 0:
        print("Warnning: 该方程不是一元二次方程!")
        if b == 0:
            print("Warnning: 该方程有无数多个实根!")
            return None, None
        else:
            print("Warnning: 该方程只有一个实根!")
    else:
        M = float(b*b - 4 * a * c)
        if M < 0:
            print("Error: 该方程无实根")
        else:
            k = math.sqrt(M)
            nx = (-b + k)/(2*a)
            ny = (-b - k)/(2*a)
            return nx, ny


# 测试:
print('quadratic(2, 3, 1) =', quadratic(2, 3, 1))
print('quadratic(1, 3, -4) =', quadratic(1, 3, -4))

if quadratic(2, 3, 1) != (-0.5, -1.0):
    print('测试失败')
elif quadratic(1, 3, -4) != (1.0, -4.0):
    print('测试失败')
else:
    print('测试成功')

quadratic("1", "2", "3")
