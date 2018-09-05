#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

bool compare(string fir, string sec){
    string fir_time = fir.substr(1, 5);
    string fir_zone = fir.substr(7,4);

    string sec_time = sec.substr(1, 5);
    string sec_zone = sec.substr(7,4);


    if( sec_zone < fir_zone )
        return true;

    else if(sec_zone > fir_zone)
        return  false;

    else if( sec_zone == fir_zone ){
        if( fir_time > sec_time )
            return  true;
        else
            return false;
    }

}

template <typename T>
void print_Vec1D(vector<T> vec){
    for( auto it=vec.begin(); it != vec.end(); it++ ){
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;
}

int main() {

    vector<int> res;
    string  Num;
//    cin >> Num;
    getline(cin, Num);
    while( Num != ""){
        int N;
        N = atoi(Num.c_str());
//        cin >> Num;
        string fir;
        int day = 0;
        if( N > 0){
            getline(cin, fir);
            day++;
        }

        string sec;
        for(int i = 1; i < N; i++){
            getline(cin, sec);
//            cout << sec << endl;
            if( compare(fir, sec) )
                day++;
            fir = sec;
        }
//        cout << day << endl;
        res.push_back(day);
//        cin >> Num;
        getline(cin, Num);
    }

    print_Vec1D(res);

    return 0;
}