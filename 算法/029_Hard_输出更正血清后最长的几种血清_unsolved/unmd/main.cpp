#include<stdio.h>
#include<string.h>
#include<iostream>
#include<functional>
#include<queue>
#include<set>
#include<string>
#include<unordered_map>
#include<map>
#include<array>
#include<algorithm>
#include<stack>
#include "GlobalHead.h"
using namespace std;

using namespace std;
typedef int ElemType;




map<char, int> mymap;



void process_map(string & stu){
    for(int i=0; i< stu.size(); i++){
        if( mymap.find(stu[i]) == mymap.end() ){
            mymap[stu[i]] = 1;
        }else{
            mymap[stu[i]]++;
        }
    }

    for( auto it = mymap.begin(); it != mymap.end(); it++ )
        cout << it->first << ": " << it-> second << endl;
}

void dfs( string& res, string& in, vector<string>& outcome){
    if(res.size() == in.size())
        outcome.push_back(res);

    for( int i = 0; i < data.size(); i++ ){

    }

    for( auto it = mymap.begin(); it != mymap.end(); it++ ){
        if( it -> second > 0 ){
            res += it->first;
            it -> second--;


        }
    }

}

string combine(string& in, int count){
    string res = "";

    int size = 0;
    while( size < in.size() ){
        int part = 0;
        for( auto it = mymap.begin(); it != mymap.end(); it++ ){
            if( it -> second > 0 ){
                res += it->first;
                it -> second--;
                part++;
                size++;
                if(part == count + 1)
                    break;

            }

        }
        if( part != count + 1 ){
            return "-1";
        }
    }
    return res;

}

struct node{
    char a;
    int val;
    node(char a, int val): a(a), val(val){}
};
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
string rearrange(string students, int count)
{
    // WRITE YOUR CODE HERE
    process_map(students);
    vector<node> data;
    for( auto it = mymap.begin(); it != mymap.end(); it++ ){
        node tmp(it-> first, it-> second);
        data.push_back(tmp);
    }

    cout << combine(students, count);

    return "";
}
// FUNCTION SIGNATURE ENDS


//主函数
int main()
{
    string in = "aaaabbbcc";
    int count = 1;
    cout << rearrange(in, 1);



    return  0;
}