# stringsteam

数字转字符串：

实际上常用的有2中， 第一种stringstream 
用法为

```cpp
Dtype a=4； 
stringstream ss； 
string result; 
ss << a; 
ss >> result; 
```

这样result存储的即为 对应数字的string格式。 
其中Dtype 可以是 int float double longlong几种。 

