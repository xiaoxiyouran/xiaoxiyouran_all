
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/08.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import itertools
def pi(N):
    ' 计算pi的值 '
    # step 1: 创建一个奇数序列: 1, 3, 5, 7, 9, ...

    # step 2: 取该序列的前N项: 1, 3, 5, 7, 9, ..., 2*N-1.

    # step 3: 添加正负符号并用4除: 4/1, -4/3, 4/5, -4/7, 4/9, ...

    # step 4: 求和:

    n = 1  # 记数
    s = 1  # 符号
    result = 0
    for a in itertools.count(1, 2):   # 产生1，3， 5， 7， 9 的序列...
        if (n <= N):
            result = result + 4 / a * s
            n += 1
            s = s * -1
        else:
            break
    return result


if __name__ == '__main__':
    # 测试:
    print(pi(10))
    print(pi(100))
    print(pi(1000))
    print(pi(10000))
    assert 3.04 < pi(10) < 3.05
    assert 3.13 < pi(100) < 3.14
    assert 3.140 < pi(1000) < 3.141
    assert 3.1414 < pi(10000) < 3.1415
    print('ok')
