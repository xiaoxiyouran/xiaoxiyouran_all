
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/10.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'


from urllib import request
import json

def fetch_data(url):
    # 访问url
    response = request.urlopen(url)
    # 对接口返回数据转码
    html = json.loads(response.read().decode('utf-8'))
    return html

if __name__ == '__main__':
    # 测试
    URL = 'https://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20weather.forecast%20where%20woeid%20%3D%202151330&format=json'
    data = fetch_data(URL)
    print(data)
    assert data['query']['results']['channel']['location']['city'] == 'Beijing'
    print('ok')
