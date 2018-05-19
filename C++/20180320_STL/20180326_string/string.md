# string



实例三 对一个字符串用指定字符分割

```cpp
#include <iostream>
#include <vector>
using namespace std;

#本例采用c++11实现
std::vector<std::string> splitFunc(const std::string &str,const std::string &delimiter)
{
    std::vector<std::string> resVec;
    if("" == str)
    {
        return resVec;
    }

    std::string strs = str + delimiter;
    size_t pos =strs.find(delimiter);
    size_t length = strs.size();
    while(pos != std::string::npos)
    {
        std::string elem = strs.substr(0,pos);
        resVec.push_back(elem);
        //update current string & pos
        strs = strs.substr(pos+1,length);
        pos = strs.find(delimiter);
    }

    return resVec;

}
int main(int argc, char ** argv)
{
    std::string label="1,2,3,4";
    std::string delimiter =",";
    std::vector<std::string> result;
    result = splitFunc(label,delimiter);
    for(auto s: result)
    {
        cout << s << endl;
    }
    return 0;

}


//------------------boost 实现-------------------------
include <boost/algorithm/string.hpp>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    vector<string> result;
    boost::split(result,"1*6,7*2,3,4",boost::is_any_of(",*"));
    for(auto s:result)
    {
        cout << s<< endl;
    }
    return 0;
}
```



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



第二种为：可以直接实现，返回string类型。

```cpp
 std::to_string(var) 
```

