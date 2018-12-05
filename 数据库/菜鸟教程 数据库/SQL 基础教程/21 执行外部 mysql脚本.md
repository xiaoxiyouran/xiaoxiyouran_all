#21 执行外部 mysql脚本

具体的一个sql 文件脚本的例子，详见 `20.sql` 文件

------

原文： https://blog.csdn.net/vebasan/article/details/7619911

sql脚本是包含一到多个sql命令的sql语句，我们可以将这些sql脚本放在一个文本文件中（我们称之为“sql脚本文件”），然后通过相关的命令执行这个sql脚本文件。基本步骤如下：
**1、创建包含sql命令的sql脚本文件**文件中包含一些列的sql语句，每条语句最后以;结尾，文件内容示例如下：
--创建表，使用“--”进行注释

```mysql
create table 表名称
(                   
  Guid Varchar(38) not null primary key,  
  Title Varchar(255),       
) TYPE=InnoDB;

```

--在表A中增加字段Status

```mysql
alter table A add Status TinyInt default '0';
```

--在表A上创建索引

```mysql
create index XX_TaskId_1 on A(Id_);
```

--在A表中添加一条记录

```mysql
Insert into A (Id,ParentId, Name) values(1,0,'名称');
```

--添加、修改、删除数据后，有可能需要提交事务

```mysql
Commit;
```

**2、执行sql脚本文件方法一** 使用cmd命令执行(windows下，unix或linux在的其控制台下)
【Mysql的bin目录】\mysql –u用户名 –p密码 –D数据库<【sql脚本文件路径全名】，示例：

```mysql
D:\mysql\bin\mysql –uroot –p123456 -Dtest<d:\test\ss.sql
```

注意：
A、如果在sql脚本文件中使用了use 数据库，则-D数据库选项可以忽略
B、如果【Mysql的bin目录】中包含空格，则需要使用“”包含，如：“C:\Program Files\mysql\bin\mysql” –u用户名 –p密码 –D数据库<【sql脚本文件路径全名】
**方法二** 进入mysql的控制台后，使用source命令执行
Mysql>source 【sql脚本文件的路径全名】 或 Mysql>\. 【sql脚本文件的路径全名】，示例：

```mysql
mysql -uroot -p;
use RUNOOB;		# 可以看到上面，脚本都是在某个数据库下添加的，所以，最好是先进入某个数据库。然后在这下面操作；
source d:\test\ss.sql 或者 . d:\test\ss.sql
```

