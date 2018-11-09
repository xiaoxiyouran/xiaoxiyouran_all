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
#include <numeric>
using namespace std;


//主函数
int main()
{
    int n;
    cin >> n;
    vector<int> Left, Right;
    vector<int> flag(n, 0);
    for( int i=0; i< n; i++ ){
        int l , r;
        cin >> l;
        cin >> r;
        Left.push_back(l);
        Right.push_back(r);
    }

    int sum = 0;
    for( int i= n-1; i >= 1; i-- ){
        if(flag[i]) continue;       // 没这个加速，只A了
        for( int j = i-1; j>=0; j-- ){
            if( Left[i]<= Left[j] && Right[i] >= Right[j] && flag[j] == 0  ) {
                sum++;
                flag[j] = 1;
            }

        }
    }

    cout << sum << endl;

    return  0;
}