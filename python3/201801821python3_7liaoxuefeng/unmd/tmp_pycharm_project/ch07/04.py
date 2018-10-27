#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch07/04.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-
__author__ = 'xi'

class Student(object):
    count = 0       # 类属性

    def __init__(self, name):
        self.name = name
        Student.count += 1
        # or
        # self.__class__.count += 1


if __name__ == '__main__':
    # 测试:
    if Student.count != 0:
        print('测试失败!')
    else:
        bart = Student('Bart')
        if Student.count != 1:
            print('测试失败!')
        else:
            lisa = Student('Bart')
            if Student.count != 2:
                print('测试失败!')
            else:
                print('Students:', Student.count)
                print('测试通过!')