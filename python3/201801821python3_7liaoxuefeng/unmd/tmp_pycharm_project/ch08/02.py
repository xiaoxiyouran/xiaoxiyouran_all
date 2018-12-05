#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch08/02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-
__author__ = 'xi'



class flyable(object):
    def fly(self):
        print('I can fly')

class runnable(object):
    def run(self):
        print('i can run')
    def fly(self):
        print('I can\'t fly')

class dog(runnable,flyable):
    def run(self):
        print('dog can run')



if __name__ == '__main__':
    dog1 = dog()
    dog1.run()
    dog1.fly()

# dog can run
# I can't fly