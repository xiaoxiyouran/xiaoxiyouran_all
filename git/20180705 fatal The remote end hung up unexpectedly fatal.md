# 20180705 fatal The remote end hung up unexpectedly fatal

一般查看问题： `ssh -VT 地址`

## 调试日志

```shell
[14:09@cookie ~/Desktop/xiaoxiyouran/src #33]$ git push github  master
Counting objects: 26573, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (6714/6714), done.
packet_write_wait: Connection to 13.229.188.59 port 22: Broken pipe
fatal: The remote end hung up unexpectedly
fatal: The remote end hung up unexpectedly
[14:36@cookie ~/Desktop/xiaoxiyouran/src #34]$ git config http.postBuffer 52428800
```



