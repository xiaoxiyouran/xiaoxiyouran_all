#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.size( ) == 0)
        {
            return 0;
        }
        else if(numbers.size( ) == 1)
        {
            return numbers[0];
        }

        int num = numbers[0], count = 1;

        //  ��ع���
        for(int i = 1; i < numbers.size( ); i++)
        {
            if(numbers[i] == num)    /// �Ѿ�, ����������
            {
                count++;
            }
            else                    /// �о�, һ��ʿ��ͬ���ھ�
            {
                count--;
            }
            debug <<"numbers[i] = " <<numbers[i] <<", count = " <<count <<endl;

            // ����ʿ���Ѿ�����
            if(count == 0)
            {
                num = numbers[i];    //  ��������������ص�ʿ��
                count = 1;
            }
        }

        debug <<"find num = " <<num <<endl;
        ///  �ټ�һ��ѭ������¼���ʿ���ĸ������Ƿ��������һ�㼴��
        count = 0;
        for(int i = 0; i < numbers.size( ); i++)
        {
            if(numbers[i] == num)
            {
                count++;
            }
        }

        if(count > numbers.size( ) / 2)
        {
            debug <<"num = " <<num <<", count = " <<count <<endl;
            return num;
        }
        else
        {
            return 0;
        }
    }
};


int __tmain( )
{
    int arr1[] = { 5, 5, 2, 2, 3, 3, 5, 5, 5};

    vector<int> vec1(arr1, arr1 + 9);

    Solution solu;
    cout <<solu.MoreThanHalfNum_Solution(vec1) <<endl;


    int arr2[] = { 1, 2 };

    vector<int> vec2(arr2, arr2 + 2);
    cout <<solu.MoreThanHalfNum_Solution(vec2) <<endl;
    return 0;
}
