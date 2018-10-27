#include <iostream>
#include <set>
using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



class Solution
{
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication)
    {

        *duplication = -1;

        if(CheckValidity(numbers, length) == false)
        {
            return false;
        }

        set<int> s;
        bool isDup = false;
        *duplication = -1;
        for(int i = 0; i < length; i++)
        {
            if(s.count(numbers[i]) == 1)  // 如果当前元素已经存在set中
            {
                isDup = true;
                *duplication = numbers[i];
                break;
            }
            s.insert(numbers[i]);

        }

        return isDup;
    }

    bool CheckValidity(int *numbers, int length)
    {
        //  输入数据不合法
        if(numbers == NULL || length <= 0)
        {
            return false;
        }

        //  元素必须在[0, n-1]的范围
        for(int i = 0; i < length; i++)
        {
            if(numbers[i] < 0 || numbers[i] > length - 1)
            {
                return false;
            }
        }

        return true;
    }
};
struct Bit
{
bool a:1;
char b:4;
};


int __tmain( )
{
    Solution solu;
    int result;

    int array[] = {2, 3, 1, 0, 2, 5, 3};
    if(solu.duplicate(array, 7, &result) == true)
    {
        cout <<result <<endl;
    }
    cout <<sizeof(Bit) <<endl;
    return 0;
}
