#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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
protected:
    vector<int> m_res;
public:

    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k)
    {
        m_res.clear( );

        if(numbers.size( ) == 0 || numbers.size() < k)
        {
            return m_res;
        }
//        m_res.clear( );
//        LeastKNumbers_BySort(numbers, k);
//
//        m_res.clear( );
//        LeastKNumbers_BySelectSort(numbers, k);
//
//        m_res.clear( );
//        LeastKNumbers_ByBubbleSort(numbers, k);


        LeastKNumbers_ByCountSort(numbers, k);


        return m_res;
    }

    ///  ��������ǰK������
    vector<int> LeastKNumbers_BySort(vector<int> numbers, int k)
    {
        debug <<endl <<"line " <<__LINE__ <<"in function : "<<__func__ <<endl <<endl;

        //vector<int> res;

        sort(numbers.begin( ), numbers.end( ));
        for(int i = 0; i < k; i++)
        {
            debug <<numbers[i] <<" ";
            m_res.push_back(numbers[i]);
        }
        debug <<endl;

        return m_res;
    }

    ///  ����ѡ������, K���ҳ�ǰK������
    ///  ����ѡ������ÿ�˽�����ǰi�����ֶ��������K�˼����ҳ�ǰKС������
    vector<int> LeastKNumbers_BySelectSort(vector<int> numbers, int k)
    {
        debug <<endl <<"line " <<__LINE__ <<" in function : "<<__func__ <<endl <<endl;

        int i, j, index;
        int length = numbers.size( ) -1;
        for(i = 0; i < k/*length*/; i++)             // ѭ��ÿ������
        {
            index = i;
            for(j = i + 1; j < length; j++)
            {
                if(numbers[j] < numbers[index])
                {
                    index  = j;                 // �ҵ���ǰ��ֵԪ�ص��±�
                }
            }
            if(index != i)
            {
                swap(numbers[i], numbers[index]);     // ����ֵ���浽Ӧ�������λ��
            }
            m_res.push_back(numbers[i]);

#ifdef __tmain

            debug <<"pos = " <<index <<", num = " <<numbers[i] <<endl;
            debug <<"when " <<i <<" select sort, the least " <<i <<" numbers is sorted" <<endl;

            for(int pos = 0; pos <= i; pos++)
            {
                debug <<numbers[pos] <<" ";
            }
            debug <<endl;

#endif  //  __tmain

        }

        return m_res;
    }

    ///  ����ð������, K���ҳ�ǰK������
    vector<int> LeastKNumbers_ByBubbleSort(vector<int> numbers, int k)
    {
        debug <<endl <<"line " <<__LINE__ <<" in function : "<<__func__ <<endl <<endl;

        int j/*����ÿ��ѭ��*/, i/*�����������ݵıȽ�ѭ��*/;
        // �������
        int length = numbers.size( );
        for(i = 0; i < k/*length - 1*/; i++)        // ���ƽ���length-1��ѭ��
        {
            for(j = length - i - 1; j > 0; j--)   // ÿ��ѭ���Ƚ�length-1-j��
            {
                if(numbers[j - 1] > numbers[j])    // �����ǰ��Ԫ�����һ��Ԫ�ز������������
                {
                    swap(numbers[j - 1], numbers[j]);
                }

            }
            m_res.push_back(numbers[i]);

#ifdef __tmain
            debug <<"pos = " <<i <<", num = " <<numbers[i] <<endl;
            debug <<"when " <<i <<" bubble sort, the least " <<i <<" numbers is sorted" <<endl;

            for(int pos = 0; pos <= i; pos++)
            {
                debug <<numbers[pos] <<" ";
            }
            debug <<endl;

#endif  //  __tmain
        }

        return m_res;
    }


    ///  ���ü�������
    vector<int> LeastKNumbers_ByCountSort(vector<int> numbers, int k)
    {
        int i, count;
        int num[1000];
        memset(num, '\0', 1000);

        for(i = 0; i < numbers.size( ); i++)
        {
            num[numbers[i]]++;
            debug <<numbers[i] <<endl;
        }
        for(i = 0, count = 0; i < 1000 && count < k; i++)
        {
            if(num[i] != 0)
            {
                count++;
                debug <<i <<" ";
                m_res.push_back(i);
            }
        }
        debug <<endl;

        return m_res;
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
