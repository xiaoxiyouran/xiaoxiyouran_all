# git 使用注意事项

1- 对于版本管理，重要的单独立项`markdown_v1.0` 等，不要添加分支；

2- `git clone` 时一定要注意查看有无其他最新的分支；

不要拷贝错了；

3- git commit 之后，一定要上网站上checke 一下；

4- 对于`.git` 管理的目录下还有其它 `.git` 文件夹，建议立即删除子文件夹下的 `.git`. 

`.gitignore` 一定要引起警惕，防止有些文件并未上传；

对于`git add ` 和 `git commit` 没有任何反应的，要清楚缓存`git rm -r --cached path  # 路径如 .`;

5- 查看最近提交信息用：

`git lg`, 前提是做了如下设置：

```shell
[20:32@cookie ~/Downloads/markdown_v2.0 #16]$ git config --global alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"
```

