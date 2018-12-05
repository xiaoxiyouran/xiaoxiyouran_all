#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch10/05.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import json
if __name__ == '__main__':
    # 测试:
    # 创建一个实例：
    obj = dict(name='小明', age=20)
    s = json.dumps(obj, ensure_ascii=False)
    print(s)            # {"age": 20, "name": "小明"}

    s = json.loads(s)
    print(s)            # {"age": 20, "name": "小明"}

    # 默认序列化方式
    s = json.dumps(obj)
    print(s)            # {"name": "\u5c0f\u660e", "age": 20}

    s = json.dumps(obj, ensure_ascii=True)
    print(s)            #  {"name": "\u5c0f\u660e", "age": 20}


