# Linux 临时设置ip地址

1- 这个设置是临时的，系统重启失效。

```sh
[xi@weekend04 Desktop]$ sudo ifconfig eth2 192.168.180.136 netmask 255.255.255.0 
[xi@weekend04 Desktop]$ ping weekend04
PING weekend04 (192.168.180.136) 56(84) bytes of data.

```

