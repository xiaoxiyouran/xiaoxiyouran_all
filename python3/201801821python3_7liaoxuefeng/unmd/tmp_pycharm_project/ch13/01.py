#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/01.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

from datetime import datetime, timedelta, timezone
import re

def to_timestamp(dt_str, tz_str):
    time = datetime.strptime(dt_str,'%Y-%m-%d %H:%M:%S')
    print(time)  #输出：2015-06-01 08:10:30

    time1 = int(re.match(r'^(UTC)([+-]\d+)\:(00)$', tz_str).group(2))
    print(time1)  #输出：7

    time2 = time + timedelta(hours=8-time1)                 # 本地时区就是8
    print(time2)   #输出：2015-06-01 09:10:30

    time3 = time2.timestamp()
    print(time3)  #输出：1433121030.0

    return time3


def to_timestamp2(dt_str, tz_str):

    # 提取时区
    tz = re.match(r'UTC([+-]\d+):\d+', tz_str).group(1)
    print(tz)

    # str转datetime
    dt = datetime.strptime(dt_str, '%Y-%m-%d %H:%M:%S')
    print(dt)

    # 本地时间转换为UTC时间
    replaced_tz = timezone(timedelta(hours=int(tz)))        # 根据当前的时区和提取的时区对比
    replaced_dt = dt.replace(tzinfo=replaced_tz)
    print(replaced_dt)

    #datetime转timestamp
    return replaced_dt.timestamp()


if __name__ == '__main__':
    # dt_str = '2015-6-1 08:10:30'
    # tz_str = 'UTC+7:00'
    # to_timestamp(dt_str, tz_str)
    # to_timestamp2(dt_str, tz_str)

    # 测试:
    t1 = to_timestamp('2015-6-1 08:10:30', 'UTC+7:00')
    assert t1 == 1433121030.0, t1

    print('----------------------------------')

    t2 = to_timestamp2('2015-5-31 16:10:30', 'UTC-09:00')
    assert t2 == 1433121030.0, t2

    print('ok')
