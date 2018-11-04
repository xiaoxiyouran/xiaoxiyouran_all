#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/11.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

from xml.parsers.expat import ParserCreate
from urllib import request
class DefaultSaxHandler(object):
    weather = {'city':'','forecast':[]}

    def start_element(self, name, attrs):
        if name == 'yweather:location':
            self.weather['city'] = attrs['city']
        if name == 'yweather:forecast':
            self.weather['forecast'].append({'date':attrs['date'],'high':attrs['high'],'low':attrs['low']})

def url_request(url):
    with request.urlopen(url) as weather:
        data = weather.read()
        return data


if __name__ == '__main__':
    URL = 'https://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20weather.forecast%20where%20woeid%20%3D%202151330&format=xml'
    handler = DefaultSaxHandler()
    parser = ParserCreate()
    parser.StartElementHandler = handler.start_element
    parser.Parse(url_request(URL))
    print(handler.weather)





