#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct qu{
    int index;
    int val;
    int dui;
    qu(int index, int val)
    {
        this->index = index;
        this-> val = val;
    }
};


bool compare(const qu st1, const qu st2){
    return st1.val < st2.val;       // 从小到大排序
}

bool compare2(const qu st1, const qu st2){
    return st1.index < st2.index;   // 从小到大排序
}


int search(vector<int> & vec, int target){
    int left = 0;
    int right = vec.size() -1;
    while (left <= right){
        int mid = (left + right)/2;
        if( vec[mid] >= target ){
            if( (mid -1 >=0 && vec[mid-1] <= target) || mid ==0 ){
                return mid;
            }
        }

        if (target>= vec[mid])
            left = mid + 1;
        else
            right = mid -1;
    }
    return  -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> dui_apple;
    for( int i=0; i<n; i++ ){
        int k;
        cin >> k;

        dui_apple.push_back(k);

    }

    int query;
    cin >> query;
    vector<int> query_arr;
    vector<qu> querr;
    for( int i=0; i<query; i++ ){
        int k;
        cin >> k;
        qu tmp(i, k);
        query_arr.push_back(k);
        querr.push_back(tmp);
    }

    sort(querr.begin(), querr.end(), compare);
    vector<int> sum_arr(dui_apple.size(),0);
    for( int i=0; i < dui_apple.size(); i++ ){
        if(i == 0)
            sum_arr[i] = dui_apple[i];
        else
            sum_arr[i] = sum_arr[i-1] + dui_apple[i];
    }


//    cout << search(sum_arr, querr) + 1 << endl;
    int p1 = 0, p2 = 0;
    for(int i = 0; i<sum_arr.size(); i++){
            while( sum_arr[i] >= querr[p2].val && p2 < querr.size()){
                if( (i -1 >=0 && sum_arr[i-1] <= querr[p2].val) || i ==0 ){
                    querr[p2].dui = i+1;
                    p2++;
            }
        }
    }

    sort(querr.begin(), querr.end(), compare2);
    for(int i =0; i< querr.size(); i++){
        cout << querr[i].dui << std::endl;
    }
//    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}
/* input:
5
2 7 3 4 9
3
1 25 11

*/