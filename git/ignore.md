# ignore

举例1：

```shell
#.gitignore for java
*.class
```

第一行是注释， 第二行是忽略任意目录下的 `*.class` 文件；

建立如下结构：

```shell
➜  demo-gitignore git:(master) tree
.
├── L1.class
└── child1
    ├── L2.class
    └── child2
        ├── L3.class
        └── child3
            └── L4.class

3 directories, 4 files
```

用 `git status` 查看是否被忽略？

```shell
➜  demo-gitignore git:(master) git status
On branch master
Initial commit
nothing to commit (create/copy files and use "git add" to track)
```

也可不用通配符，例如， 忽略所有名字叫 `Hello.xml` 文件

```shell
# project specified gitignore
Hello.xml
```

<br>

未完。。。

参考： https://www.jianshu.com/p/a3e6b5b2ab59?utm_campaign=maleskine&utm_content=note&utm_medium=seo_notes&utm_source=recommendation

gitignore 不检测新增的文件， 解决： https://segmentfault.com/q/1010000000742533

删除缓存就能用了：

```sh
git rm -r --cached .
```







