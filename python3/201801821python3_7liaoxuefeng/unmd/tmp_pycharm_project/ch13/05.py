#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/05.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'


import hashlib
db = {
    'michael': 'e10adc3949ba59abbe56e057f20f883e',
    'bob': '878ef96e86145580c38c87f0410ad153',
    'alice': '99b1c2188db85afee403b1536010c2c9'
}

def login(user_name,password):
    md5 = hashlib.md5()
    md5.update(password.encode('utf-8'))
    if md5.hexdigest() == db[user_name]:
        return True
    else:
        return False
print(login('michael', '123456'))

