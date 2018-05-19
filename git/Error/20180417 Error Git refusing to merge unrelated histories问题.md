#20180417 Error Git refusing to merge unrelated histories问题

终端有README.txt 然后本地有文件，无历史track

------

原文： https://notes.wanghao.work/2017-06-28-%E8%A7%A3%E5%86%B3Git-refusing-to-merge-unrelated-histories%E9%97%AE%E9%A2%98.html

最近在使用brew更新了git之后，发现在与Github上的新创建的`repo`建立关联的之后，进行`pull`操作会出现类似于下面的这种错误：

```
 * branch            master     -> FETCH_HEAD
 * [new branch]      master     -> origin/master
fatal: refusing to merge unrelated histories
```

通过查阅资料显示，GIt从版本`2.9.0`开始，预设行为不允许合并没有共同祖先的分支，需要加上`--allow-unrelated-histories`选项进行pull操作才不会出现此类错误信息：

```
git pull origin master --allow-unrelated-histories
```