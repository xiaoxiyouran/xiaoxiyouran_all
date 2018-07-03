# 136 Single Number

Given a **non-empty** array of integers, every element appears *twice* except for one. Find that single one.

**Note:**

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

**Example 1:**

```
Input: [2,2,1]
Output: 1
```

**Example 2:**

```
Input: [4,1,2,1,2]
Output: 4
```

## 解

使用异或，比较简单直接，

如 `[5,3,3]` 

```cpp
0 ^ 5 = 5;
5 ^ 3 = 6; | 101 ^ 011 = 110
6 ^ 3 = 5; | 110 ^ 011 = 101
```

Code, 

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0; 
        for( int i = 0; i < nums.size() ; i++ ){
            res ^= nums[i];
        }
        return res;
    }
};
```





参考：https://leetcode.com/problems/single-number/discuss/42997/My-O(n)-solution-using-XOR