#30 MySQL 序列使用



------

原文： http://www.runoob.com/mysql/mysql-using-sequences.html

MySQL序列是一组整数：1, 2, 3, ...，由于一张数据表**只能有一个字段自增主键**， 如果你想实现其他字段也实现自动增加，就可以**使用MySQL序列**来实现。

本章我们将介绍如何使用MySQL的序列。

------

## 使用AUTO_INCREMENT

MySQL中最简单使用序列的方法就是使用 MySQL **AUTO_INCREMENT 来定义列**。

### 实例

以下实例中创建了数据表insect， insect中id无需指定值可实现自动增长

```mysql
mysql> CREATE TABLE insect
	 (
	 id INT UNSIGNED NOT NULL AUTO_INCREMENT,
	 PRIMARY KEY (id),
	 name VARCHAR(30) NOT NULL, # type of insect
	 date DATE NOT NULL, # date collected
	 origin VARCHAR(30) NOT NULL # where collected
);
Query OK, 0 rows affected (0.02 sec)

mysql> INSERT INTO insect (id,name,date,origin) VALUES
	 (NULL,'housefly','2001-09-10','kitchen'),
	 (NULL,'millipede','2001-09-10','driveway'),
	 (NULL,'grasshopper','2001-09-10','front yard');
Query OK, 3 rows affected (0.02 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM insect ORDER BY id;
+----+-------------+------------+------------+
| id | name        | date       | origin     |
+----+-------------+------------+------------+
|  1 | housefly    | 2001-09-10 | kitchen    |
|  2 | millipede   | 2001-09-10 | driveway   |
|  3 | grasshopper | 2001-09-10 | front yard |
+----+-------------+------------+------------+
3 rows in set (0.00 sec)
```



## 获取AUTO_INCREMENT值

在MySQL的客户端中你可以使用 SQL中的LAST_INSERT_ID( ) 函数来获取最后的插入表中的自增列的值。

```mysql
mysql> select LAST_INSERT_ID( ) from insect;
+-------------------+
| LAST_INSERT_ID( ) |
+-------------------+
|                 1 |
|                 1 |
|                 1 |
+-------------------+
3 rows in set (0.00 sec)
```



## 重置序列

如果你删除了数据表中的多条记录，并希望对剩下数据的AUTO_INCREMENT列进行重新排列，那么你可以通过删除自增的列，然后重新添加来实现。 不过该操作要非常小心，如果在删除的同时又有新记录添加，有可能会出现数据混乱。操作如下所示：

```Mysql
mysql> ALTER TABLE insect DROP id;
mysql> ALTER TABLE insect
	 ADD id INT UNSIGNED NOT NULL AUTO_INCREMENT FIRST,
	 ADD PRIMARY KEY (id);
```

------

## 设置序列的开始值

一般情况下序列的开始值为1，但如果你需要指定一个开始值100，那我们可以通过以下语句来实现：

```Mysql
mysql> CREATE TABLE insect
	 (
	 id INT UNSIGNED NOT NULL AUTO_INCREMENT,
	 PRIMARY KEY (id),
	 name VARCHAR(30) NOT NULL, 
	 date DATE NOT NULL,
	 origin VARCHAR(30) NOT NULL
)engine=innodb auto_increment=100 charset=utf8;
```

或者你也可以在表创建成功后，通过以下语句来实现：

```Mysql
mysql> ALTER TABLE t AUTO_INCREMENT = 100;
```