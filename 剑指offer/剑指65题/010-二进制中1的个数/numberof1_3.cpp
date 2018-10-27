#include <iostream>

using namespace std;

//  µ÷ÊÔ¿ª¹Ø
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class Solution
{
public:
    int NumberOf1(int n)
    {
        int count = 0;

        while(n)
        {
            ++count;
            n = (n - 1) & n;
        }
        return count;
    }

};


#include <cmath>

int __tmain( )
{
    cout <<sizeof(long) <<endl;
    Solution solu;
    cout <<solu.NumberOf1(1) <<endl;;
    cout <<solu.NumberOf1(2) <<endl;;
    cout <<solu.NumberOf1(-3) <<endl;;
    cout <<solu.NumberOf1(-2147483648) <<endl;;

    return 0;
}
