#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch05/05.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-

import functools
from inspect import isfunction
import time


def logger(arg=''):
    if type(arg) == str or not arg:
        # 带一个参数调用
        def decorator(fn):
            @functools.wraps(fn)
            def wrapper(*args, **kw):
                # print(arg + ' begin call')
                print('Begin call %s' % fn.__name__)
                start = time.time()
                fw = fn(*args, **kw)
                end = time.time()
                print('%s executed in %.4f ms' % (fn.__name__, end - start))
                print('End call %s' % fn.__name__)
                # print(arg + ' end call')
                return fw

            # print('Begin call %s' % fn.__name__)
            return wrapper
        return decorator

    if isfunction(arg):
        # 不带参数调用
        @functools.wraps(arg)
        def warpper(*args, **kw):
            # print('begin call')
            print('Begin call %s' % arg.__name__)
            start = time.time()
            fw = arg(*args, **kw)
            end = time.time()
            print('%s executed in %.4f ms' % (arg.__name__, end - start))
            print('End call %s' % arg.__name__)
            # print('end call')
            return fw


        return warpper


# 测试
@logger('execute')
def fast(x, y):
    time.sleep(0.0012)
    return x + y;

@logger
def slow(x, y, z):
    time.sleep(0.1234)
    return x * y * z;

f = fast(11, 22)
s = slow(11, 22, 33)
if f != 33:
    print('测试失败!')
elif s != 7986:
    print('测试失败!')
