#include <iostream>
#include <vector>
using namespace std;

//  ���Կ���
#define __tmain main


#ifdef __tmain
    #define dout cout
#else
    #define dout 0 && cout
#endif // __tmain


class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        for(int i = 0; i < rotateArray.size( ); i++)
        {
            //  ����Ԫ�غ����ĸ�������С��Ԫ��
            if(rotateArray[i] > rotateArray[i + 1])
            {
                return rotateArray[i + 1];
            }
        }
        //  ����Ļ�, ��ת����Ϊ0, ��һ��Ԫ�ؼ�����СԪ��
        return rotateArray[0];
    }

    int minNumberInRotateArray(int* rotateArray, int length)
    {
        int low = 0, high = length - 1;

        while(low < high)
        {
            if(rotateArray[low] < rotateArray[high])
            {

            }
        }

    }
};


int __tmain( )
{
    dout <<"test" <<endl;
    return 0;
}
