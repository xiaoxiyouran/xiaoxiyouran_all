#[math]119. Pascal's Triangle II

Given an index *k*, return the *k*th row of the Pascal's triangle.

For example, given *k* = 3,
Return `[1,3,3,1]`.

**Note:**
Could you optimize your algorithm to use only *O*(*k*) extra space?

用迭代的思想。 

1- 默认初始化为0 ，应该从后往前处理，相当于满足最后一个位1的情形。

2- 一层层的迭代处理

```sh
			1  0  /// 补个0
		  1	  1  0 /// i = 1
        1   2    1  0 /// i = 2 <-----  从后往前  
      1   3    3    1   /// i = 3 
```

结果如下：

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,0);  // all initialize 0
        res[0] = 1;
        for( int i=1; i<= rowIndex; i++ ){
            for( int j = i; j >= 1; j-- )
                res[j] += res[j-1];
        }
        
        return res;
    }
};
```







