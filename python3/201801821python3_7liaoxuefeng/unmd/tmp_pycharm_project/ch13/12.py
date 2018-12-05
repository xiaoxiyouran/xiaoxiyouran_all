#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/12.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'



import requests
from lxml import html
def fetchWebData(url):
    page = requests.get(url)
    tree = html.fromstring(page.text)
    print(tree)
    titles=tree.xpath('//h3[@class="event-title"]/a/text()')
    times=tree.xpath('//h3/../p/time/@datetime')
    locations=tree.xpath('//span[@class="event-location"]/text()')
    processdata=map(lambda x,y,z:{'event-title':x,'event-time':y,'event-location':z} ,titles,times,locations)
    for n in processdata:
        print (n)

fetchWebData('https://www.python.org/events/python-events/')