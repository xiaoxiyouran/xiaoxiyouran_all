#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

#define ddebug 0 && cout

class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> numbers, int k)
    {
        int kth;
        vector<int> res;

        for(int i = 0; i < k; i++)
        {
            kth = FindKth(numbers, 0, numbers.size( ) - 1, i);
            debug <<i <<" th is " <<kth <<endl;
            res.push_back(kth);
        }

        return res;
    }


    /**
     * [Partition ��������Ļ��ֺ���, ��������(left�±�Ԫ��)�������������Ӧ��������λ��,
      ���±�Ϊleft��Ԫ���ǵڼ����Ԫ��
     * @Author    gatieme
     * @DateTime  2016-04-26T11:11:34+0800
     * @param     numbers                  [�����ֵ�����]
     * @param     left                     [���������ݵ���ʼλ��]
     * @param     right                    [���������ݵĽ���λ��]
     * @return                             [���������������������Ӧ���ڵ�λ��]
     */
    int Partition(vector<int> &numbers, int left, int right)
    {
        int i = left, j = right;

        ///  ����ѡ���һ��Ԫ����Ϊ��׼
        ///  ���Ҳ�������ѡ��
        int pivotIndex = left, pivotNum = numbers[pivotIndex];

        ddebug <<"pivotNum = " <<pivotNum <<endl;
        while(i < j)
        {
            while(i < j && numbers[j] >= pivotNum)
            {
                ddebug <<"[" <<i <<", " <<j <<"] " <<numbers[j] <<" >= " <<pivotNum <<endl;
                j--;
            }
            ddebug <<"now we find i = " <<i <<", posJ = " <<j <<", num = " <<numbers[j] <<" < " <<pivotNum <<endl;;
            numbers[i] = numbers[j];        // ���ҵ����Ǹ�������С�����������������I��λ��
            //swap(numbers[i], numbers[j]); // Ҳ����ʹ�ý���, ����û�б�Ҫ, ��Ϊ�����λ�ò�û�����ȷ��

            while(i < j && numbers[i] <= pivotNum)
            {
                ddebug <<"[" <<i <<", " <<j <<"] " <<numbers[i] <<" <= " <<pivotNum <<endl;
                i++;
            }

            ddebug <<"now we find j = " <<i <<", posI = " <<j <<", num = " <<numbers[i] <<" > " <<pivotNum <<endl;;
            numbers[j] = numbers[i];        // ���ҵ����Ǹ����������������������Ҳ�J��λ��
            //swap(numbers[i], numbers[j]); // Ҳ����ʹ�ý���, ����û�б�Ҫ, ��Ϊ�����λ�ò�û�����ȷ��
        }

        numbers[i] = pivotNum;              //  ����λ�� i == j ���������λ��

#ifdef __tmain

        ddebug <<pivotNum <<" 's post is" <<i <<endl;
        for(int pos = left; pos <= right; pos++)
        {
            ddebug <<numbers[pos] <<" ";
        }
        ddebug <<endl;
        //system("PAUSE");

#endif // __tmain

        return i;
    }

    /**
     * [FindKth ���������е�K���Ԫ��]
     * @Author    gatieme
     * @DateTime  2016-04-26T11:18:00+0800
     * @param     numbers                  [������Ԫ�����ڵ�����]
     * @param     left                     [������ʼԪ�ص�λ��]
     * @param     right                    [������ֹԪ�ص�λ��]
     * @param     k                        [��K���Ԫ��]
     * @return                             [�����е�K���Ԫ�ص�ֵ]
     */
    int FindKth(vector<int> &numbers, int left, int right, int k)
    {
        int res;
        int pivotIndex = left + 1;

        if(left == right)
        {
            ddebug <<"left == right" <<numbers[left] <<endl;
            return numbers[left];
        }

        pivotIndex = Partition(numbers, left, right);


        if(pivotIndex < k)          //  ��ǰ���ҵ��ıȵ�K����С
        {
            // ��K��ĵ���pivot֮ǰ, ��[pivotIndex + 1, right]֮�����
            ddebug <<"K is in [" <<pivotIndex + 1 <<", " <<right <<"]" <<endl;
            return FindKth(numbers, pivotIndex + 1, right, k);
        }
        else if(pivotIndex > k)     //  ��ǰ���ҵ��ıȵ�K������
        {
            // ��KС����pivot֮ǰ, ��[left, pivotIndex - 1]֮�����
            ddebug <<"K is in [" <<left <<", " <<pivotIndex - 1 <<"]" <<endl;
            return FindKth(numbers, left, pivotIndex - 1, k);
        }
        else      //  ���ﷵ�ص�����λ��
        {
            /// return pivotIndex; ///  error
            ddebug <<"pivotIndex == k, " <<numbers[pivotIndex] <<endl;
            return numbers[pivotIndex];
        }
    }


    /**
     * [CheckMoerThanHalf ���numԪ��������numbers�г��ֵĴ����Ƿ񳬹�һ��]
     * @AuthorHTL
     * @DateTime  2016-04-26T11:20:35+0800
     * @param     numbers                  [�����������]
     * @param     num                      [����ѯ��Ԫ��]
     * @return                             [���Ԫ��num������numbers�г��ֵĴ����������鳤�ȵ�һ���򷵻�true, ���򷵻�false]
     */
    bool CheckMoerThanHalf(vector<int> numbers, int num)
    {
        int count = 0;
        for(int i = 0; i < numbers.size( ); i++)
        {
            if(numbers[i] == num)
            {
                count++;
            }
        }
        ddebug <<"num = " <<num <<", count = " <<count <<endl;

        if(count > numbers.size( ) / 2)
        {
            return true;
        }
        else
        {
            return false;
        }
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

