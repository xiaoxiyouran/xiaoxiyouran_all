# 20180606 error git untracked content

1、提交代码到服务器后发现git clone下来的有些目录是空的。

查看服务器的目录果然是空的。看本季git add .    后查看git  status 

```
modified: xxx(modified content, untracked content)
```

```
大概意思是xxx目录没有被跟踪。那自然push上去的时候是空的了
解决办法：后来发现这主要是xxx目录下有一个.git 目录，可能是被人给你这个目录的时候里面有了.git目录。删除.git目录。重新git add .就可
```



解决之道是：

```shell
删除 .git 文件夹
git rm -r --cached path  # 路径如 .
git add .
git commit -m "xx"
git push origin master 
```

 