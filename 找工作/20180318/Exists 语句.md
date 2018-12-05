#Exists 语句

## 准备数据

我们先介绍下使用的3个数据表：

student数据表：

![img](http://img.blog.csdn.net/20131009201837390?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXN5emI=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

course数据表：

![img](http://img.blog.csdn.net/20131009201858468?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXN5emI=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

sc数据表：

![img](http://img.blog.csdn.net/20131009201927171?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXN5emI=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## EXISTS

EXISTS代表存在量词∃。带有EXISTS谓词的子查询不返回任何数据，只产生逻辑真值“true”或者逻辑假值“false”。

一个例子1.1：

要求：查询选修了课程”操作系统“的同学

SQL语句：

```mysql
SELECT Sname FROM student
WHERE EXISTS
(SELECT * FROM sc,course WHERE Sno=student.Sno AND sc.Cno=course.Cno AND course.Cname="操作系统")
```

 使用存在量词EXISTS后，若内层查询结果为非空，则外层的WHERE子句返回值为真，否则返回值为假。

在本例中，首先分析最内层的语句：

```mysql
SELECT * FROM sc,course WHERE Sno=student.Sno AND sc.Cno=course.Cno AND course.Cname="操作系统"  
```

本例中的子查询的查询条件依赖于外层父查询的某个属性值（本例中的是Student的Sno值），这个相关子查询的处理过程是：

首先取外层查询中（student）表的第一个元组，根据它与内层查询相关的属性值（Sno值）处理内层查询，若外层的WHERE返回为真，则取外层查询中该元组的Sname放入结果表；

然后再取（student）表的下一组，重复这一过程，直至外层（Student）表全部检查完毕。

查询结果表：

![img](http://img.blog.csdn.net/20131009203613625?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXN5emI=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## NOT EXISTS

与EXISTS谓词相对的是NOT EXISTS谓词。使用存在量词NOT EXISTS后，若对应查询结果为空，则外层的WHERE子语句返回值为真值，否则返回假值。

例子2.1：
要求：查询没有选修课程”操作系统“的同学

SQL语句：

```mysql
SELECT Sname FROM student
WHERE NOT EXISTS
(SELECT * FROM sc,course WHERE Sno=student.Sno AND sc.Cno=course.Cno AND course.Cname="操作系统")
```

使用NOT EXISTS之后，若内层查询结果为非空，则对应的NOT EXISTS不成立，所以对应的WHERE语句也不成立。

在例子1.1中李勇同学对应的记录符合内层的select语句的，所以返回该记录数据，但是对应的NOT EXISTS不成立，WHERE语句也不成立，表示这不是我们要查询的数据。

查询结果表：

![img](http://img.blog.csdn.net/20131009205823343?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXN5emI=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

例子2.2（这是一个用NOT EXISTS表示全称量词的例子）：

要求：查询选修了全部课程的学生姓名。

SQL语句：

```mysql
SELECT Sname  
FROM Student   
WHERE NOT EXISTS  
(SELECT * FROM Course WHERE NOT EXISTS  
     (SELECT * FROM SC WHERE Sno=Student.Sno AND Cno=Course.Cno)  
);  
```

这个算是一个比较复杂的sql语句了，两个EXISTS和三个WHERE。

这个sql语句可以分为3层，最外层语句，最内层语句，中间层语句。

我们很关心最外层语句，因为结果表中的数据都是最外层的查询的表中的数据，我们更关心最内层的数据，因为最内层的数据包含了全部的判断语句，决定了student表中的那一条记录是我们查询的记录。

我们由内而外进行分析：

最外层的student表中的第一条记录是李勇同学对应的记录，然后中间层的course表的第一条记录是数据库对应的记录，然后对该数据进行判断（最内层的WHERE语句），结果返回真，则内层的NOT EXISTS为假，

然后继续对course表中的下一条记录进行判断，返现NOT EXISTS的值也为假，直到遍历完course表中的所有的数据，内层的NOT EXISTS的值一直都是假，所以中间层的WHERE语句的值也一直都是假。

对应student的李勇记录，course表中的所有的记录对应的中间层的返回值为假，所以最外层的NOT EXISTS对应的值为真，最外层的WHERE的值也为真，则李勇对应的记录符合查询条件，装入结果表中。

然后继续对student表中的下一条记录进行判断，直达student表中的所有数据都遍历完毕。

查询结果表：

![img](http://img.blog.csdn.net/20131009203613625?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXN5emI=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)