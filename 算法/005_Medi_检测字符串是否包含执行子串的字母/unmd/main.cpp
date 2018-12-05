#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

bool process(string& in1, string& in2){
    if(in1.size() < 5 || in2.size() < 5 || in1.size() <= in2.size())
        return false;
    unordered_map<char, int> mymap;
    for(int i=0; i < in1.size(); i++){
        if( mymap.find(in1[i]) != mymap.end() )
            mymap[in1[i]] ++;
        else
            mymap[in1[i]] = 1;      // first insert
    }
//    general::print_Hashmap(mymap);
    bool flag = true;
    for( int i=0; i < in2.size(); i++ ){
        if( mymap.find(in2[i]) != mymap.end() ){
            if( mymap[in2[i]] > 0 ){        // 不只一个
                mymap[in2[i]]--;
                continue;
            }else{      // 重复检查的元素不够
                flag = false;
                break;
            }

        }else{
            flag = false;       // 发现了一个不存在的字符
            break;
        }
    }
//    general::print_Hashmap(mymap);
    return flag;
}

int main() {

    string input1;
    string input2;
    cin >> input1;
    cin >> input2;

    // check
    cout <<boolalpha<< process(input1, input2) << endl;

    return 0;
}