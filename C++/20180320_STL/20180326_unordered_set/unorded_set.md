# unorded_set

在vector中要进行频繁的查找或者删除。

最重要的是没有重复元素

```cpp
unordered_set<string> wordDict(wordList.begin(), wordList.end());       /// 用一个vector 来初始化一个 unordered_set

wordDict.erase(word);		// unorded_set 可以删除要要删除的值，而在vector中就必须删除指定位置的iterator了。
```

插入元素

```cpp
set.insert(val);
```

判断某元素存不存在（和unordered_map一样）

```cpp
while(sets.count(val) ) // 或者这样，sets.count() > 0
/// or
while( sets.find(val) != sets.end() )
```

