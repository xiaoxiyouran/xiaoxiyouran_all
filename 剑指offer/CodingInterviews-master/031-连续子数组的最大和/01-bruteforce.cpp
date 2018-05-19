#include <iostream>
#include <vector>
#include <iterator>

#include <climits>

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
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if(array.size( ) == 0)
        {
            return 0;
        }
#ifdef __tmain
        cout <<"vector : ";
        copy(array.begin( ), array.end( ), ostream_iterator<int>(cout, " "));
        cout <<endl;
#endif  //  __tmain
        int sum, maxSum = INT_MIN;
        //  ѭ��ÿ��������Ŀ�ʼλ��
        for(unsigned int i = 0; i < array.size( ); i++)
        {
            sum = 0;
            //  ѭ����i��ʼ������������
            for(unsigned int j = i; j < array.size( ); j++)
            {
                sum += array[j];        //  ������ĺ�array[i] ~ array[j]
                if(sum > maxSum)
                {
                    debug <<"[" <<i <<", " <<j <<"] = " <<sum <<endl;
                    maxSum = sum;
                }
            }
        }
        return maxSum;
    }
};

int __tmain( )
{
    Solution solu;

    int arr1[] = { 6, -3, -2, 7, -15, 1, 2, 2};
    vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
    cout <<"maxSum = " <<solu.FindGreatestSumOfSubArray(vec1) <<endl;

    int arr2[] = { -2, -8, -1, -5, -9 };
    vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
    cout <<"maxSum = " <<solu.FindGreatestSumOfSubArray(vec2) <<endl;

    return 0;
}
