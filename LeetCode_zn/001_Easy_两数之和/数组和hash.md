# 001 两数之和

## 链接和考点

| LeetCode | https://leetcode-cn.com/problems/two-sum/description/ |
| -------- | ----------------------------------------------------- |
| 考点     | vector,  unordered_map                                |
| 难度     | Easy                                                  |

<br>

## 题意

给定一个整数数组和一个目标值，找出数组中和为目标值的**两个**数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

**示例:**

```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

<br>

## 分析

用一个hash表存储要查找的串即可。

<br>

## 参考答案

时间复杂度： 比O(n) 大一点

空间复杂度：O(n)

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            int numberToFind = target - numbers[i];

                //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                        //+1 because indices are NOT zero based
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }

                //number was not found. Put it in the map.
            hash[numbers[i]] = i;
        }
        return result;
    }
};

template <typename T>
void print_Vec1D(vector<T> vec){
    for( auto it=vec.begin(); it != vec.end(); it++ ){
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

int main() {
    vector<int> numbers {2,7,11,15};
    Solution sol;
    print_Vec1D(sol.twoSum(numbers, 9 ));

    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}
```

