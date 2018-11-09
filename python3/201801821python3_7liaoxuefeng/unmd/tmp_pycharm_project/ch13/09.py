
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/09.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'



from contextlib import closing
from urllib.request import urlopen

with closing(urlopen('https://www.python.org')) as page:
    for line in page:
        print(line)
