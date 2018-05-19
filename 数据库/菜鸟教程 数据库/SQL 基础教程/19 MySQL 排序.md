#19 MySQL 排序



------

原文： http://www.runoob.com/mysql/mysql-order-by.html

我们知道从 MySQL 表中使用 SQL SELECT 语句来读取数据。

如果我们需要对读取的数据**进行排序**，我们就可以使用 MySQL 的 **ORDER BY** 子句来设定你想**按哪个字段哪种方式来进行排序**，再返回搜索结果。

### 语法

以下是 SQL SELECT 语句使用 ORDER BY 子句将查询数据排序后再返回数据：

```Mysql
SELECT field1, field2,...fieldN table_name1, table_name2...
ORDER BY field1, [field2...] [ASC [DESC]]
```

- 你可以**使用任何字段来作为排序的条件**，从而返回排序后的查询结果。
- 你**可以设定多个字段**来排序。
- 你可以使用 **ASC 或 DESC 关键字来设置查询结果是按升序或降序**排列。 **默认情况下，它是按升序排列**。
- 你可以**添加 WHERE...LIKE 子句来设置条件**。

------

## 在命令提示符中使用 ORDER BY 子句

以下将在 SQL SELECT 语句中使用 ORDER BY 子句来读取MySQL 数据表 runoob_tbl 中的数据：

### 实例

尝试以下实例，结果将按升序及降序排列。

## SQL 排序

```Mysql
mysql> use RUNOOB;
Database changed
# 升序排列
mysql> SELECT * from runoob_tbl ORDER BY submission_date ASC;
+-----------+---------------+---------------+-----------------+
| runoob_id | runoob_title  | runoob_author | submission_date |
+-----------+---------------+---------------+-----------------+
| 3         | 学习 Java   | RUNOOB.COM    | 2015-05-01      |
| 4         | 学习 Python | RUNOOB.COM    | 2016-03-06      |
| 1         | 学习 PHP    | 菜鸟教程  | 2017-04-12      |
| 2         | 学习 MySQL  | 菜鸟教程  | 2017-04-12      |
+-----------+---------------+---------------+-----------------+
4 rows in set (0.01 sec)
 
# 降序排列
mysql> SELECT * from runoob_tbl ORDER BY submission_date DESC;
+-----------+---------------+---------------+-----------------+
| runoob_id | runoob_title  | runoob_author | submission_date |
+-----------+---------------+---------------+-----------------+
| 1         | 学习 PHP    | 菜鸟教程  | 2017-04-12      |
| 2         | 学习 MySQL  | 菜鸟教程  | 2017-04-12      |
| 4         | 学习 Python | RUNOOB.COM    | 2016-03-06      |
| 3         | 学习 Java   | RUNOOB.COM    | 2015-05-01      |
+-----------+---------------+---------------+-----------------+
4 rows in set (0.01 sec)
```

读取 runoob_tbl 表中所有数据并按 submission_date 字段的升序排列。