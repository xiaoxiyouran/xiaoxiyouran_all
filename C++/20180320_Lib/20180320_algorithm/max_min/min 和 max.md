# min 和 max

## 1- 头文件

包含在c++标准库中头文件<algorithm>中，在头文件<windows.h>中定义了min,max的宏，若在包含<algorithm>的同时包含<windows.h>会导致函数无法使用。

<windows.h>提供了_cpp_min等函数来代替min函数的功能。



##2- 函数原型

C++11标准：<algorithm>中min函数的原型

| default (1)          | `template <class T> const T& min (const T& a, const T& b);`  |
| -------------------- | ------------------------------------------------------------ |
| custom (2)           | `template <class T, class Compare>  const T& min (const T& a, const T& b, Compare comp);` |
| initializer list (3) | `template <class T> T min (initializer_list<T> il);template <class T, class Compare>  T min (initializer_list<T> il, Compare comp);` |

Return the smallest
Returns the smallest of a and b. If both are equivalent, a is returned.
The versions for initializer lists (3) return the smallest of all the elements in the list. Returning the first of them if these are more than one.
The function uses **operator< (or comp, if provided)** to compare the values.【函数或函数对象】

```cpp
template <class T, class Compare>  
const T& min (const T& a, const T& b, Compare comp); 
```

## 3- min举例

```cpp
#include<iostream>
#include<algorithm>     /// min  and max func
using namespace std;
struct var {
    char *name;
    int key;
    var(char *a,int k):name(a),key(k){}
};
bool comp(const var& l, const var& r) {        		/// 重写 operator <
    return l.key < r.key;
}
int main() {
    var v1("var1", 2);
    var v2("var2", 3);
    cout << std::min(v1, v2, comp).name << endl;    /// var1
    return 0;
}
```

max函数同min. 不过多介绍了。









