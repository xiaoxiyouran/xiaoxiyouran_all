# mysql 修改密码

5. 输入use mysql; （连接权限数据库）。
6. 改密码：update user set password=password("123") where user="root";（别忘了最后加分号） 。
7. 刷新权限（必须步骤）：flush privileges;　。 
8. 退出 quit。 

