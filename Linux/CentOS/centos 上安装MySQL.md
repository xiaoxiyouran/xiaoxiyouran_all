# centos 上安装MySQL

## 安装

刚开始用root 身份安装会省去很多麻烦。

1- 查看当前系统是否安装了MySQL 组件

```sh
#这个命令就会查看该操作系统上是否已经安装了mysql数据库
#如果发现有安装组件则需要先进行卸载，才能进行下一步安装，下面是卸载命令。注意：如果在进行卸载时，提示：*package mysql is not installea* 则说明系统中已经没有MySQL 组件，直接进行下一步安装即可
[root@lichis ~] rpm -qa | grep mysql　　

#普通删除模式
[root@lichis ~]# rpm -e mysql　　

#强力删除模式，如果使用上面命令删除时，提示有依赖的其它文件，则用该命令可以对其进行强力删除
[root@lichis ~]# rpm -e --nodeps mysql　　
```

2- 通过 yum 指令进安装 MySQL

```sh
#查询 yum 上提供的  MySQL  的版本信息
root@lichis ~]# yum list | grep mysql
```

3- 安装 MySQL

```sh
[root@lichis ~]# yum install -y mysql-server mysql mysql-deve
```

4- 最后提示 Complete ！ 则表示安装成功了

```sh
[root@liang ~]# rpm -qi mysql-server
```

5- mysql数据库的初始化及相关配置

1 . 启动 MySQL 服务，提示 Starting mysqld: [OK] 即表示服务启动成功！

```sh
[root@lichis ~]# service mysqld start
```

<br>

## 无法启动

启动不了：

```sh
[xi@weekend01 hive-0.12.0]$ sudo chown -R xi /var/lib/mysql
[xi@weekend01 hive-0.12.0]$ cd /var/lib

[xi@weekend01 lib]$ ll
total 144
drwxr-xr-x. 2 root    root    4096 Oct 29 07:45 alternatives
drwx------. 3 root    root    4096 Oct 27 07:52 authconfig
drwxr-xr-x. 2 root    root    4096 Sep 12  2017 bluetooth
drwx------. 2 apache  apache  4096 Jun 19 08:45 dav
drwxr-xr-x. 2 root    root    4096 Oct 27 07:54 dbus
drwxr-xr-x. 2 root    root    4096 Sep 23  2011 DeviceKit-power
drwxr-xr-x. 2 root    root    4096 Nov 10 11:26 dhclient
drwxr-xr-x. 2 root    root    4096 Oct  2  2017 dnsmasq
drwxr-xr-x. 2 root    root    4096 Mar 10  2015 fprint
drwxr-xr-x. 2 root    root    4096 Sep 23  2011 games
drwxrwx--T. 9 gdm     gdm     4096 Nov 10 11:27 gdm
-rw-r--r--. 1 root    root     512 Nov 11 03:48 logrotate.status
drwxr-xr-x. 2 root    root    4096 Oct 27 07:54 misc
drwxr-x---. 2 root    slocate 4096 Mar 12  2015 mlocate
d-wx--x--x. 2 xi      mysql   4096 Jan 26  2017 mysql	 # 用户组原来是 MySQL， MySQL
drwxr-xr-x. 2 root    root    4096 Mar 22  2017 net-snmp
drwxr-xr-x. 2 root    root    4096 Nov 11 09:16 NetworkManager
drwxr-xr-x. 2 ntp     ntp     4096 Jan 25  2018 ntp
drwxr-xr-x. 2 root    root    4096 Nov 11 09:05 PackageKit
drwxr-xr-x. 2 root    root    4096 Oct 27 07:45 plymouth
drwx------. 3 root    root    4096 Oct 27 07:44 polkit-1
drwx------. 2 postfix root    4096 Oct 27 07:54 postfix
drwxr-xr-x. 2 root    root    4096 Oct 27 08:48 prelink
drwx------. 2 pulse   pulse   4096 Mar 21  2017 pulse
-rw-------. 1 root    root    4096 Nov 10 11:26 random-seed
drwxr-xr-x. 2 root    root    4096 Nov 23  2013 readahead
drwxr-xr-x. 2 root    root    4096 Nov 11 03:42 rpm
drwx------. 2 root    root    4096 Jun 19 08:17 rsyslog
drwxr-xr-x. 5 root    root    4096 Oct 27 07:47 samba
drwxr-xr-x. 4 root    root    4096 Oct 27 07:45 stateless
drwxr-xr-x. 3 root    root    4096 Oct 27 07:45 udev
drwx------. 2 root    root    4096 Mar 21  2017 udisks
drwxr-xr-x. 3 root    root    4096 Oct 27 07:56 vmware
drwxr-xr-x. 3 root    root    4096 Oct 27 07:54 vmware-caf
drwxr-xr-x. 2 root    root    4096 Nov 10 11:27 xkb
drwxr-xr-x. 6 root    root    4096 Nov 11 09:05 yum

[xi@weekend01 lib]$ sudo chmod -R 777 /var/lib/mysql	

[xi@weekend01 lib]$ service mysqld start
Starting mysqld:  [FAILED]

sudo less /var/log/mysqld.log		# 发现没这个文件， 权限和用户组的问题
[xi@weekend01 log]$ sudo chown -R xi /var/log/mysql*
[xi@weekend01 log]$ chmod -R 777 /var/log/mysql*

[xi@weekend01 log]$ sudo service mysqld start
MySQL Daemon failed to start.
Starting mysqld:  [FAILED]

[xi@weekend01 log]$ su -		# 感觉是权限问题，切换到root
Password: 
[root@weekend01 ~]# service mysqld start
MySQL Daemon failed to start.
Starting mysqld:  [FAILED]
```



刚开始用下面的启动不了：

```sh
rm -fr /var/lib/mysql/*
rm /var/lock/subsys/mysqld 
killall mysqld
 
再运行： service mysqld start
      /etc/rc.d/init.d/mysqld status
```

好像解决了， 神奇。

<br>

## 设置开机自启动

查看 mysql 是否是开机自启动，并设置开机自启动

```sh
#查看当前mysql 的服务启动配置
[root@lichis ~]# chkconfig --list | grep mysqld 
mysqld          0:off   1:off   2:off   3:off   4:off   5:off   6:off   #显示没有开机自启动
[root@lichis ~]# chkconfig mysqld on    
#设置 mysql 为开机自启动
```

设置 mysql 的 root 账户的管理密码, 设置好密码后可以用 mysql -u root -p 来登录 mysql

```sh
#设置账户 root 的管理密码为 root
[root@lichis ~]# mysqladmin -u root password 'root'   
```

如果需要在外部进行访问 mysql 则还需要进入数据库修改远程登录， 另外还需要在 linux 的防火墙中将 3306 端口放行才能在外部进行访问

```sh
mysql->GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'root' WITH GRANT OPTION;
```

mysql的主要配置文件路径

```sh
1. /etc/my.cnf 这是mysql的主配置文件，以下是查看命令
2. /var/lib/mysql   mysql数据库的数据库文件存放位置
3. /var/log mysql数据库的日志输出存放位置
4. 查看系统监听的端口信息 ：netstat -anp 
```

<br>

## 参考

0- 安装参考： https://blog.csdn.net/qq_36886121/article/details/72858113

1- https://blog.csdn.net/u012286517/article/details/50436740

2- http://www.111cn.net/database/mysql/47251.htm

3- https://stackoverflow.com/questions/16890154/mysql-var-lib-mysql-directory-doesnt-exist-cant-start-mysql-server

4- http://halfsking.iteye.com/blog/2377169

5- https://www.centos.org/forums/viewtopic.php?t=44526

6- http://blog.sina.com.cn/s/blog_544f18310102w8m0.html

