
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/06.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import hashlib, random

def get_md5(s):
    return hashlib.md5(s.encode('utf-8')).hexdigest()

class User(object):
    def __init__(self, username, password):
        self.username = username
        # print( chr(random.randint(48,122) ) )
        # print([chr(random.randint(48, 122)) for i in range(20)])
        self.salt = ''.join([chr(random.randint(48, 122)) for i in range(20)])    # 数据库中添加了一个随机盐
        self.password = get_md5(password + self.salt)
db = {
    'michael': User('michael', '123456'),
    'bob': User('bob', 'abc999'),
    'alice': User('alice', 'alice2008')
}


def login(username, password):
    user = db[username]
    # return user.password == get_md5(password)
    return user.password == get_md5(password + user.salt)   # 和上面的对应， + 的顺序不能反


if __name__ == '__main__':
    # 测试:
    assert login('michael', '123456')
    assert login('bob', 'abc999')
    assert login('alice', 'alice2008')
    assert not login('michael', '1234567')
    assert not login('bob', '123456')
    assert not login('alice', 'Alice2008')
    print('ok')
