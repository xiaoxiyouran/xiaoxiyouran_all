#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch07/02_01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-
__author__ = 'xi'

class Animal(object):
    def run(self):
        print('Animal is running...')

    def run_twice (self):
        self.run()

class Dog(Animal):
    def run(self):
        print('Dog is running...')

class Cat(Animal):
    def run(self):
        print('Cat is running...')


if __name__ == '__main__':
    a = Animal()
    d = Dog()
    c = Cat()

    a.run_twice()
    d.run_twice()
    c.run_twice()