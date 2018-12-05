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