#17 MySQL LIKE 子句

1- like 通常和 `%` 一起使用，代替 `=`

------



我们知道在 MySQL 中使用 SQL SELECT 命令来读取数据， 同时我们可以在 SELECT 语句中使用 WHERE 子句来获取指定的记录。

WHERE 子句中可以使用等号 = 来设定获取数据的条件，如 "runoob_author = 'RUNOOB.COM'"。

但是有时候我们需要获取 runoob_author 字段**含有 "COM" 字符的所有记录**，这时我们就需要在 WHERE 子句中使用 SQL LIKE 子句。

SQL LIKE 子句中**使用百分号 %字符来表示任意字符，类似于UNIX或正则表达式中的星号 ***。

如果没有使用百分号 %, LIKE 子句与等号 = 的效果是一样的。

### 语法

以下是 SQL SELECT 语句使用 LIKE 子句从数据表中读取数据的通用语法：

```mysql
SELECT field1, field2,...fieldN 
FROM table_name
WHERE field1 LIKE condition1 [AND [OR]] filed2 = 'somevalue'
```

- 你可以在 WHERE 子句中**指定任何条件。**
- 你可以在 WHERE 子句中**使用LIKE子句**。
- 你可以**使用LIKE子句代替等号 =**。
- **LIKE 通常与 %** 一同使用，类似于一个元字符的搜索。
- 你可以**使用 AND 或者 OR 指定**一个或多个条件。
- 你可以**在 DELETE 或 UPDATE 命令中使用 WHERE...LIKE** 子句来指定条件。

------

## 在命令提示符中使用 LIKE 子句

以下我们将在 SQL SELECT 命令中使用 WHERE...LIKE 子句来从MySQL数据表 runoob_tbl 中读取数据。

### 实例

以下是我们将 runoob_tbl 表中获取 runoob_author 字段中以 COM 为结尾的的所有记录：

```shell
mysql> use RUNOOB;
Database changed
mysql> SELECT * from runoob_tbl  WHERE runoob_author LIKE '%COM';
+-----------+---------------+---------------+-----------------+
| runoob_id | runoob_title  | runoob_author | submission_date |
+-----------+---------------+---------------+-----------------+
| 3         | 学习 Java   | RUNOOB.COM    | 2015-05-01      |
| 4         | 学习 Python | RUNOOB.COM    | 2016-03-06      |
+-----------+---------------+---------------+-----------------+
2 rows in set (0.01 sec)
```

