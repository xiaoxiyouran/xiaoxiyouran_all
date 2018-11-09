#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/03.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import base64

def safe_base64_decode(s):
    s=s+b'='*(4-(4 if len(s)%4 ==0 else len(s)%4))
    return base64.b64decode(s)

if __name__ == '__main__':
    # 测试:
    assert b'abcd' == safe_base64_decode(b'YWJjZA=='), safe_base64_decode('YWJjZA==')
    assert b'abcd' == safe_base64_decode(b'YWJjZA'), safe_base64_decode('YWJjZA')
    print('ok')


