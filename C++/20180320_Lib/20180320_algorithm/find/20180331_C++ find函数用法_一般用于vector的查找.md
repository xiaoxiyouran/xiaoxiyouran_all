# 20180331_C++ find函数用法_一般用于vector的查找

相信学习C++的人有很多人用过CString.find()函数，但是你有么有用过 **std::find()** 函数呢？



##1- 数组中的查找

​       find函数主要实现的是在容器内查找指定的元素，并且这个元素必须是基本数据类型的。
查找成功返回一个指向指定元素的迭代器，查找失败返回end迭代器。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>//注意要包含该头文件
using namespace std;
int main()
{
    int nums[] = { 3, 1, 4, 1, 5, 9 };
    int num_to_find = 5;
    int start = 0;
    int end = 5;
    int* result = find( nums + start, nums + end, num_to_find );
    if( result == nums + end ) 
    {
        cout<< "Did not find any number matching " << num_to_find << endl;
    } 
    else
    {
         cout<< "Found a matching number: " << *result << endl;
    }
    return 0;
}
```

主要用于vector中找到某一个元素，然后删除掉它。

```cpp
vector<int> vec;
vec.erase(find(vec.begin(),vec.end(), num_to_find ));
```



## 2- 容器中的查找

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
        vector<int> v;
        int num_to_find=25;//要查找的元素,类型要与vector<>类型一致
        for(int i=0;i<10;i++)
                v.push_back(i*i);
        vector<int>::iterator iter=std::find(v.begin(),v.end(),num_to_find);//返回的是一个迭代器指针
        if(iter==v.end())
            cout<<"ERROR!"<<endl;
        else               //注意迭代器指针输出元素的方式和distance用法
            cout<<"the index of value "<<(*iter)<<" is " << std::distance(v.begin(), iter)<<std::endl;
        return 0;
}
```



