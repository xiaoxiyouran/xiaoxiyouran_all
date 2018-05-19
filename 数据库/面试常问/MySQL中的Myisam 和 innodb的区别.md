# MySQL中的Myisam 和 innodb的区别

```cpp
1- MyIsam不支持事务操作，外键以及行级锁，而InnoDB支持这些功能
2- MyIsam 读更快； InnoDB 不保存行数
3- InnoDB执行Drop from table 时，不会重新建表，而是一行一行删除。

4- 如果执行大量的select操作选择MyIsam，如果有大量的insert和update操作，选择InnoDB。

5- AUTO_INCREMENT： 对于AUTO_INCREMENT类型的字段，InnoDB中必须包含只有该字段的索引，但是在MyISAM表中，可以和其他字段一起建立联合索引

6- InnoDB的存储方式是一个表空间数据文件，一个日志文件，
	而MyIsam的存储方式是索引文件（.MYI（myindex）），数据文件(.MYD(mydata))，表存储定义文件(.frm)
```



### Myisam与InnoDB的区别：

- 最主要的一点是MyIsam不支持事务操作，外键以及行级锁，而InnoDB支持这些功能。MyIsam只支持表级锁，当多线程并发操作数据库时，就会为整个表上锁，而InnoDB 则从行上锁。但这也是不一定的，如果一个SQL语句不能确定扫描范围的话，也会为整个表上锁，比如： update table set num=1 where name like “%aaa%”
- 但是MyIsam的读的速度比InnoDB**更加快一些，InnoDB不保存表的行数**，比如要执行count(*)的话，它就会扫描整个表，但是如果是MyIsam的话，直接返回行数
- InnoDB执行Drop from table 时，不会重新建表，而是一行一行删除。如果执行大量的select操作选择MyIsam，如果有大量的insert和update操作，选择InnoDB。
- **AUTO_INCREMENT： 对于AUTO_INCREMENT类型的字段，InnoDB中必须包含只有该字段的索引，但是在MyISAM表中，可以和其他字段一起建立联合索引**
- 表的存储方面：InnoDB的存储方式是一个表空间数据文件，一个日志文件，而MyIsam的存储方式是索引文件（.MYI（myindex）），数据文件(.MYD(mydata))，表存储定义文件(.frm)