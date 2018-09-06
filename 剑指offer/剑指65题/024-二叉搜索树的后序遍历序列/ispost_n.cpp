#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Solution {
public:
	/*
	step1�����һ��Ϊ���ڵ㣻
	step2���Ӹ��ڵ����߿�ʼ��ǰ�������ҵ���һ��������Ľڵ���Ϊ����������Ϊright
	step3��������������߿�ʼ��ǰ�������ҵ���һ������С�Ľڵ���Ϊ����������Ϊleft
	step4���ж�( left, right )�е�ֵ�Ƿ񶼱ȸ��ڵ������бȸ��ڵ�С���򷵻�false
	step5: �ж�( 0, left )�е�ֵ�Ƿ񶼱ȸ��ڵ�С������бȸ��ڵ����򷵻�false
	step6: ����true

	ʱ�临�Ӷȣ�O(n), �ռ临�Ӷ�: O(1)
	û��֤���������Ǵ���ͨ���ˣ�����������û��
	*/
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) return true;
		int len = sequence.size();

		int left = -1, right = -1;
		for (int i = len - 2; i >= 0; --i)
		{
			if (right == -1 && sequence[i] > sequence[len - 1])
                right = i;
			if (left == -1 && sequence[i] < sequence[len - 1])
                left = i;
		}
        cout <<"left = " <<left <<", right = " <<right <<endl;
		for (int i = right - 1; i > left; --i)
        {
            if (sequence[i] < sequence[len - 1])
            {
                return false;
            }
        }
		for (int i = left - 1; i > 0; --i)
		{
			if (sequence[i] > sequence[len - 1])
            {

                return false;
            }

        }
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
