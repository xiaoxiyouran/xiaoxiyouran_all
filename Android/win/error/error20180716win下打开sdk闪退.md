# error20180716win下打开sdk闪退

安装好jdk之后出现了闪退，一般是sdk的路径有问题。

参考[这篇文章](https://blog.csdn.net/puma004/article/details/11392271)

```shell\
修改android.bat文件了。对，直接指定java.exe的路径：
把
set java_exe=
call lib\find_java.bat

改成：
set java_exe=C:\Java\jdk1.7.0_25\bin\java.exe
```



其它参考： https://blog.csdn.net/ccy521520/article/details/43084193

