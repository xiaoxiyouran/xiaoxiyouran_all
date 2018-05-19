# istream_iterator 和 ostream_iterator

```
// 1- 从输入读入一系列的 数字/字母/字符串 放入到特定的容器。
vector<int> ivec;
copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ivec));
// or 
vector<int> ivec(istream_iterator<int>(cin),istream_iterator<int>());
istream_iterator<int>()//相当于eof

+-+-+-+-+-+-+-+-+-+-+- 输出到屏幕+-+-+-+-+-+-+-+-+-+-+-
copy(ivec.begin(),ivec.end(),ostream_iterator<int>(cout,"\t"));  

//将ivec 从begin到end 拷贝到输出缓冲区，这个元素的构成：ivec的"元素\t"
//输出缓冲区中存放："元素1\t","元素2\t","元素3\t",......打印的时候\t 会转换为制表符输出到屏幕

copy(iVec.begin(),iVec.end(),ostream_iterator<int>(cout," "));  // -1 1 2 3 10 11 12 13 1
```

