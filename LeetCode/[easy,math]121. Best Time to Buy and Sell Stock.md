#[easy,math]121. Best Time to Buy and Sell Stock

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

**Example 1:**

```
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
```

**Example 2:**

```
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
```



1- 如果是负数，就还是0，不会加上去

2- 当找到更小的值时，maxCur 会更新。 maxSoFar 是最大值。

```cpp
[7, 1, 5, 3, 6, 4]
i = 1
maxCur = -6
maxCur = 0
maxSoFar = 0
    
i = 2 
maxCur = 4
maxSoFar = 4
    
i = 3
    
```



```CPP
#include<algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {       
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = std::max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = std::max(maxCur, maxSoFar);
        }
        return maxSoFar;
        
    }
};
```



## 2- 更直观的解法

每次保存遍历到的最小值，然后判断之后的每个盈利。

```cpp
int min = 0;
int profit = 0;
for( int i =1; i < prices.size(); i++  ){
    if( prices[i] < prices[min] ){
        min = i;    /// 找到了更小的值
    }else{ 			/// 后面的都比最小值大，更新最大盈利值 
        if( prices[i] - prices[min] > profit )
            profit = prices[i] - prices[min];
    }
}

return profit;
```

