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
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if(sequence.size( ) == 0)
        {
            return false;
        }
        int count = 0;
        int left = 0, right = sequence.size( ) - 1;
        while(right > 0)
        {
            //  ǰһ���Ԫ�ض�С��size
            while(sequence[left] < sequence[right])
            {
                left++;
                count++;

            }
            // ѭ������ʱ, left�ǵ�һ�����ڸ���Ԫ�ص�λ��
            // ������Ԫ�ض�Ӧ�ñȸ���
            while(sequence[left] > sequence[right])
            {
                left++;
                count++;
            }
            //  ���������, ѭ������ʱ, leftӦ�õ���right
            debug <<left <<" " <<right <<endl;
            if(left < right)
            {
                return false;
            }
            right--;
            left = 0;
        }
        cout <<count <<endl;
        //  ���ѭ��һֱ�ߵ�right == 0����ֹ, ˵�������������Ķ���
        return true;
    }
};


int __tmain( )
{
//     10
//   6    14
//  8   12  16
//4



    int a[] = { 2, 9, 5, 16, 17, 15, 19, 18, 12, };

    vector<int> vec(a, a + 9);

    Solution solu;
    cout <<solu.VerifySquenceOfBST(vec) <<endl;
    return 0;
}
