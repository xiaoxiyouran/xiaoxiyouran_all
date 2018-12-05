# 20180416 error thread is not a member of std

在Windows上调用C++ 11 新加的线程库，发现会出问题。 [解决方式](https://blog.csdn.net/wangxiaobupt/article/details/37882541)

```cpp
#include<iostream>  
#include<thread>  
using namespace std;  
  
void hello()  
{  
    cout<<"hello kitty"<<endl;  
}  
  
int main()  
{  
    std::thread t(hello);  
    t.join();  
    return 0;  
}  
```

错误原因：

没有c++11线程库支持

解决方法：

<1>从下面网站下载threads-posix 支持【貌似是重新下了一个MinGw 编译器，全覆盖】

<http://sourceforge.net/projects/mingwbuilds/files/host-windows/releases/4.8.1/64-bit/threads-posix/sjlj/>

<2>覆盖在MinGW目录下

<3>设置编译器为  x86_64-w64-mingw32-g++.exe 即可

<4>重启code blocks