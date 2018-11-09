#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch16/03.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

from tkinter import *


from tkinter import *
import tkinter as tk
import tkinter.messagebox as messagebox


win = Tk()
win.title('title')
win.geometry('100x100')

tk.Label(win, text='hello').place(x=10, y=10)
tk.Button(win, text='1', command=quit).place(x=5, y=30)
tk.Button(win, text='2', command=quit).place(x=25, y=30)
tk.Button(win, text='3', command=quit).place(x=45, y=30)

win.mainloop()
