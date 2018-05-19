#29 MySQL 复制表



1. 另一种完整复制表的方法:

   ```mysql
   CREATE TABLE targetTable LIKE sourceTable;
   INSERT INTO targetTable SELECT * FROM sourceTable;
   ```

   其他:

   可以拷贝一个表中其中的一些字段:

   ```Mysql
   CREATE TABLE newadmin AS
   (
       SELECT username, password FROM admin
   )
   ```

   可以将新建的表的字段改名:

   ```mysql
   CREATE TABLE newadmin AS
   (  
       SELECT id, username AS uname, password AS pass FROM admin
   )
   ```

   可以拷贝一部分数据:

   ```Mysql
   CREATE TABLE newadmin AS
   (
       SELECT * FROM admin WHERE LEFT(username,1) = 's'
   )
   ```

   可以在创建表的同时定义表中的字段信息:

   ```Mysql
   CREATE TABLE newadmin
   (
       id INTEGER NOT NULL AUTO_INCREMENT PRIMARY KEY
   )
   AS
   (
       SELECT * FROM admin
   )  
   ```

   ​

2. ​

   **来给大家区分下mysql复制表的两种方式。**

   **第一、只复制表结构到新表**

   ```mysql
   create table 新表 select * from 旧表 where 1=2
   ```

   或者

   ```mysql
   create table 新表 like 旧表 
   ```

   **第二、复制表结构及数据到新表**

   ```mysql
   create table 新表 select * from 旧表 
   ```

   ​

------

原文： http://www.runoob.com/mysql/mysql-clone-tables.html

如果我们需要完全的复制MySQL的数据表，包括表的结构，索引，默认值等。 如果仅仅使用**CREATE TABLE ... SELECT** 命令，是无法实现的。

本章节将为大家介绍如何**完整的复制MySQL数据**表，步骤如下：

- 使用 **SHOW CREATE TABLE** 命令获取创建数据表(**CREATE TABLE**) 语句，该语句包含了原数据表的结构，索引等。
- 复制以下命令显示的SQL语句，修改数据表名，并执行SQL语句，通过以上命令 将完全的复制数据表结构。
- 如果你想复制表的内容，你就可以使用 **INSERT INTO ... SELECT** 语句来实现。

### 实例

尝试以下实例来复制表 runoob_tbl 。

**步骤一：**

获取数据表的完整结构。

```mysql
mysql> SHOW CREATE TABLE runoob_tbl \G;
*************************** 1. row ***************************
       Table: runoob_tbl
Create Table: CREATE TABLE `runoob_tbl` (
  `runoob_id` int(11) NOT NULL auto_increment,
  `runoob_title` varchar(100) NOT NULL default '',
  `runoob_author` varchar(40) NOT NULL default '',
  `submission_date` date default NULL,
  PRIMARY KEY  (`runoob_id`),
  UNIQUE KEY `AUTHOR_INDEX` (`runoob_author`)
) ENGINE=InnoDB 
1 row in set (0.00 sec)

ERROR:
No query specified
```

**步骤二：**

修改SQL语句的数据表名，并执行SQL语句。

```Mysql
mysql> CREATE TABLE `clone_tbl` (
	 `runoob_id` int(11) NOT NULL auto_increment,
	 `runoob_title` varchar(100) NOT NULL default '',
	 `runoob_author` varchar(40) NOT NULL default '',
	 `submission_date` date default NULL,
	 PRIMARY KEY  (`runoob_id`),
	 UNIQUE KEY `AUTHOR_INDEX` (`runoob_author`)
	 ) ENGINE=InnoDB;
Query OK, 0 rows affected (1.80 sec)
```

**步骤三：**

执行完第二步骤后，你将在数据库中创建新的克隆表 clone_tbl。 如果你**想拷贝数据表的数据**你可以使用 **INSERT INTO... SELECT** 语句来实现。

```Mysql
mysql> INSERT INTO clone_tbl (runoob_id,
	                        runoob_title,
	                        runoob_author,
	                        submission_date)
	 SELECT runoob_id,runoob_title, 
	        runoob_author,submission_date
	 FROM runoob_tbl;
Query OK, 3 rows affected (0.07 sec)
Records: 3  Duplicates: 0  Warnings: 0
```

执行以上步骤后，你将完整的复制表，包括表结构及表数据。

事实上，我上面用的 唯一键【一直到做 唯一 索引用】有重复的。

```mysql
 UNIQUE KEY AUTHOR_INDEX (runoob_author)
```

所以改该表的结构如下：

```mysql
# 先删除该索引
mysql> drop index AUTHOR_INDEX on clone_tbl;
Query OK, 0 rows affected (0.02 sec)
Records: 0  Duplicates: 0  Warnings: 0

# 重新添加 唯一键 为该id
mysql> ALTER TABLE clone_tbl ADD UNIQUE KEY `unique_index`(`runoob_id`);
Query OK, 0 rows affected (0.11 sec)
Records: 0  Duplicates: 0  Warnings: 0

# 复制数据
mysql> INSERT INTO clone_tbl (runoob_id, runoob_title, runoob_author,         submission_date)  
SELECT runoob_id, runoob_title, runoob_author, submission_date 
FROM runoob_tbl;
Query OK, 5 rows affected (0.05 sec)
Records: 5  Duplicates: 0  Warnings: 0
```



