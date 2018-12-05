#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch14/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

from PIL import Image, ImageFilter

# 打开一个jpg图像文件，注意是当前路径:
im = Image.open('test.jpg')

# 应用模糊滤镜:
im2 = im.filter(ImageFilter.BLUR)
im2.save('blur.jpg', 'jpeg')

