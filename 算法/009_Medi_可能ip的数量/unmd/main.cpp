#include <iostream>
#include <unordered_map>
#include <vector>
//#include "GlobalHead.h"
#include <vector>
#include <string>
using namespace std;


void process(string str, int & cnt, int start, int & stage){
    if(!(start < str.size() ))      // 如果因为字符串太短， 直接导致后面字段上的值不够， 那么直接返回
        return;

    if( stage == 4 ){               // 已经到了第四个字段， 检验剩下的是否合格
        string cur = str.substr(start, str.size() - start);
        int num = stoi(cur);
        if( ( num >=0 && num <= 255 )){
            cnt ++;
            return;
        }else{
            return;
        }

    }

    for( int i =  start; i < start+3 && i < str.size() ; i++ ){
        string cur = str.substr(start, i - start + 1);
        int num = stoi(cur);
        if( !( num >=0 && num <= 255 ))     // 如果当前不满足，直接中断， 剪枝
            continue;
        else{
            stage++;
            process(str, cnt, i+1, stage);
            stage--;
        }

    }
}


int main() {
    string M;
    cin >> M;

    int stage = 1;              // 刚开始处理第一个字段
    int cnt  = 0;               // 记录可行的ip数
    process(M, cnt, 0, stage);
    cout << cnt << endl;
    return 0;
}
/*output:
18888

4
*/