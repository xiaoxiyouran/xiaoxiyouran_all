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
    int jumpFloorII(int target)
    {
        long long ret;
		if(target >= 32)//����8�ֽں���Ҫ��������λ���������
		{
			ret = 1 << 30;
			ret = ret << (target - 31);
		}
		else
        {
			ret = 1 << (target - 1);
        }

        return ret;
    }
};



int __tmain( )
{
    Solution solu;
    cout <<solu.jumpFloorII(2) <<endl;;

    return 0;
}
