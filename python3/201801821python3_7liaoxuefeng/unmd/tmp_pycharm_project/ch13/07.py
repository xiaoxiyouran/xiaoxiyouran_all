
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/07.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'


import random,hashlib,hmac

#注册
user_info={}
def registration(u,p):
    if u in user_info:
        print('username existed...please choose another one...')
    else:
        user_info[u]=Users(u,p)

#hmac加密
def get_hmac(key,pw):
    return hmac.new(key.encode('utf-8'),pw.encode('utf-8'),'MD5').hexdigest()

#账号密码处理
class Users(object):
    def __init__(self,username,password):
        self._username=username
        self.key=''.join([chr(random.randint(48,122)) for i in range(25)])  # 这里是随机生成了一个key
        self._password=get_hmac(self.key,password)

#验证登陆
def login(user,pw):
    if user not in user_info.keys():
        return 'no such username'
    else:
        a=user_info[user]
        if a._password == get_hmac(a.key,pw):
            return 'succeeded!'
        else:
            return 'wrong password'

#测试
registration('mary','123')
registration('kirk','abc787')
registration('herby','gg567')
print(user_info)
print(login('mary','123'))


