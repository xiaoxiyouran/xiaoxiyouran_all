# 23 MySQL NULL 值处理

1- MySQL 中**处理 NULL 使用 IS NULL 和 IS NOT NULL 运算符。**



------

原文： http://www.runoob.com/mysql/mysql-null.html

我们已经知道 MySQL 使用 SQL SELECT 命令及 WHERE 子句来读取数据表中的数据,但是**当提供的查询条件字段为 NULL 时**，该命令可能就无法正常工作。

为了处理这种情况，MySQL提供了三大运算符:

- **IS NULL:** 当列的值是 NULL,此运算符返回 true。
- **IS NOT NULL:** 当列的值不为 NULL, 运算符返回 true。
- **<=>:** 比较操作符（不同于=运算符），当比较的的两个值为 NULL 时返回 true。

关于 NULL 的条件比较运算是比较特殊的。你**不能使用 = NULL 或 != NULL 在列中查找 NULL 值** 。

在 MySQL 中，**NULL 值与任何其它值的比较（即使是 NULL）永远返回 false，即 NULL = NULL 返回false 。**

MySQL 中**处理 NULL 使用 IS NULL 和 IS NOT NULL 运算符。**

------

## 在命令提示符中使用 NULL 值

以下实例中假设数据库 RUNOOB 中的表 runoob_test_tbl 含有两列 runoob_author 和 runoob_count, runoob_count 中设置插入NULL值。

### 实例

尝试以下实例:

```mysql
# 创建数据表 runoob_test_tbl

root@host# mysql -u root -p password;
Enter password:*******
mysql> use RUNOOB;
Database changed
mysql> create table runoob_test_tbl
	(
	runoob_author varchar(40) NOT NULL,
	runoob_count  INT
	);
Query OK, 0 rows affected (0.05 sec)
mysql> INSERT INTO runoob_test_tbl (runoob_author, runoob_count) values ('RUNOOB', 20);
mysql> INSERT INTO runoob_test_tbl (runoob_author, runoob_count) values ('菜鸟教程', NULL);
mysql> INSERT INTO runoob_test_tbl (runoob_author, runoob_count) values ('Google', NULL);
mysql> INSERT INTO runoob_test_tbl (runoob_author, runoob_count) values ('FK', 20);
 
mysql> SELECT * from runoob_test_tbl;
+---------------+--------------+
| runoob_author | runoob_count |
+---------------+--------------+
| RUNOOB        | 20           |
| 菜鸟教程  | NULL         |
| Google        | NULL         |
| FK            | 20           |
+---------------+--------------+
4 rows in set (0.01 sec)
```

以下实例中你可以看到 = 和 != 运算符是不起作用的：

```mysql
mysql> SELECT * FROM runoob_test_tbl WHERE runoob_count = NULL;
Empty set (0.00 sec)
mysql> SELECT * FROM runoob_test_tbl WHERE runoob_count != NULL;
Empty set (0.01 sec)
```

查找数据表中 runoob_test_tbl 列是否为 NULL，必须使用 **IS NULL** 和 **IS NOT NULL**，如下实例：

```mysql
mysql> SELECT * FROM runoob_test_tbl WHERE runoob_count IS NULL;
+---------------+--------------+
| runoob_author | runoob_count |
+---------------+--------------+
| 菜鸟教程  | NULL         |
| Google        | NULL         |
+---------------+--------------+
2 rows in set (0.01 sec)
 
mysql> SELECT * from runoob_test_tbl WHERE runoob_count IS NOT NULL;
+---------------+--------------+
| runoob_author | runoob_count |
+---------------+--------------+
| RUNOOB        | 20           |
| FK            | 20           |
+---------------+--------------+
2 rows in set (0.01 sec)
```







