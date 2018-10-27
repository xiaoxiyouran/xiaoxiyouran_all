# 20180904 Errorsrc refspec master does not match any

## 摘要

| Item | Content  |
| ---- | -------- |
| 更新 | 20180904 |

<br>

## 问题

使用git push时出现如下问题：

```shell
[10:49@cookie ~/Desktop/xiaoxiyouran #12]$ git push origin master
error: src refspec master does not match any.
error: failed to push some refs to 'git@github.com:xiaoxiyouran/blogger.git'
[10:49@cookie ~/Desktop/xiaoxiyouran #13]$ git pull origin master
fatal: Couldn't find remote ref master
```

最后发现`git push origin master` 不在当前的master分支：

```shell
[10:51@cookie ~/Desktop/xiaoxiyouran #14]$ git st
On branch gh-pages
nothing to commit, working tree clean
```

最后推上去用master分支，就解决了。

```shell
[10:52@cookie ~/Desktop/xiaoxiyouran #16]$ git push  origin gh-pages
Counting objects: 174, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (157/157), done.
Writing objects: 100% (174/174), 2.91 MiB | 1.40 MiB/s, done.
Total 174 (delta 67), reused 121 (delta 16)
remote: Resolving deltas: 100% (67/67), completed with 23 local objects.
To github.com:xiaoxiyouran/blogger.git
   db896f2e..31e30448  gh-pages -> gh-pages
```

