#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch14/03.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'


import requests

def load_get():
    # r = requests.get('https://www.douban.com/search',params={'q':'python','cat':'1001'} ) # cat = 1001 是哪个书籍；
    r = requests.get('https://www.douban.com/search',params={'q':'python','cat':'1001'} ) # 去掉cat 就是全部搜索了；
    print('URL:',r.url)
    print('Header:',r.headers)
    print('StatusCode',r.status_code)
    print('Text:',r.text)
    with open('douban.html', 'w') as f:
        f.write(r.text)

def get_json():
    r = requests.get('https://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20weather.forecast%20where%20woeid%20%3D%202151330&format=json')
    print("Json:",r.json())

if __name__ == '__main__':
    load_get()
    get_json()