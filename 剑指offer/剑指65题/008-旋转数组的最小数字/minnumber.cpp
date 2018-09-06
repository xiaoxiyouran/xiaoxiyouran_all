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
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size( ) == 0)
        {
            debug <<"�Ƿ�����" <<endl;
            return 0;
        }

        int low = 0, high = rotateArray.size( ) - 1;
        //  �������������ǰ��0��Ԫ�ذᵽ���棬Ҳ����˵��ʵû����ת��
        //  ��ô��0��Ԫ�ؾ�����С��Ԫ��
        //  ������ǽ�mid��ʼ��Ϊ0
        int mid = low;
#ifdef __tmain
        if(rotateArray[low] < rotateArray[high])
        {
            debug <<"����δ����ת" <<endl;
        }
#endif
        while(rotateArray[low] >= rotateArray[high])
        {
            //  ���ǰһ��Ԫ�����һ��Ԫ�ز�һλ
            //  ˵���ҵ��������С��Ԫ��
            if(high - low == 1)
            {
                mid = high;
                debug <<"min = " <<low <<", high = " <<high <<endl;
                break;
            }

            mid = (low + high) / 2;
            debug <<rotateArray[low] <<", " <<rotateArray[mid] <<", " <<rotateArray[high] <<endl;

            // rotateArray[low] rotateArray[mid] rotateArray[high]�������
            // �޷�ȷ���м�Ԫ��������ǰ�滹�Ǻ���ĵ���������
            // ֻ��˳�����
            if(rotateArray[low] == rotateArray[mid] && rotateArray[mid] == rotateArray[high])
            {
                debug <<"low == mid == high, so we should order it" <<endl;
                return MinOrder(rotateArray, low, high);
            }

            //  ������м�Ԫ��λ��ǰ��ĵ��������飬��ô��Ӧ�ô��ڻ��ߵ��ڵ�һ��ָ��ָ���Ԫ��
            if(rotateArray[mid] >= rotateArray[low])
            {
                low = mid;          //  ��ʱ��С��Ԫ��λ���м�Ԫ�صĺ���
            }
            // ����м�Ԫ��λ�ں���ĵ��������飬��ô��Ӧ��С�ڻ��ߵ��ڵڶ���ָ��ָ ���Ԫ��
            else if(rotateArray[mid] <= rotateArray[high])
            {
                high = mid;         //  ��ʱ��С��Ԫ��λ���м�Ԫ�ص�ǰ��
            }
        }

        return rotateArray[mid];
    }

private:
    // ˳��Ѱ����Сֵ
    int MinOrder(vector<int> &num, int low, int high)
    {
        int result = num[low];
        for(int i = low + 1; i < high; i++)
        {
            if(num[i] < result)
            {
                result = num[i];
            }//if
        }//for
        return result;
    }
};

int __tmain( )
{

    int a[] = { 1, 0, 1, 1, 1,};
    vector<int> vec(a, a + 5);

    Solution solu;
    cout <<solu.minNumberInRotateArray(vec) <<endl;

    return 0;
}
