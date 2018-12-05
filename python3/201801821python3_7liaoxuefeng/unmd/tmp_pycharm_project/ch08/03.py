#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch08/03.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-
__author__ = 'xi'

from enum import Enum, unique

@unique
class Gender(Enum):
    Male = 0
    Female = 1


class Student(object):
    def __init__(self, name, gender):
        self.name = name
        if not isinstance(gender, Gender):
            raise TypeError('输入类型错误!')

        # or
        # if type(gender) != Gender:
        #     raise TypeError('输入类型错误!')

        self.gender = gender

    def __str__(self):
        return '学生的姓名为：%s,性别为：%s' % (self.name, self.gender)

    __repr__ = __str__




if __name__ == '__main__':
    # 测试:
    bart = Student('Bart', Gender.Male)
    if bart.gender == Gender.Male:
        print('测试通过!')
    else:
        print('测试失败!')

    print(Student('Micheal', Gender.Female))

# 测试通过!
# 学生的姓名为：Micheal,性别为：Gender.Female