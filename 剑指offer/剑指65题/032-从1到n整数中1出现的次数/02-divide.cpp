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
    /**
     * [NumberOf1Between1AndN_Solution ͳ��1��n��������1���ֵĴ���]
     * @Author   gatieme
     * @DateTime 2016-05-01T22:03:43+0800
     * @param    n                        [����n]
     * @return                            [1��n��������1���ֵĴ���]
     */
    int NumberOf1Between1AndN_Solution(int n)
    {
        return CountOne(n);
    }

    int CountOne(int n)
    {
        debug <<"now N = " <<n <<endl;
        long count = 0;

        if (n == 0)
        {
            debug <<"Fun(0) = " <<0 <<endl;
            count = 0;
        }
        else if (n > 1 && n < 10)
        {
            debug <<"Fun(" <<n <<") = " <<1 <<endl;
            count =  1;
        }
        else
        {
            // ����n��λ��
            long highest = n;       //��ʾ���λ������
            int bit = 0;
            while (highest >= 10)
            {
                highest /= 10;
                bit++;
            }
            //  ѭ������ʱ, bit��ʾn��λ��, ��highest�������λ������

            //int weight = (int)Math.Pow(10, bit);//�������λ��Ȩ�أ������λһ��1����Ĵ�С
            int weight = pow(10, bit);//�������λ��Ȩ�أ������λһ��1����Ĵ�С

            if (highest == 1)
            {
                debug <<"Fun(" <<n <<") = "
                      /*
                      <<"Fun(10^" <<bit <<" - 1) + "
                      <<"Fun(" <<n <<" - 10^" <<bit <<") + "
                      <<"(" <<n <<" - 10^" <<bit <<" + 1) = "
                      */
                      <<"Fun(" <<weight <<" - 1) + "
                      <<"Fun(" <<n <<" - " <<weight <<") + "
                      <<"(" <<n <<" - " <<weight <<" + 1)" <<endl;
                count = CountOne(weight - 1)
                      + CountOne(n - weight)
                      + (n - weight + 1);
                debug <<"will continue " <<weight - 1 <<", " <<n - weight <<endl <<endl;
            }
            else
            {
                debug <<"Fun(" <<n <<") = "
                      /*
                      <<"Fun(10^" <<bit <<" - 1) + "
                      <<"Fun(" <<n <<" - 10^" <<bit <<") + "
                      <<weight <<" = "
                      */
                      <<highest <<" * Fun(" <<weight <<" - 1) + "
                      <<"Fun(" <<n <<" - " <<highest <<" * " <<weight <<") + "
                      <<weight <<endl;
                count = highest * CountOne(weight - 1)
                      + CountOne(n - highest * weight)
                      + weight;
                debug <<"Now will continue " <<weight - 1 <<", " <<n - highest * weight <<endl <<endl;
            }
        }

        return count;
    }
};



int __tmain( )
{
    Solution solu;

    //cout <<solu.NumberOf1Between1AndN_Solution(12) <<endl;
    //cout <<solu.NumberOf1Between1AndN_Solution(132) <<endl;
    cout <<solu.NumberOf1Between1AndN_Solution(232) <<endl;

    return 0;
}
