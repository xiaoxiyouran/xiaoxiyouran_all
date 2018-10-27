#include <iostream>
#include <vector>

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
    void reOrderArray(vector<int> &array)
    {
        if(array.size( ) <= 1)
        {
            return ;
        }
        vector<int>::iterator left = array.begin( );
        vector<int>::iterator right = array.end( ) - 1;

        // ����˳��������ֻ��deque��vector�����ĵ�����֧�ִ�С�ıȽϺ��������㡣

        while(left < right)
        //while(left != right)
        {
            //system("PAUSE");

            //  left����ƶ�ָ���һ��ż��
            while(left < right && (*left & 0x01) == 1)
            {
                left++;
            }

            // right��ǰ�ƶ�ָ���һ������
            while(left < right && (*right &0x01) == 0)
            {
                right--;
            }
            debug <<"left = " <<*left <<", right = " <<*right <<endl;

            if(left < right)
            {
                swap(*left, *right);
            }
        }

    }
};


int __tmain( )
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7};
    vector<int> vec(array, array + 7);
    for(int i = 0; i < 7; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    Solution solu;
    solu.reOrderArray(vec);

    for(int i = 0; i < 7; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    return 0;
}
