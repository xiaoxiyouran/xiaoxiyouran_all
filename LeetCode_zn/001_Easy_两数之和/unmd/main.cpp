#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            int numberToFind = target - numbers[i];

                //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                        //+1 because indices are NOT zero based
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }

                //number was not found. Put it in the map.
            hash[numbers[i]] = i;
        }
        return result;
    }
};

template <typename T>
void print_Vec1D(vector<T> vec){
    for( auto it=vec.begin(); it != vec.end(); it++ ){
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

int main() {
    vector<int> numbers {2,7,11,15};
    Solution sol;
    print_Vec1D(sol.twoSum(numbers, 9 ));

    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}