#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch05/03.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

# -*- coding: utf-8 -*-



# def createCounter():
#     a = 0           # 只在创建闭包的时候调用一次
#     def counter():
#         nonlocal a
#         a += 1
#         return a
#     return counter

#
# def createCounter():
#     n = [0]
#     def counter():
#         n[0] = n[0] + 1     # 列表可以直接用外部变量
#         return n[0]
#     return counter

def createCounter():
    def iter():
       n=1
       while 1:
        yield n
        n=n+1
    it= iter()
    def counter():
        return next(it)
    return counter


# 测试:
counterA = createCounter()
print(counterA(), counterA(), counterA(), counterA(), counterA()) # 1 2 3 4 5
counterB = createCounter()
if [counterB(), counterB(), counterB(), counterB()] == [1, 2, 3, 4]:
    print('测试通过!')
else:
    print('测试失败!')