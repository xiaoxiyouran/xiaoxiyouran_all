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

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.size( ) == 0)
        {
            return 0;
        }
        else if(numbers.size( ) == 1)
        {
            return numbers[0];
        }

        int num = FindKth(numbers, 0, numbers.size( ) - 1, numbers.size( ) / 2);

        if(CheckMoerThanHalf(numbers, num) == true)
        {
            return num;
        }
        else
        {
            return 0;
        }
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

        debug <<"pivotNum = " <<pivotNum <<endl;
        while(i < j)
        {
            while(i < j && numbers[j] >= pivotNum)
            {
                debug <<"[" <<i <<", " <<j <<"] " <<numbers[j] <<" >= " <<pivotNum <<endl;
                j--;
            }
            debug <<"now we find i = " <<i <<", posJ = " <<j <<", num = " <<numbers[j] <<" < " <<pivotNum <<endl;;
            numbers[i] = numbers[j];        // ���ҵ����Ǹ�������С�����������������I��λ��
            //swap(numbers[i], numbers[j]); // Ҳ����ʹ�ý���, ����û�б�Ҫ, ��Ϊ�����λ�ò�û�����ȷ��

            while(i < j && numbers[i] <= pivotNum)
            {
                debug <<"[" <<i <<", " <<j <<"] " <<numbers[i] <<" <= " <<pivotNum <<endl;
                i++;
            }

            debug <<"now we find j = " <<i <<", posI = " <<j <<", num = " <<numbers[i] <<" > " <<pivotNum <<endl;;
            numbers[j] = numbers[i];        // ���ҵ����Ǹ����������������������Ҳ�J��λ��
            //swap(numbers[i], numbers[j]); // Ҳ����ʹ�ý���, ����û�б�Ҫ, ��Ϊ�����λ�ò�û�����ȷ��
        }

        numbers[i] = pivotNum;              //  ����λ�� i == j ���������λ��

#ifdef __tmain

        debug <<pivotNum <<" 's post is" <<i <<endl;
        for(int pos = left; pos <= right; pos++)
        {
            debug <<numbers[pos] <<" ";
        }
        debug <<endl;
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
            debug <<"left == right" <<numbers[left] <<endl;
            return numbers[left];
        }

        pivotIndex = Partition(numbers, left, right);


        if(pivotIndex < k)          //  ��ǰ���ҵ��ıȵ�K����С
        {
            // ��K��ĵ���pivot֮ǰ, ��[pivotIndex + 1, right]֮�����
            debug <<"K is in [" <<pivotIndex + 1 <<", " <<right <<"]" <<endl;
            return FindKth(numbers, pivotIndex + 1, right, k);
        }
        else if(pivotIndex > k)     //  ��ǰ���ҵ��ıȵ�K������
        {
            // ��KС����pivot֮ǰ, ��[left, pivotIndex - 1]֮�����
            debug <<"K is in [" <<left <<", " <<pivotIndex - 1 <<"]" <<endl;
            return FindKth(numbers, left, pivotIndex - 1, k);
        }
        else      //  ���ﷵ�ص�����λ��
        {
            /// return pivotIndex; ///  error
            debug <<"pivotIndex == k, " <<numbers[pivotIndex] <<endl;
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
        debug <<"num = " <<num <<", count = " <<count <<endl;

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
    int arr1[] = { 5, 5, 2, 2, 3, 3, 5, 5, 5};

    vector<int> vec1(arr1, arr1 + 9);

    Solution solu;
    cout <<solu.MoreThanHalfNum_Solution(vec1) <<endl;


    int arr2[] = { 1, 2 };

    vector<int> vec2(arr2, arr2 + 2);
    cout <<solu.MoreThanHalfNum_Solution(vec2) <<endl;
    return 0;
}
