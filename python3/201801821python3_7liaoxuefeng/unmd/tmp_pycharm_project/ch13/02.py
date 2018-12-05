#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/02.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

from datetime import datetime, timedelta, timezone

tz_utc_8 = timezone(timedelta(hours=8)) # 创建时区UTC+8:00
now = datetime.now()
print(now)          # 2018-10-25 16:34:25.281069

dt = now.replace(tzinfo=tz_utc_8)
print(dt)           # 2018-10-25 16:34:25.281069+08:00

