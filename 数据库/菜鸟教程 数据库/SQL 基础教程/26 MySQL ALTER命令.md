#26 MySQL ALTER命令

1- 修改表的结构，如 表的名字，表的字段

alter其他用途：

修改存储引擎：修改为myisam

```Mysql
alter table tableName engine=myisam;
```

删除外键约束：keyName是外键别名

```mysql
alter table tableName drop foreign key keyName;
```

修改字段的相对位置：这里name1为想要修改的字段，type1为该字段原来类型，first和after二选一，这应该显而易见，first放在第一位，after放在name2字段后面

```mysql
alter table tableName modify name1 type1 first|after name2;
```



------

原文：http://www.runoob.com/mysql/mysql-alter.html

当我们需要**修改数据表名或者修改数据表字段**时，就需要使用到MySQL ALTER命令。

开始本章教程前让我们先创建一张表，表名为：testalter_tbl。

```mysql
root@host# mysql -u root -p password;
Enter password:*******
mysql> use RUNOOB;
Database changed
mysql> create table testalter_tbl
    -> (
    -> i INT,
    -> c CHAR(1)
    -> );
Query OK, 0 rows affected (0.05 sec)
mysql> SHOW COLUMNS FROM testalter_tbl;  # 显示表的结构
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| i     | int(11) | YES  |     | NULL    |       |
| c     | char(1) | YES  |     | NULL    |       |
+-------+---------+------+-----+---------+-------+
2 rows in set (0.00 sec)
```

------

## 删除，添加或修改表字段

如下命令使用了 ALTER 命令及 DROP 子句来删除以上创建表的 i 字段：

```mysql
mysql> ALTER TABLE testalter_tbl  DROP i;
```

如果数据表中**只剩余一个字段则无法使用DROP来删除字段**。

MySQL 中使用 **ADD 子句来向数据表中添加列**，如下实例在表 testalter_tbl 中添加 i 字段，并定义数据类型:

```Mysql
mysql> ALTER TABLE testalter_tbl ADD i INT;
```

执行以上命令后，i 字段会自动添加到数据表字段的末尾。

```Mysql
mysql> SHOW COLUMNS FROM testalter_tbl;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| c     | char(1) | YES  |     | NULL    |       |
| i     | int(11) | YES  |     | NULL    |       |
+-------+---------+------+-----+---------+-------+
2 rows in set (0.00 sec)
```

如果你需要指定新增字段的位置，可以使用MySQL提供的关键字 FIRST (设定位第一列)， AFTER 字段名（设定位于某个字段之后）。

尝试以下 ALTER TABLE 语句, 在执行成功后，使用 SHOW COLUMNS 查看表结构的变化：

```Mysql
ALTER TABLE testalter_tbl DROP i;
mysql> SHOW COLUMNS FROM testalter_tbl;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| c     | char(1) | YES  |     | NULL    |       |
+-------+---------+------+-----+---------+-------+
1 row in set (0.00 sec)

# FIRST 字段会指定字段的位置
ALTER TABLE testalter_tbl ADD i INT FIRST;
mysql> SHOW COLUMNS FROM testalter_tbl;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| i     | int(11) | YES  |     | NULL    |       |
| c     | char(1) | YES  |     | NULL    |       |
+-------+---------+------+-----+---------+-------+
2 rows in set (0.00 sec)


ALTER TABLE testalter_tbl DROP i;
mysql> SHOW COLUMNS FROM testalter_tbl;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| c     | char(1) | YES  |     | NULL    |       |
+-------+---------+------+-----+---------+-------+
1 row in set (0.00 sec)

# i 字段现在 在 c 之后
ALTER TABLE testalter_tbl ADD i INT AFTER c;
mysql> SHOW COLUMNS FROM testalter_tbl;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| c     | char(1) | YES  |     | NULL    |       |
| i     | int(11) | YES  |     | NULL    |       |
+-------+---------+------+-----+---------+-------+
2 rows in set (0.00 sec)
```

FIRST 和 AFTER 关键字只占用于 ADD 子句，所以如果你想重置数据表字段的位置就需要先使用 DROP 删除字段然后使用 ADD 来添加字段并设置位置。

------

## 修改字段类型及名称

如果需**要修改字段类型及名称**, 你可以在ALTER命令中**使用 MODIFY 或 CHANGE 子句** 。

例如，把字段 c 的类型从 CHAR(1) 改为 CHAR(10)，可以执行以下命令:

```mysql
mysql> ALTER TABLE testalter_tbl MODIFY c CHAR(10);

mysql> SHOW COLUMNS FROM testalter_tbl;
+-------+----------+------+-----+---------+-------+
| Field | Type     | Null | Key | Default | Extra |
+-------+----------+------+-----+---------+-------+
| c     | char(10) | YES  |     | NULL    |       |
| i     | int(11)  | YES  |     | NULL    |       |
+-------+----------+------+-----+---------+-------+
2 rows in set (0.00 sec)
```

使用 CHANGE 子句, 语法有很大的不同。 在 **CHANGE 关键字之后，紧跟着的是你要修改的字段名，然后指定新字段名及类型**。尝试如下实例：

```Mysql
mysql> ALTER TABLE testalter_tbl CHANGE i j BIGINT;
mysql> SHOW COLUMNS FROM testalter_tbl;
+-------+------------+------+-----+---------+-------+
| Field | Type       | Null | Key | Default | Extra |
+-------+------------+------+-----+---------+-------+
| c     | char(10)   | YES  |     | NULL    |       |
| j     | bigint(20) | YES  |     | NULL    |       |
+-------+------------+------+-----+---------+-------+
2 rows in set (0.00 sec)
```



```Mysql
mysql> ALTER TABLE testalter_tbl CHANGE j j INT;
mysql> SHOW COLUMNS FROM testalter_tbl;
+-------+----------+------+-----+---------+-------+
| Field | Type     | Null | Key | Default | Extra |
+-------+----------+------+-----+---------+-------+
| c     | char(10) | YES  |     | NULL    |       |
| j     | int(11)  | YES  |     | NULL    |       |
+-------+----------+------+-----+---------+-------+
2 rows in set (0.00 sec)
```



## ALTER TABLE 对 Null 值和默认值的影响

当你修改字段时，你可以指定是否包含值或者是否设置默认值。

以下实例，指定字段 j 为 NOT NULL 且默认值为100 。

```mysql
mysql> ALTER TABLE testalter_tbl 
    -> MODIFY j BIGINT NOT NULL DEFAULT 100;
```

如果你不设置默认值，MySQL会自动设置该字段默认为 NULL。



## 修改字段默认值

你可以使用 ALTER 来修改字段的默认值，尝试以下实例：

```mysql
mysql> ALTER TABLE testalter_tbl CHANGE j i  INT;  	# 先把 j 改为 i
mysql> ALTER TABLE testalter_tbl ALTER i SET DEFAULT 1000;
mysql> SHOW COLUMNS FROM testalter_tbl;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| c     | char(1) | YES  |     | NULL    |       |
| i     | int(11) | YES  |     | 1000    |       |
+-------+---------+------+-----+---------+-------+
2 rows in set (0.00 sec
```



## 删除字段的默认值

你也可以使用 ALTER 命令及 DROP子句来删除字段的默认值，如下实例：

```mysql
mysql> ALTER TABLE testalter_tbl ALTER i DROP DEFAULT;
mysql> SHOW COLUMNS FROM testalter_tbl;
+-------+---------+------+-----+---------+-------+
| Field | Type    | Null | Key | Default | Extra |
+-------+---------+------+-----+---------+-------+
| c     | char(1) | YES  |     | NULL    |       |
| i     | int(11) | YES  |     | NULL    |       |
+-------+---------+------+-----+---------+-------+
2 rows in set (0.00 sec)
Changing a Table Type:
```



## 修改表的引擎

修改数据表类型，可以**使用 ALTER 命令及 TYPE 子句来完成**。尝试以下实例，我们将表 testalter_tbl 的类型修改为 MYISAM ：

**注意：**查看数据表类型可以使用 **SHOW TABLE STATUS** 语句。

```mysql
mysql> ALTER TABLE testalter_tbl ENGINE = MYISAM;
mysql>  SHOW TABLE STATUS LIKE 'testalter_tbl'\G
*************************** 1. row ****************
           Name: testalter_tbl
           Type: MyISAM
     Row_format: Fixed
           Rows: 0
 Avg_row_length: 0
    Data_length: 0
Max_data_length: 25769803775
   Index_length: 1024
      Data_free: 0
 Auto_increment: NULL
    Create_time: 2007-06-03 08:04:36
    Update_time: 2007-06-03 08:04:36
     Check_time: NULL
 Create_options:
        Comment:
1 row in set (0.00 sec)
```



## 修改表名

如果需要修改数据表的名称，可以在 ALTER TABLE 语句中使**用 RENAME 子句**来实现。

尝试以下实例将数据表 testalter_tbl 重命名为 alter_tbl：

```mysql
mysql> ALTER TABLE testalter_tbl RENAME TO alter_tbl;
```

ALTER 命令还可以用来**创建及删除MySQL数据表的索引**，该功能我们会在接下来的章节中介绍。













