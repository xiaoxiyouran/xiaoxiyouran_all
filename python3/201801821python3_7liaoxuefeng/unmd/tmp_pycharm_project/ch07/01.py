#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch07/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-
__author__ = 'xi'

class Student(object):
    def __init__(self, name, gender):
        self.name = name
        self.__gender = gender

    def get_gender(self):
        return self.__gender

    def set_gender(self, gender):
        if gender == "female" or "male":
            self.__gender = gender;

        else:
            raise ValueError("bad gender")


if __name__ == '__main__':
    # 测试:
    bart = Student('Bart', 'male')
    if bart.get_gender() != 'male':
        print('测试失败!')
    else:
        bart.set_gender('female')
        if bart.get_gender() != 'female':
            print('测试失败!')
        else:
            print('测试成功!')
