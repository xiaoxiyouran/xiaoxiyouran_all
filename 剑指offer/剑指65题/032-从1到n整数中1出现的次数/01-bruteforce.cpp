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
    /**
     * [NumberOf1Between1AndN_Solution ͳ��1��n��������1���ֵĴ���]
     * @Author   gatieme
     * @DateTime 2016-05-01T22:03:43+0800
     * @param    n                        [����n]
     * @return                            [1��n��������1���ֵĴ���]
     */
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;

        for(int i = 1;
            i <= n;
            i++)
        {
            count += NumberOf1(i);
        }

        return count;
    }

protected:
    /**
     * [NumberOf1 ͳ��number��1���ֵĴ���]
     * @Author    gatieme
     * @DateTime 2016-05-01T22:01:08+0800
     * @param    number                   [�����������]
     * @return                            [number��1���ֵĴ���]
     */
    int NumberOf1(int number)
    {
        int count = 0;
        while(number != 0)
        {
            if(number % 10 == 1)
            {
                count++;
            }

            number /= 10;
        }

        return count;
    }
};



int __tmain( )
{
    Solution solu;
    cout <<solu.NumberOf1Between1AndN_Solution(12) <<endl;
    cout <<solu.NumberOf1Between1AndN_Solution(100) <<endl;
    cout <<solu.NumberOf1Between1AndN_Solution(1000) <<endl;
    return 0;
}
