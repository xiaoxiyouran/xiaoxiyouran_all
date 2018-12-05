#06 MySQL 创建数据库

------

我们可以在登陆 MySQL 服务后，使用 creat 命令创建数据库，语法如下:

```Mysql
CREATE DATABASE 数据库名;
```

以下命令简单的演示了创建数据库的过程，数据名为 RUNOOB:

```shell
[root@host]# mysql -u root -p   
Enter password:******  # 登录后进入终端

mysql> create DATABASE RUNOOB;
```

### 使用 mysqladmin 创建数据库

使用普通用户，你可能需要特定的权限来创建或者删除 MySQL 数据库。

所以我们这边使用root用户登录，root用户拥有最高权限，可以使用 mysql mysqladmin 命令来创建数据库。

以下命令简单的演示了创建数据库的过程，数据名为 RUNOOB:

```Shell
[root@host]# mysqladmin -u root -p create RUNOOB
Enter password:******
```

以上命令执行成功后会创建 MySQL 数据库 RUNOOB。

------

## 使用 PHP脚本 创建数据库

PHP 使用 mysqli_query 函数来创建或者删除 MySQL 数据库。

该函数有两个参数，在执行成功时返回 TRUE，否则返回 FALSE。

### 语法

```Php
mysqli_query(connection,query,resultmode);
```

| 参数         | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| *connection* | 必需。规定要使用的 MySQL 连接。                              |
| *query*      | 必需，规定查询字符串。                                       |
| *resultmode* | 可选。一个常量。可以是下列值中的任意一个：MYSQLI_USE_RESULT（如果需要检索大量数据，请使用这个）MYSQLI_STORE_RESULT（默认） |

### 实例

以下实例演示了使用PHP来创建一个数据库：

## 创建数据库

```php
<?php
$dbhost = 'localhost:3306';  // mysql服务器主机地址
$dbuser = 'root';            // mysql用户名
$dbpass = '123456';          // mysql用户名密码
$conn = mysqli_connect($dbhost, $dbuser, $dbpass);
if(! $conn )
{
  die('连接错误: ' . mysqli_error($conn));
}
echo '连接成功<br />';
$sql = 'CREATE DATABASE RUNOOB';
$retval = mysqli_query($conn,$sql );
if(! $retval )
{
    die('创建数据库失败: ' . mysqli_error($conn));
}
echo "数据库 RUNOOB 创建成功\n";
mysqli_close($conn);
?>
```

执行成功后，返回如下结果：

![img](05_01.jpg)

如果数据库已存在，执行后，返回如下结果：

![img](05_02.jpg)



## 1 篇笔记



使用root登录后，可以使用

```Mysql
CREATE DATABASE IF NOT EXISTS RUNOOB DEFAULT CHARSET utf8 COLLATE utf8_general_ci;
```

创建数据库，该命令的作用：

-  1. 如果数据库不存在则创建，存在则不创建。
-  2. 创建RUNOOB数据库，并设定编码集为utf8