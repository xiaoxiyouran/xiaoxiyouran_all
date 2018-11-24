# 1045 access denied for user root

改完密码发现登录吧不上了。

密码时对的：

```sh
[xi@weekend01 ~]$ mysql -uroot -p
Enter password: 
ERROR 1045 (28000): Access denied for user 'root'@'localhost' (using password: YES)
```

密码正确的情况下，mysql数据库已经禁止了root用户在本地的登录权限了。

　　使用root用户通过主机127.0.0.1登录就可以正常进入mysql，127.0.0.1和localhost对mysql数据库来讲是不同的主机，

```sh
　　[root@228827 ~]# mysql -uroot -p123456 -h 127.0.0.1
```

　　这让我想起**了mysql下的user表**。

　　我们要进mysql看user表，一种方法可以通过上面的命令，如果不行，可以用下面的命令启动数据库，缺省密码进入

```mysql
[root@228827 ~]# /etc/init.d/mysql stop

[root@228827 ~]# /usr/local/mysql/bin/mysqld_safe –skip-grant-tables &

[root@228827 ~]# mysql
Welcome to the MySQL monitor. Commands end with ; or g.
Your MySQL connection id is 1
Server version: 5.1.57 Source distribution
Copyright (c) 2000, 2010, Oracle and/or its affiliates. All rights reserved.
Type 'help;' or 'h' for help. Type 'c' to clear the current input statement.

mysql> use mysql

Database changed

mysql> select user,host,password from user where user='root';
+——+——————-+——————————————-+
| user | host | password |
+——+——————-+——————————————-+
| root | % | *A50E066E106320CF4142 |
| root | centos | *A50E066E106320CF4142 |
| root | 127.0.0.1 | *A50E066E1063608320CF4142 |
+——+——————-+——————————————-+
3 rows in set (0.12 sec)
```

发现user表host字段中没有localhost，但是我的理解是%代表所有的主机都能登录的，为什么localhost不能呢，同样的情况我在5.0.45版的mysql上面做实验就不会发生localhost无法登录，我当前用的是5.1.57版的，难道是版本的问题?

　　接下来的修改很明显了：

代码如下	 

```sh
mysql> update user set host='localhost' where user='root' and host='%';

mysql> flush privileges;
```

　　OK，退出mysql，重启mysql就解决问题了;

最后。我又重新加了一条授权列表： 将`localhost` 的主机名加入 user 表中。 

```sh
mysql> use mysql;
mysql> GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' IDENTIFIED BY 'root' WITH GRANT OPTION;
Query OK, 0 rows affected (0.01 sec)

mysql> flush privileges;
Query OK, 0 rows affected (0.00 sec)

mysql> select user,host,password from user where user='root';
+------+-----------+-------------------------------------------+
| user | host      | password                                  |
+------+-----------+-------------------------------------------+
| root | %         | *81F5E21E35407D884A6CD4A731AEBFB6AF209E1B |
| root | weekend01 | *81F5E21E35407D884A6CD4A731AEBFB6AF209E1B |
| root | 127.0.0.1 | *81F5E21E35407D884A6CD4A731AEBFB6AF209E1B |
| root | localhost | *81F5E21E35407D884A6CD4A731AEBFB6AF209E1B |
+------+-----------+-------------------------------------------+
4 rows in set (0.00 sec)

mysql> quit;
```

<br>

## 参考

1- http://blog.51cto.com/12449902/1893401

