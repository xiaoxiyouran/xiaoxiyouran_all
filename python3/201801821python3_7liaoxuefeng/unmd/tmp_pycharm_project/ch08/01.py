#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch08/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-
__author__ = 'xi'

class Screen(object):
    @property
    def width(self):
        return self.m_width

    @width.setter
    def width(self, value):
        self.m_width = value

    @property
    def height(self):
        return self.m_height

    @height.setter
    def height(self, value):
        self.m_height = value

    @property
    def resolution(self):
        return self.m_width * self.height

if __name__ == '__main__':
    # 测试
    s = Screen()
    s.width = 1024
    s.height = 768
    print('resolution =', s.resolution)
    if s.resolution == 786432:
        print('测试通过!')
    else:
        print('测试失败!')