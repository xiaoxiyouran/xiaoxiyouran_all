#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch12/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'


import  re

def is_valid_email(addr):
    if re.match(r'[\w.]+@\w+.com$', addr):      # []: 表示范围，可以是字母，数字，或者 .; @ ; \w: 字母或数字; . ; com 结尾
      return True
    return False

# 测试:
assert is_valid_email('someone@gmail.com')
assert is_valid_email('bill.gates@microsoft.com')
assert not is_valid_email('bob#example.com')
assert not is_valid_email('mr-bob@example.com')
print('ok')




