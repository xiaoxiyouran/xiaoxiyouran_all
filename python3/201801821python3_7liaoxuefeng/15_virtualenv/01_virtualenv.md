# virtualenv

就是一个python

在开发Python应用程序的时候，系统安装的Python3只有一个版本：3.4。所有第三方的包都会被`pip`安装到Python3的`site-packages`目录下。

如果我们要==同时开发多个应用程序==，那这些应用程序都会共用一个Python，就是安装在系统的Python 3。如果应用A需要jinja 2.7，而应用B需要jinja 2.6怎么办？

这种情况下，每个应用可能需要各自拥有一套“独立”的Python运行环境。virtualenv就是用来为一个应用创建一套“隔离”的Python运行环境。

==首先==，我们用`pip`安装virtualenv：

```sh
$ pip3 install virtualenv
```

然后，假定我们要开发一个新的项目，需要一套独立的Python运行环境，可以这么做：

第一步，创建目录：

```sh
Mac:~ michael$ mkdir myproject
Mac:~ michael$ cd myproject/
Mac:myproject michael$
```

第二步，创建一个独立的Python运行环境，命名为`venv`：

```sh
Mac:myproject michael$ virtualenv --no-site-packages venv
Using base prefix '/usr/local/.../Python.framework/Versions/3.4'
New python executable in venv/bin/python3.4
Also creating executable in venv/bin/python
Installing setuptools, pip, wheel...done.
```

命令`virtualenv`就可以创建一个独立的Python运行环境，我们还加上了==参数`--no-site-packages`，这样，已经安装到系统Python环境中的所有第三方包都 **不会** 复制过来==，这样，我们就得到了一个不带任何第三方包的“干净”的Python运行环境。

新建的Python环境被放到当前目录下的`venv`目录。有了`venv`这个Python环境，可以==用`source`进入该环境==：

```sh
Mac:myproject michael$ source venv/bin/activate
(venv)Mac:myproject michael$
```

注意到命令提示符变了，有个`(venv)`前缀，表示==当前环境是一个名为`venv`的Python环境==。

下面正常安装各种第三方包，并运行`python`命令：

```sh
(venv)Mac:myproject michael$ pip install jinja2
...
Successfully installed jinja2-2.7.3 markupsafe-0.23
(venv)Mac:myproject michael$ python myapp.py
...
```

在`venv`环境下，用`pip`安装的==包都被安装到`venv`这个环境下==，==系统Python环境不受任何影响==。也就是说，`venv`环境是专门针对`myproject`这个应用创建的。

==退出当前的`venv`环境，使用`deactivate`命令==：

```sh
(venv)Mac:myproject michael$ deactivate 
Mac:myproject michael$
```

此时就回到了正常的环境，现在`pip`或`python`均是在系统Python环境下执行。

完全可以针对每个应用创建独立的Python运行环境，这样就可==以对每个应用的Python环境进行隔离==。

virtualenv是如何创建“独立”的Python运行环境的呢？原理很简单，就是==把系统Python复制一份到virtualenv的环境，用命令`source venv/bin/activate`进入一个virtualenv环境时，virtualenv会修改相关环境变量，让命令`python`和`pip`均指向当前的virtualenv环境==。

<br>

## 小结

virtualenv为应用提供了隔离的Python运行环境，解决了不同应用间多版本的冲突问题。

<br>

python3.3以后自带venv模块支持轻量级虚拟环境，virtualenv模块仍然支持,可安装。

1.创建虚拟环境 `virtualenv --no-site-packages myvenv`等价于  `virtualenv myvenv`（目前**新版默认就不使用系统环境包**）

python3自带 `venv python -m venv myvenv ` **也是默认全新干净的环境**，相反可选的参数 `python -m venv --system-site-packages myvenv` 使虚拟环境==指向系统环境包目录（非复制, 相当于借用）==，在**系统环境pip新安装包，在虚拟环境就可以使用。**

<br>

2.激活虚拟环境

```sh
Platform    Shell        Command to activate virtual environment
Posix       bash/zsh     $ source <venv>/bin/activate
            fish         $ . <venv>/bin/activate.fish
            csh/tcsh     $ source <venv>/bin/activate.csh
            
Windows     cmd.exe      C:> <venv>\Scripts\activate.bat
            PowerShell   PS  C:> <venv>\Scripts\Activate.ps1
```

<br>

3.关闭虚拟环境 <strong>deactivate</strong>

4.删除虚拟环境 删除目录即可 <strong>rd /s /q myvenv</strong> （windows cmd下）

5 谢谢，使用 help 命令查了一下，确实如此。

> --no-site-packages    DEPRECATED. Retained only for backward compatibility. Not having access to global site-packages is now the default behavior.

不赞成使用。**仅为了向下兼容而保留**此参数。现在不会获取全局的 site-packages 包了。(尬译 ;)

<br>

6- 另有anaconda创建虚拟环境的文档， 可以参照，这里给个例子：

用这个是因为可以创建多个python 版本，

```sh
myzhao@myzhao-YNAO:~$ conda create --name test python=2.7
myzhao@myzhao-YNAO:~$ source activate test
(test) myzhao@myzhao-YNAO:~$ conda list
# packages in environment at /home/myzhao/anaconda3/envs/test:
#
# Name                    Version                   Build  Channel
ca-certificates           2017.08.26           h1d4fec5_0  
certifi                   2018.1.18                py27_0  
libedit                   3.1                  h9ac1fc1_0  
libffi                    3.2.1                h97ff0df_4  
libgcc-ng                 7.2.0                h9268252_3  
libstdcxx-ng              7.2.0                h9268252_3  
ncurses                   6.0                  h8a800b7_2  
openssl                   1.0.2n               hb7f436b_0  
pip                       9.0.1                    py27_5  
python                    2.7.14              h1571d57_30  
readline                  7.0                  h6b4b497_4  
setuptools                38.5.1                   py27_0  
sqlite                    3.22.0               h1bed415_0  
tk                        8.6.7                h9a736a7_3  
wheel                     0.30.0           py27h13c6743_1  
zlib                      1.2.11               h907e355_2
```

如果没有第三方包的‘干净’的环境，应该只有`pip`和`setuptools`的。

但是我conda用的也不熟，不排除有参数**可以不加第三方包**，那么效果就和virtualenv一样了。

<br>

7- 如果用virtualenv 创建python2 和python3的虚拟环境呢？

- 1） 要求系统中已经安装了 python3 ；
- 2） 使用以下指令：

```sh
virtualenv -p /usr/local/bin/python3.4 py34env # 在当前目录创建py34env文件夹
```



