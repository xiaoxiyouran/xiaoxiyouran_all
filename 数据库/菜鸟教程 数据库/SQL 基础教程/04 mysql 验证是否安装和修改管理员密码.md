# 04 mysql 验证是否安装和修改管理员密码



------

原文：http://www.runoob.com/mysql/mysql-install.html

## 是否安装

```mysql
[root@host]# mysqladmin --version
```



## Mysql安装后需要修改密码

Mysql安装成功后，默认的root用户密码为空，你可以使用以下命令来创建root用户的密码：

```
[root@host]# mysqladmin -u root password "new_password";
```

现在你可以通过以下命令来连接到Mysql服务器：

```
[root@host]# mysql -u root -p
Enter password:*******
```

**注意：**在输入密码时，密码是不会显示了，你正确输入即可。

## 查询数据库

```mysql
mysql> SHOW DATABASES;
+----------+
| Database |
+----------+
| mysql    |
| test     |
+----------+
2 rows in set (0.13 sec)
```

