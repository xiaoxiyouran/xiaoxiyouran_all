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
    int Fibonacci(int n)
    {
        if(n <= 1)
        {
            return n;
        }
        else
        {
            return Fibonacci(n - 1) + Fibonacci(n - 2);
        }
    }
};

int __tmain( )
{
    Solution solu;
    cout <<solu.Fibonacci(3) <<endl;;

    return 0;
}
