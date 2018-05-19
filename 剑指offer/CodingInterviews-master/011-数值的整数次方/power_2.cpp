#include <iostream>
#include <cmath>
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
        //  ָ��Ϊ0����������ܵ����Ƕ��ٶ�Ӧ����0
        if(exponent == 0)
        {
            return 1.0;
        }

        //  ָ��Ϊ����������£���������Ϊ0
        if(Equal(base, 0.0) == true && exponent < 0)
        {
            debug <<"�쳣, ָ��Ϊ����������£���������Ϊ0" <<endl;
            return 0.0;
        }

        double res = 1.0;
        if(exponent > 0.0)
        {
            res = PowerNormal(base, exponent);
        }
        else
        {
            res = PowerNormal(base, -exponent);
            res = 1 / res;
        }

        return res;
    }

private :
    double PowerNormal(double base, int exponent)
    {

        double res = 1;
        for(int i = 0; i < exponent; i++)
        {
            res *= base;
        }

        return res;

    }
    double Equal(double left, double right)
    {
        if(fabs(left - right) <  0.0000001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};



int __tmain( )
{
    Solution solu;

    cout <<solu.Power(2, 0) <<endl;
    cout <<solu.Power(2, -3) <<endl;
    return 0;
}
