# 005 最长回文子串

## 链接和考点

| LeetCode | https://leetcode-cn.com/problems/longest-palindromic-substring/description/ |
| -------- | ------------------------------------------------------------ |
| 考点     | String                                                       |
| 难度     | Medium                                                       |

<br>

## 题意

给定一个字符串 **s**，找到 **s** 中最长的回文子串。你可以假设 **s** 的最大长度为1000。

**示例 1：**

```
输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
```

**示例 2：**

```
输入: "cbbd"
输出: "bb"
```

 

<br>

## 分析

写一个中间向两边扩展的函数即可

<br>

## 参考答案

时间复杂度：``k* O(n)``, k <n, 是找到的最长回文字符的长度

空间复杂度：O(1)

Java 程序如下：

```cpp
public class Solution {
public String longestPalindrome(String s) {
        int max = Integer.MIN_VALUE;//最长回文子串长度;
        String result = "";
        for(int i=0;i<s.length();i++){
        //奇数中心展开
        String temp1 = expandFromCenterToEdge(s, i, i);
        if(max<temp1.length()){
        max = temp1.length();
        result = temp1;
        }
        //偶数展开
        String temp2 = expandFromCenterToEdge(s, i, i+1);
        if(max<temp2.length()){
        max = temp2.length();
        result = temp2;
        }
        }
return result;
    }
//写一个中间向两边扩展程序
public String expandFromCenterToEdge(String str,int l,int r){
int left = l;
int right = r;
//while循环是为了找到最长的串；
while(left>=0&&right<=str.length()-1&&str.charAt(left)==str.charAt(right)){
left--;
right++;
//System.out.println(left+"---"+right);
}
return str.substring(left+1,right);
}
}
```

<br>

C++ 程序如下

注意，对于有 `INT_MIN` 的比较，一定得转成int类型才能比较，否则会出错。

```cpp
(lldb) p sizeof(temp1.size())	# 占8位，它本来是1， 却小于 INT_MIN
(unsigned long) $6 = 8
(lldb) p sizeof(int)
(unsigned long) $7 = 4
```

如下：

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = INT_MIN; // 记录回文序列最长的长度
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            // 奇数中心展开
           string temp1 = expandFromCenterToEdge(s, i, i);
            if (  int(temp1.size()) > maxLen  )     // 这里必须有一个强制类型转换
            {
                maxLen = temp1.size();
                result = temp1;
            }
            //偶数展开
            string temp2 = expandFromCenterToEdge(s, i, i + 1);
            if (maxLen< int(temp2.size()) )
            {
                maxLen = temp2.size();
                result = temp2;
            }
        }
        return result;
    }

    //写一个中间向两边扩展程序
     string expandFromCenterToEdge(string str,int l,int r){
            int left = l;
            int right = r;
            //while循环是为了找到最长的串；
            while( left>=0 && right<=str.length()-1 && str[left]==str[right] ){
                left--;
                right++;
                //System.out.println(left+"---"+right);
            }
//            return str.substring(left+1,right);  // Java 截取 [left+1, right)
            return str.substr(left+1,right - (left + 1));
        }

};

int main() {

    std:: cout << Solution().longestPalindrome("aba") << std::endl;
//    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}
/*output:
aba
*/
```

