#34 MySQL 导入数据



------

原文：http://www.runoob.com/mysql/mysql-database-import.html

MySQL中可以使用两种简单的方式来导入MySQL导出的数据。

------

## 使用 LOAD DATA 导入数据

MySQL 中提供了LOAD DATA INFILE语句来插入数据。 以下实例中将从当前目录中读取文件 dump.txt ，将该文件中的数据插入到当前数据库的 mytbl 表中。

```Mysql
mysql> LOAD DATA LOCAL INFILE 'dump.txt' INTO TABLE mytbl;
```

　如果指定LOCAL关键词，则表明**从客户主机上按路径读取文件**。如果没有指定，则文件在服务器上按路径读取文件。

你能明确地在LOAD DATA语句中指出列值的分隔符和行尾标记，但是默认标记是定位符和换行符。

两个命令的 FIELDS 和 LINES 子句的语法是一样的。两个子句都是可选的，但是如果两个同时被指定，**FIELDS 子句必须出现在 LINES 子句之前。**

如果用户指定一个 FIELDS 子句，它的子句 （TERMINATED BY、[OPTIONALLY] ENCLOSED BY 和 ESCAPED BY) 也是可选的，不过，用户**必须至少指定它们中的一个。**

```Mysql
mysql> LOAD DATA LOCAL INFILE 'dump.txt' INTO TABLE mytbl
	 FIELDS TERMINATED BY ':'
	 LINES TERMINATED BY '\r\n';
```

LOAD DATA 默认情况下是按照数据文件中列的顺序插入数据的，**如果数据文件中的列与插入表中的列不一致，则需要指定列的顺序。**

如，在数据文件中的列顺序是 a,b,c，但在插入表的列顺序为b,c,a，则数据导入语法如下：

```
mysql> LOAD DATA LOCAL INFILE 'dump.txt' 
	 INTO TABLE mytbl (b, c, a);
```

------

## 使用 mysqlimport 导入数据

mysqlimport客户端提供了LOAD DATA INFILEQL语句的一个命令行接口。mysqlimport的大多数选项直接对应LOAD DATA INFILE子句。

从文件 dump.txt 中将数据导入到 mytbl 数据表中, 可以使用以下命令：

```shell
$ mysqlimport -u root -p --local database_name dump.txt
password *****
```

mysqlimport命令可以指定选项来设置指定格式,命令语句格式如下：

```Shell
$ mysqlimport -u root -p --local --fields-terminated-by=":" \
   --lines-terminated-by="\r\n"  database_name dump.txt
password *****
```

mysqlimport 语句中使用 --columns 选项来设置列的顺序：

```shell
$ mysqlimport -u root -p --local --columns=b,c,a \
    database_name dump.txt
password *****
```

------

## mysqlimport的常用选项介绍

| 选项                         | 功能                                                         |
| ---------------------------- | ------------------------------------------------------------ |
| -d or --delete               | 新数据导入数据表中之前删除数据数据表中的所有信息             |
| -f or --force                | 不管是否遇到错误，mysqlimport将强制继续插入数据              |
| -i or --ignore               | mysqlimport跳过或者忽略那些有相同唯一 关键字的行， 导入文件中的数据将被忽略。 |
| -l or -lock-tables           | 数据被插入之前锁住表，这样就防止了， 你在更新数据库时，用户的查询和更新受到影响。 |
| -r or -replace               | 这个选项与－i选项的作用相反；此选项将替代 表中有相同唯一关键字的记录。 |
| --fields-enclosed- by= char  | 指定文本文件中数据的记录时以什么括起的， 很多情况下 数据以双引号括起。 默认的情况下数据是没有被字符括起的。 |
| --fields-terminated- by=char | 指定各个数据的值之间的分隔符，在句号分隔的文件中， 分隔符是句号。您可以用此选项指定数据之间的分隔符。 默认的分隔符是跳格符（Tab） |
| --lines-terminated- by=str   | 此选项指定文本文件中行与行之间数据的分隔字符串 或者字符。 默认的情况下mysqlimport以newline为行分隔符。 您可以选择用一个字符串来替代一个单个的字符： 一个新行或者一个回车。 |

mysqlimport命令常用的选项还有**-v 显示版本**（version）， **-p 提示输入密码**（password）等。