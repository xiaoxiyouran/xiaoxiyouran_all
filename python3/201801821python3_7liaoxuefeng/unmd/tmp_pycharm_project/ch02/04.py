#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch02/04.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''
#
# height = 1.75
# weight = 80.5

hei = float(input('please enter your height(m):'))
wei = float(input('please enter your weight(kg):'))
bmi = wei/hei/hei
if bmi > 32:
    print('您的bmi指数是%.1f，属于严重肥胖' % bmi)
elif bmi >= 28:
    print('您的bmi指数是%.1f，属于肥胖' % bmi)
elif bmi >= 25:
    print('您的bmi指数是%.1f，属于超重' % bmi)
elif bmi >= 18.5:
    print('您的bmi指数是%.1f，属于正常' % bmi)
else:
    print('您的bmi指数是%.1f，属于过轻' % bmi)

# please enter your height(m):1.75
# please enter your weight(kg):80.5
# 您的bmi指数是26.3，属于超重