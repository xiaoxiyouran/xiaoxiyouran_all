# 20180528 ubuntu 下对pthread create 未定义的引用



## 问题如下



```shell
/home/xi/Power-Model/20180118mcpat-master/mcpat-master/cacti/Ucache.cc:786：对‘pthread_create’未定义的引用
/home/xi/Power-Model/20180118mcpat-master/mcpat-master/cacti/Ucache.cc:791：对‘pthread_join’未定义的引用
/home/xi/Power-Model/20180118mcpat-master/mcpat-master/cacti/Ucache.cc:825：对‘pthread_create’未定义的引用
/home/xi/Power-Model/20180118mcpat-master/mcpat-master/cacti/Ucache.cc:830：对‘pthread_join’未定义的引用
collect2: error: ld returned 1 exit status
```



-----------

原文：http://ifelseif.me/2016/10/29/ubuntu%E4%B8%8B%E5%AF%B9pthread_create%E6%9C%AA%E5%AE%9A%E4%B9%89%E7%9A%84%E5%BC%95%E7%94%A8%E9%94%99%E8%AF%AF/

### 编译的时候出现了”对‘pthread_create’未定义的引用”这个错误。可是明明头部已经引用了pthread.h，mac下也可以正常编译，换到ubuntu下就不行了，这是为啥呢？

原因是pthread库不是Linux系统默认的库，连接时需要使用库libpthread.a,所以在使用pthread_create创建线程时，在编译中要加-lpthread参数。

注意： `-lpthread`  一定是在`.c` 源文件的后面。

```shell
gcc threadExample.c -lpthread -o threadExample
```

或者也可以这样：

```shell
gcc -o threadExample threadExample.c -lpthread 
```



如果你用的是cmake，则在CMkeLists.txt中加入：

```shell
find_package(Threads)
target_link_libraries (myhttpd ${CMAKE_THREAD_LIBS_INIT})
```



