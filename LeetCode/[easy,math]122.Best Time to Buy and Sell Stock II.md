# [easy,math]122.Best Time to Buy and Sell Stock II

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

可以买卖多次，赚所有可以盈利的总和。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        for( int i=1; i< prices.size();i++ ){
            if( prices[i] > prices[i-1] )  total += prices[i] - prices[i-1];    /// 只要有高的价就卖
            
        }
        
        return total;
    }
};
```

