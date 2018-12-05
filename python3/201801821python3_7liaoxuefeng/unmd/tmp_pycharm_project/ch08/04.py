#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch08/04.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'


class Field(object):
    # 保存数据库表的字段名和字段类型
    def __init__(self, name, column_type):
        self.name = name
        self.column_type = column_type

    def __str__(self):
        return '<%s:%s>' % (self.__class__.__name__, self.name)


class StringField(Field):
    '''
    继承自 Field
    '''
    def __init__(self, name):
        super(StringField, self).__init__(name, 'varchar(100)')

class IntegerField(Field):
    '''
    继承自Field
    '''
    def __init__(self, name):
        super(IntegerField, self).__init__(name, 'bigint')


class ModelMetaclass(type):
    '''
    元类 继承自 type
    '''
    def __new__(cls, name, bases, attrs):
        if name=='Model':                   # 排除掉对 Model 类的修改
            return type.__new__(cls, name, bases, attrs)

        print('Found model: %s' % name)

        mappings = dict()
        for k, v in attrs.items():  # 找到想要的属性
            if isinstance(v, Field):
                print('Found mapping: %s ==> %s' % (k, v))
                mappings[k] = v

        for k in mappings.keys():   # 将这些属性弹出
            attrs.pop(k)


        attrs['__mappings__'] = mappings    # 保存属性和列的映射关系， 将属性用 __mapping__ 字典包装， 放回
        attrs['__table__'] = name           # 假设表名和类名一致， 新添加的表名属性
        return type.__new__(cls, name, bases, attrs)        # 重新创建类


class Model(dict, metaclass=ModelMetaclass):
    '''
    用户的基类
    '''
    def __init__(self, **kw):
        super(Model, self).__init__(**kw)

    def __getattr__(self, key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"'Model' object has no attribute '%s'" % key)

    def __setattr__(self, key, value):
        self[key] = value

    def save(self):
        fields = []
        params = []
        args = []
        for k, v in self.__mappings__.items():              # 在元类中， 这些属性被重新放进了 __mappings__ 列表中
            fields.append(v.name)
            params.append('?')
            args.append(getattr(self, k, None))
        sql = 'insert into %s (%s) values (%s)' % (self.__table__, ','.join(fields), ','.join(params))
        print('SQL: %s' % sql)
        print('ARGS: %s' % str(args))

class User(Model):
    # 定义类的属性到列的映射：
    id = IntegerField('id')
    name = StringField('username')
    email = StringField('email')
    password = StringField('password')



if __name__ == '__main__':
    # 测试:
    # 创建一个实例：
    u = User(id=12345, name='Michael', email='test@orm.org', password='my-pwd')
    # 保存到数据库：
    u.save()


# Found model: User
# Found mapping: email ==> <StringField:email>
# Found mapping: id ==> <IntegerField:id>
# Found mapping: password ==> <StringField:password>
# Found mapping: name ==> <StringField:username>
# SQL: insert into User (email,id,password,username) values (?,?,?,?)
# ARGS: ['test@orm.org', 12345, 'my-pwd', 'Michael']
