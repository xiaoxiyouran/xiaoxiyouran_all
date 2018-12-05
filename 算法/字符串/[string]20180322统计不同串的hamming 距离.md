#  20180322统计不同串的hamming 距离

题目如下，有一个长串S :aba, 则T 串 aa .串的长度范围是 1<= |T| <= |S| <= 10 ^5

```sh
aba					aba
|					 |
aa(距离是1)		   ab(距离是2)	
```

在给一个更复杂一点的例子来说明我们的快捷方法：

```sh
abaaba			abaaba
|				 |	
aa				 aa .....	
```

可以像上面这样暴力破解。但好像复杂度O(n) * O(m)

由于题目规定只有ab两种字符，可以编码为 0 和 1

```sh
010010		010010
|			 |	
00			 00  ......
```

现在要做的事情如上。

我们建立一个新的概念，称为前缀数组。a[],a[i] 表示[0,i] 范围内的1的数目

b[]，那么b[i] 表示[0,i]范围内的0 的数目。[为节省空间，可用i - a[i] =  b[i] 来求得  ]

遍历以下数组不难得到。题目最大的串长度是10^5， 如果用bitset 来表示，最大得支持bitset<10^5>，空间还是太大，还是用字符串表示最合适。

```cpp
int a[s1.size()];
memset(a,0,sizeof(a));

if(s1[0] == 1 )
    a[0] = 1;
for( int i = 1;  i< s1.size();i++ ){
	if( s1[i] == '1' )	 
        a[i] = a[i-1] + 1;
}
```

把每个数^ 一下，求^后的1的个数，表示的是



------

我觉得不可行，就放弃掉。两层for解决

最后简单的代码如下:

```cpp
int main(){
    string s ;
    string t;
    cin >> s;
    cin >> t;

    int sum = 0;
    for( int i=0; i<s.size();i++ ){
        int head_s = i;
        int head_t = 0;
        for( int j = head_t; j < t.size();j++ ){
            if( s[head_s] != t[j] )
                sum++;
        }
    }

    cout << sum << endl;

    return 0;

}
```









