# 20180528Linux  shell 命令完成提醒

比如`ls` 指令：

```shell
xi@xi-ubuntu16:~/Learning-Notes-For-Xi_1/Linux$ ls;notify-send -u critical "complete"
20180528Linux  shell 命令完成提醒.md

```



----------------------------

原文：https://www.douban.com/note/210037816/

一个命令要运行很长的时间，我可不想一直守在那，于是切到其他桌面上豆瓣了。

但这样我就需要来回切换桌面以检查那个命令是否运行完了。来回切换桌面也太麻烦了，我需要一种完成提醒的功能，当命令运行完的时候收到桌面提醒，最好是弹出一个（巨大的）X 对话框。

以前用的方法是：

cmd ; notify-send -u critical "complete"

在 systray 显示一个提示框

这个方法本来也用得很好的，但由于我在公司用了多显示器，就是一个笔记本接着一个显示器，VGA 作为我的主要显示设备，但那个提示框跑到笔记本上去了。

第二种方法：

cmd ; Xdialog --infobox "complete" 400 300 0

或者干脆：

cmd ; feh ~/complete.png

本来想用 zenity 的，但 zenity 的窗口只能在当前桌面显示，囧

**后续问题：**

我 ssh 登录远程主机并在上面运行命令，怎么收到完成提醒？

-- ssh X11 forwarding: ssh -C -X host