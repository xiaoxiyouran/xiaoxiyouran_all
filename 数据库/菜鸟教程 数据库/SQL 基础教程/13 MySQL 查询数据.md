# 13 MySQL 查询数据

offset 要和 limit 一起用。

原文： https://blog.csdn.net/iastro/article/details/53037600

代码示例:

语句1：select * from student limit 9,4

语句2：slect * from student limit 4 offset 9

// 语句1和2均返回表student的第10、11、12、13行  

//语句2中的4表示返回4行，9表示从表的第十行开始

例2，通过limit和offset 或只通过limit可以实现分页功能。
假设 numberperpage 表示每页要显示的条数，pagenumber表示页码，那么 返回第pagenumber页，每页条数为numberperpage的sql语句：

代码示例:

语句3：select * from studnet limit (pagenumber-1)*numberperpage,numberperpage

语句4：select * from student limit numberperpage offset (pagenumber-1)*numberperpage

------

原文： http://www.runoob.com/mysql/mysql-select-query.html

MySQL 数据库使用SQL SELECT语句来查询数据。

你可以通过 mysql> 命令提示窗口中在数据库中查询数据，或者通过PHP脚本来查询数据。

### 语法

以下为在MySQL数据库中查询数据通用的 SELECT 语法：

```Mysql
SELECT column_name,column_name
FROM table_name
[WHERE Clause]
[LIMIT N][ OFFSET M]
```

- 查询语句中你可以**使用一个或者多个表，表之间使用逗号(,)分割，并使用WHERE语句来设定查询条件**。
- SELECT 命令可以读取一条或者多条记录。
- 你可以使用星号（*）来代替其他字段，SELECT语句会返回表的所有字段数据
- 你可以使用 WHERE 语句来包含任何条件。
- 你可以使用 **LIMIT 属性来设定返回的记录数**。
- 你可以通过**OFFSET指定SELECT语句开始查询的数据偏移量。默认情况下偏移量为0**。

------

## 通过命令提示符获取数据

以下实例我们将通过 SQL SELECT 命令来获取 MySQL 数据表 runoob_tbl 的数据：

### 实例

以下实例将返回数据表 runoob_tbl 的所有记录:

## 读取数据表：

select * from runoob_tbl;

输出结果：

![img](http://www.runoob.com/wp-content/uploads/2014/03/DB742246-84F3-4447-BD43-6BAEADD7CA91.jpg)