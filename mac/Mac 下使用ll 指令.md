# Mac 下使用ll 指令

linux有ll等命令，切换到MAC下这些指令是没有的

其实就是别名，用ls -alF也能做到

添加方法：

```sh
vim ~/.bash_profile	# 这个是mac的环境变量配置文件
```

输入一下内容

```sh
alias ll='ls -alF'	# 等价ll
alias la='ls -A'	# 列出带隐藏的文件名
alias l='ls -CF'	# 等价ls
```

保存完成之后

```sh
source ~/.bash_profile
```

可以使用ll等命令了

source命令用法：

```sh
source FileName
```

作用:在当前bash环境下读取并执行FileName中的命令。
注：该命令通常用命令“.”来替代。
如：``source .bash_rc`` 与 ``. .bash_rc ``是等效的。
注意：source命令与shell scripts的区别是，
source在当前bash环境下执行命令，而scripts是启动一个子shell来执行命令。这样如果把设置环境变量（或alias等等）的命令写进scripts中，就只会影响子shell,无法改变当前的BASH,所以通过文件（命令列）设置环境变量时，要用source 命令。

