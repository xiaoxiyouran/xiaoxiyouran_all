# 200180605git clone 非 master分支的代码



##  本地提交非 Origin 分支时

```shell
(venv1) [11:57@cookie ~/Downloads/20180603_updatemarkdown/markdown #4]$ git add .
(venv1) [11:58@cookie ~/Downloads/20180603_updatemarkdown/markdown #5]$ git commit -m "update for 修改了悬浮目录，增加子集目录和忽略文件"
(venv1) [11:59@cookie ~/Downloads/20180603_updatemarkdown/markdown #6]$ git push origin master:version_hiddeDir

# 本地切换到新分支
(venv1) [12:02@cookie ~/Downloads/20180603_updatemarkdown/markdown #8]$ git checkout -b version_hiddeDir
```



## git clone 非 master分支的代码

原文链接： https://www.cnblogs.com/jeacy/p/6439933.html

几步就解决了。

```shell
xi@xi-ubuntu16:~$ git clone https://gitee.com/xiaoxiyouran/markdown.git
正克隆到 'markdown'...
Username for 'https://gitee.com': xiaoxiyouran
Password for 'https://xiaoxiyouran@gitee.com': 
remote: Counting objects: 403, done.
remote: Compressing objects: 100% (327/327), done.
remote: Total 403 (delta 126), reused 270 (delta 63)
接收对象中: 100% (403/403), 3.91 MiB | 766.00 KiB/s, 完成.
处理 delta 中: 100% (126/126), 完成.
检查连接... 完成。

xi@xi-ubuntu16:~$ cd markdown/
xi@xi-ubuntu16:~/markdown$ git branch -r		# 查看远程所有分支
  origin/HEAD -> origin/master
  origin/master
  origin/version_hiddeDir
xi@xi-ubuntu16:~/markdown$ git branch -a		# 查看所有分支
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/master
  remotes/origin/version_hiddeDir

xi@xi-ubuntu16:~/markdown$ git checkout origin/version_hiddeDir
HEAD 目前位于 3f4e67d... udpate readme

```

git clone 默认会把远程仓库整个给clone下来; 
但只会在本地默认创建一个master分支 

可以使用checkout命令来把远程分支取到本地

或者使用-t参数，它默认会在本地建立一个和远程分支名字一样的分支
折叠展开复制代码

```shell
$ git checkout -t origin/daily/1.4.1
```





## 查看当前所在分支

使用如下命令查看当前所在分支；

```shell
xi@xi-ubuntu16:~/markdown$ git status
头指针分离于 origin/version_hiddeDir
无文件要提交，干净的工作区
xi@xi-ubuntu16:~/markdown$ git branch
* （头指针分离于 origin/version_hiddeDir）
  master

```

