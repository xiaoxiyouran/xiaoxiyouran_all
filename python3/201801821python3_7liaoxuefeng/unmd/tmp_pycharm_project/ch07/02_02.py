#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch07/02_02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-
__author__ = 'xi'

class Animal(object):
    def run(self):
        print('Animal is running...')

class Dog(Animal):
    def run(self):
        print('Dog is running...')

class Cat(Animal):
    def run(self):
        print('Cat is running...')


def run_twice (animal):
    '''
    全局函数， 演示有run() 方法的鸭子特性
    :param self:
    :return: animal
    '''
    animal.run()


if __name__ == '__main__':
    a = Animal()
    d = Dog()
    c = Cat()

    run_twice(a)
    run_twice(d)
    run_twice(c)