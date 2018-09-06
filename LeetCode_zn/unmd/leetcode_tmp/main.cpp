#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int MinInOrder(int* numbers, int index1, int index2){
    int result = numbers[index1];
    for(int i = index1 + 1; i <= index2; i++){
        if( result > numbers[i] )
            result = numbers[i];
    }
    return  result;
}

int Min(int* numbers, int length){
    if ( numbers == NULL || length <=0 )
        throw new std::invalid_argument("Invalid parameters.");
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while (numbers[index1] >= numbers[index2]){
        if (index2 - index1 == 1){      // 前面比后面大， 刚好找到最小值
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2) / 2;

        // 如果三者相等，只能顺序查找
        if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1] )
            return MinInOrder(numbers, index1, index2);

        if ( numbers[indexMid] >= numbers[index1] )
            index1 = indexMid;
        else if (numbers[indexMid] <= numbers[index2] )
            index2 = indexMid;
    }

    return numbers[indexMid];
}

int main() {
   int numbers[5] = {1, 0, 1, 1, 1};
    cout << Min(numbers, 5) << endl;    // 0

    return 0;
}