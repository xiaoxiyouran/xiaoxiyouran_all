# boost 库的安装

编译过程中未遇到错误；

输入命令如下：

到<http://www.boost.org/>下载boost的安装包，以boost_1_58_0.tar.gz为例 
下载完成后进行解压缩：

```sh
tar zxvf boost_1_58_0.tar.gz
cd boost_1_58_0
./bootstrap.sh --with-libraries=all --with-toolset=gcc
```

`--with-toolset`指定编译时使用哪种编译器，Linux下使用gcc即可，如果系统中安装了多个版本的gcc，在这里可以指定gcc的版本，比如`--with-toolset=gcc-4.4`

```sh
./b2 toolset=gcc

./b2 install --prefix=/usr
```

--prefix=/usr用来指定boost的安装目录，不加此参数的话默认的头文件在/usr/local/include/boost目录下，库文件在/usr/local/lib/目录下。这里把安装目录指定为--prefix=/usr则boost会直接安装到系统头文件目录和库文件目录下，可以省略配置环境变量。

下面这个好像没运行成功：

```sh
ldconfig
```

<br>

## 参考

1- https://blog.csdn.net/this_capslock/article/details/47170313

