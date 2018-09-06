#include <iostream>
#include <vector>
#include <algorithm>


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
    class greater_class
    {
      public:
        bool operator()(int a, int b)
        {
            return a > b;
        }
    };

    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k)
    {
        return LeastKNumbers_ByMinHeap(numbers, k);
    }

    vector<int> LeastKNumbers_ByMinHeap(vector<int> numbers, int k)
    {
        vector<int> res;

        if(numbers.size( ) == 0 || numbers.size( ) < k)
        {
            return res;
        }
        make_heap(numbers.begin( ), numbers.end( ), greater_class());

        for(int i = 0; i < k; i++)
        {

            //  ��С��Ԫ����ջ��
            debug <<numbers[0] <<" ";
            res.push_back(numbers[0]);

            ///  һ�����ֲ���������
            // [1]  --  �����, Ȼ�����������
            //numbers.erase(numbers.begin( ));
            //sort_heap(numbers.begin( ), numbers.end( ));

            // [2]  --  ��Ȼ�Ӷѳ��������ջ��Ԫ��
            pop_heap(numbers.begin( ), numbers.end( ), greater_class( ));   // ����һ��Ԫ�غ�ʣ�µ����ؽ��� heap���Ա���heap������
            numbers.pop_back();         // vector ɾ��ĩβԪ��

        }

        return res;
    }


};


int __tmain( )
{

    int arr[ ] = { 4, 5, 1, 6, 2, 7, 3, 8 };
    std::vector<int> vec(arr, arr + 8);

    Solution solu;
    solu.GetLeastNumbers_Solution(vec, 4);
    return 0;
}
