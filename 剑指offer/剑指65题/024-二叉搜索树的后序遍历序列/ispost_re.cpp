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

        return judge(sequence, 0, sequence.size( ) - 1);
    }

    /// 2, 9, 5, 16, 17, 15, 19, 18, 12
    bool judge(vector<int>  &sequence, int left, int right)
    {
        if(left >= right)
        {
            return true;
        }

        /// ��һ���Ԫ�ض��ȸ�Ԫ�ش�
        int mid = right - 1;
        while (sequence[mid] > sequence[right])
        {
            mid--;
        }
        /// ��ôǰ���Ԫ�ض�Ӧ�ñȸ�С
        int i = left;
        while (i < mid && sequence[i] < sequence[right])
        {
            i++;
        }
        if (i < mid)
        {
            return false;
        }
#ifdef __tmain
        printf("left : ");
        for(int i = left; i <= mid; i++)
        {
            cout <<sequence[i] <<" ";
        }
        cout <<endl;
        printf("right : ");
        for(int i = mid + 1; i < right; i++)
        {
            cout <<sequence[i] <<" ";
        }
        cout <<endl;
        cout <<"root : " <<sequence[right] <<endl;
#endif // __tmain

        ///  �������Ǿͻ��ֳ�����
        ///  [left, mid] ��������
        ///  [mid + 1, right - 1] ��������
        ///  right �Ǹ��ڵ�
        return judge(sequence, left, mid) && judge(sequence, mid + 1, right - 1);
    }
};


int __tmain( )
{

    int a[] = { 2, 9, 5, 16, 17, 15, 19, 18, 12, };

    vector<int> vec(a, a + 9);

    Solution solu;
    cout <<solu.VerifySquenceOfBST(vec) <<endl;
    return 0;
}
