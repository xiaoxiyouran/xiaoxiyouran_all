#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch07/03.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-
__author__ = 'xi'



class MyObject(object):
    def __init__(self):
        self.x = 9
    def add(self):
        return self.x + self.x

    def pow(self):
        return self.x * self.x

    def sub(self):
        return self.x - self.x

    def div(self):
        return self.x / self.x

computer = MyObject()

def run(x):
    inp = input('method>')
    # 判断是否有这个属性
    if hasattr(computer,inp):
    # 有就获取然后赋值给新的变量
        func = getattr(computer,inp)
        print(func())
    else:
    # 没有我们来set一个
        setattr(computer,inp,lambda x:x+1)
        func = getattr(computer,inp)
        print(func(x))



if __name__ == '__main__':
    run(10)
