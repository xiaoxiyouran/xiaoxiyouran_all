# [dfs,bfs,未完]126.  Word Ladder II

Given two words (*beginWord* and *endWord*), and a dictionary's word list, find all shortest transformation sequence(s) from *beginWord* to *endWord*, such that:

1. Only one letter can be changed at a time
2. Each transformed word must exist in the word list. Note that *beginWord* is *not* a transformed word.

For example,

Given:
*beginWord* = `"hit"`
*endWord* = `"cog"`
*wordList* = `["hot","dot","dog","lot","log","cog"]`

Return

```
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
```

**Note:**

- Return an empty list if there is no such transformation sequence.
- All words have the same length.
- All words contain only lowercase alphabetic characters.
- You may assume no duplicates in the word list.
- You may assume *beginWord* and *endWord* are non-empty and are not the same.

**UPDATE (2017/1/20):**
The *wordList* parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

第一种方法最简单的就是dfs, 但是超时了。

```cpp
class Solution {
public:
    int minLen = INT_MAX;
    int cmp(string& fir, string& sec){
        int differ = 0;
        // std::unordered_map<int,string> mymap;
        for(int i =0; i< fir.length(); i++ ) {
            if( fir[i] != sec[i] )
                differ++;
        }
        return differ;
    }

    void nextValidWords(string& beginWord, vector<string>& wordList, vector<string>& next){
        for( int i=0; i < wordList.size(); i ++ ){

            if( cmp(beginWord, wordList[i]) == 1 ){
                next.push_back(wordList[i]);
//                wordList.erase(wordList.begin() + i);
            }
        }
    }

    void dfs(string beginWord,string& endWord, vector<string>& wordList,int& pathLen, vector<string>& tmp,vector<vector<string>>& res ){
        if( beginWord == endWord ){
            if(pathLen < minLen){
                minLen = pathLen;
                res.clear();
                res.push_back(tmp);
            }else if(pathLen == minLen){
                res.push_back(tmp);
            }
            return;
        }
        vector<string> next;
        nextValidWords(beginWord, wordList, next);
        for(int i = 0; i< next.size(); i++){
            ++pathLen;
            tmp.push_back(next[i]);
            wordList.erase( find(wordList.begin(),wordList.end(),next[i]) );        /// 需要注意的是这里删除指定的元素
            dfs(next[i],endWord,wordList,pathLen,tmp, res);
            wordList.push_back(next[i]);                                            /// 然后这里又添加回来
            tmp.pop_back();
            --pathLen;
        }

    }

    vector<vector<string>> findLadders(string beginWord,string endWord, vector<string> wordList) {
        vector<string> tmp;
        vector<vector<string>> res;
        int pathLen =0;
        /// 起始单词需要加入进去
        ++pathLen;
        tmp.push_back(beginWord);
        dfs(beginWord,endWord,  wordList,pathLen, tmp,res);
        return res;

    }
};

```





