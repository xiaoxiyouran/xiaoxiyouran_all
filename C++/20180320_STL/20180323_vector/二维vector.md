# 二维vector

## 1- 取二维vector的值

```cpp
    /// Get the min num of one row
    int minNumOneRow( vector<int>& row){
        int min = row[0];
        for( int val: row )	/// 取一维vector的每一个值
            if( val < min )
                min = val;
        return min;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum = 0;
        for( vector<int > vec: triangle )  /// 取二维vector的每一维
            sum += minNumOneRow(vec);
        
        return sum;
    }
```



## 2- 初始化 

1- 用{}

2- 用另一个vector来初始化

```cpp
// 1- 
vector<vector<int> > in{{-1}, {3,2},{-3,1,-1}};

// 2-
vector<vector<int>>& triangle;
vector<int > minlen( triangle.back() ); /// Get the last line vector to initialize
```

