#include <iostream>

using namespace std;

//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



class Solution
{
public:
    double Power(double base, int exponent)
    {
        double res = 1;
        for(int i = 0; i < exponent; i++)
        {
            res *= base;
        }

        return res;
    }
};



int __tmain( )
{
    Solution solu;

    cout <<solu.Power(2, 0) <<endl;
    cout <<solu.Power(2, -3) <<endl;
    return 0;
}
