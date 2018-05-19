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
public :
    static int pre;
    static int post;
    int temp;
    int Fibonacci(int n)
    {
        /**
         * ÿ��Fibonacci���ý�����:
         *      pre:  ��Ķ���Fibonacci(n)��ֵ
         *      post: ��Ķ���Fibonacci(n-1)��ֵ
         */

        // if   n = 0            #=> 0
        // else n = 1 || n = 2   #=> 1
        if(n <= 2)
        {
            if (n == 0) return 0;
            pre = 1;
            post = 1;
            return pre;
        }

        // n Ϊ������ ������һ������ �����ص�ʱ
        //        pre��        f(n) = f(n - 1) + f(n - 2)
        //        post��   f(n - 1) = f(n) - f(n - 2)
        if(n%2 == 1)
        {
            Fibonacci(n-1);
            pre = pre + post;
            post = pre - post;
            return pre;
        }

        // nΪż��ʱ���ϳ���
        // �����ص�ʱ,f(n) ͨ�� f(n/2) ������:
        //
        //  �� n = 2k��
        //          f(2k) = f(k)  * f(k + 1) + f(k-1) * f(k)
        //                = f(k) * [f(k) + f(k - 1)] + f(k-1) * f(k)
        //                = f(k) ^ 2 + 2 * f(k) * f(k - 1)
        // �� n = 2k-1��
        //      f(2k - 1) = f(k) * f(k) + f(k - 1)  * f(k - 1)
        //                = f(k)^2 + f(k - 1)^2
        //
        Fibonacci(n/2);
        temp = pre;
        // f(2k) = f(k)^2 + 2 * f(k) * f(k - 1)
        pre = pre * pre + 2 * pre * post;
        // f(2k - 1) = f(k) * f(k) + f(k - 1) * f(k - 1)
        post = temp*temp + post*post;
        return pre;
    }
};

int Solution::pre = 0;
int Solution::post = 0;


int __tmain( )
{
    Solution solu;
    cout <<solu.Fibonacci(3) <<endl;;

    return 0;
}
