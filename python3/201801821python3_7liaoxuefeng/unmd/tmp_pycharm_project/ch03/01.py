#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch03/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''


n1 = 255
n2 = 1000

n1_hex = hex(n1)
n2_hex = hex(n2)
print(n1_hex, n2_hex)

print(help(hex))

# 0xff
# 0x3e8
# Help on built - in function hex in module builtins:
#
# hex(number, /)
#     Return the hexadecimal representation of an integer.
#
#     >> > hex(12648430)
#     '0xc0ffee'
# 
# None