#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch03/03.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

def product(*args):
    '''
    计算数的乘积
    :param args:
    :return:
    '''
    if not args:                                            # 如果列表为空，args 就返回 false
        raise TypeError("Error: 必须至少含有一个参数!!!")

    # or
    # if len(args) <= 0:
    #     raise TypeError("Error: 必须至少含有一个参数!!!")

    res = 1
    for x in args:
        if not isinstance(x, (int, float)):                 #加一个参数类型检查
            raise TypeError('Numbers only')
        res = res * x
    return res


# 测试
print('product(5) =', product(5))
print('product(5, 6) =', product(5, 6))
print('product(5, 6, 7) =', product(5, 6, 7))
print('product(5, 6, 7, 9) =', product(5, 6, 7, 9))
if product(5) != 5:
    print('测试失败!')
elif product(5, 6) != 30:
    print('测试失败!')
elif product(5, 6, 7) != 210:
    print('测试失败!')
elif product(5, 6, 7, 9) != 1890:
    print('测试失败!')
else:
    try:
        product()
        print('测试失败!')
    except TypeError:
        print('测试成功!')

