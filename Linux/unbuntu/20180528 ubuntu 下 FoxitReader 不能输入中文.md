# 20180528 ubuntu 下 FoxitReader 不能输入中文





使用这种并不能解决问题：http://www.cnblogs.com/empty16/p/7290439.html

Foxit Reader也是Ubuntu下面非常成熟的pdf阅读软件，支持中英文pdf软件的阅读和注释，同时提供了丰富的注释工具，非常方便。

而且Foxit Reader同样是跨平台软件，可以在多个系统下使用。安装最新版本的Foxit Reader软件后，并不支持中文的输入和注释，所以非常麻烦，搜索并尝试很多解决方案，但是只有一种解决方案完美解决了我的问题。

解决方案：

\1.  在～/.profile和/etc/profile中加入环境变量，使得Foxit Reader可以获取输入法环境变量信息:

```
sudo gedit /etc/profile
```

在该文件中加入以下变量信息：

```
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx #最重要的一句
export XMODIFIERS=@im=fcitx
```

重启或者使用下面语句使环境变量生效：

```
sudo ldconfig
```

添加该环境变量主要是因为：Foxit Reader需要添加gtk,gtk3,qt等对fcitx的支持，使得在启动之前设置好环境变量。

原帖见：

[FoxitReader中无法启用fcitx](https://groups.google.com/forum/#!topic/fcitx/wcwaIAWt1ds)

[为什么有些软件中不能用Fcitx输入中文](https://bbs.deepin.org/forum.php?mod=viewthread&tid=45314)

 

同时也搜索到其他的解决方案，尝试后并没有解决我的问题，一并总结以供大家尝试：

[foxit reader中注释无法输入中文](http://haoma.sogou.com/bbs/forum.php?mod=viewthread&tid=2639560)

[ubuntu--FoxitReader不能使用中文输入法](http://blog.csdn.net/scylhy/article/details/52550324)

---

参考原文如下：https://blog.csdn.net/scylhy/article/details/52550324

最终解决办法如下：

- 方法一，修改sh脚本——>推荐 

  **修改/home/xi/bin/FoxitReader.sh，注释掉export那一行即可**

```shell
#!/bin/sh
 appname="FoxitReader"

 selfpath="/home/liu/bin/foxit"
 LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$selfpath/lib:$selfpath/platforms:$selfpath/printsupport:$selfpath/rmssdk:$selfpath/sensors:$selfpath/imageformats:$selfpath/platforminputcontexts
 #export LD_LIBRARY_PATH      #加上#，注释掉这一行即可
 exec "$selfpath/$appname" "$@"
```