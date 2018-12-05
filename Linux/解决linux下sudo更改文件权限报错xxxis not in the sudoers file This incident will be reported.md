# 解决linux下sudo更改文件权限报错xxxis not in the sudoers file This incident will be reported

```sh
[sudo] password for xi: 
xi is not in the sudoers file.  This incident will be reported.
[xi@localhost ~]$ xi is not in the sudoers file.  This incident will be reported
```

解决如下：

```sh
chmod u+w /etc/sudoers
vi /etc/sudoers 
找到这行 root ALL=(ALL) ALL,在他下面添加xxx ALL=(ALL) ALL (这里的xxx是你的用户名)
xi ALL=(ALL) ALL
```

<br>

## 参考

1-  https://blog.csdn.net/sinat_36118270/article/details/62899093



