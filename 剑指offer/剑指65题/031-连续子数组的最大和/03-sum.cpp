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
        debug <<"vector : ";
        copy(array.begin( ), array.end( ), ostream_iterator<int>(cout, " "));
        debug <<endl;
#endif  // __tmain

        int maxNum = INT_MIN;
        int sum = 0, maxSum = INT_MIN;
        for(int i = 0; i < (int)array.size( ); i++)
        {
            sum += array[i];
            debug <<sum <<endl;

            if(sum < 0)     ///  �����ǰ��С��0, ��������, ���¿�ʼ�ۼ�
            {
                sum = 0;
            }
            else if(sum > maxSum)   ///  ����Ļ��ۼƵ�ǰ��
            {
                maxSum = sum;
            }

            ///  ���������е����ֵ
            ///  �����������Ϊ���ų���������ȫΪ�������������
            if(array[i] > maxNum)
            {
                maxNum = array[i];
            }
        }

        ///  ����������ֵ����0, ��ô���Ǿ�ֱ�ӷ����ۼƵ�����
        ///  ����������ֵΪ����, ˵���������鶼�Ǹ���, ��ô�ͷ����������ֵ
        return (maxNum > 0) ? maxSum : maxNum;
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
