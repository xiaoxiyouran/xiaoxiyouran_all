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
     * [Partition 快速排序的划分函数, 返回枢轴(left下标元素)在排序的数组中应该所处的位置,
      即下标为left的元素是第几大的元素
     * @Author    gatieme
     * @DateTime  2016-04-26T11:11:34+0800
     * @param     numbers                  [待划分的数组]
     * @param     left                     [待划分数据的起始位置]
     * @param     right                    [待划分数据的结束位置]
     * @return                             [返回枢轴在排序后数组中应该在的位置]
     */
    int Partition(vector<int> &numbers, int left, int right)
    {
        int i = left, j = right;

        ///  我们选择第一个元素作为基准
        ///  这个也可以随机选择
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
            numbers[i] = numbers[j];        // 将找到的那个比枢轴小的数，放在枢轴左侧I的位置
            //swap(numbers[i], numbers[j]); // 也可以使用交换, 但是没有必要, 因为枢轴的位置并没有最后确定

            while(i < j && numbers[i] <= pivotNum)
            {
                debug <<"[" <<i <<", " <<j <<"] " <<numbers[i] <<" <= " <<pivotNum <<endl;
                i++;
            }

            debug <<"now we find j = " <<i <<", posI = " <<j <<", num = " <<numbers[i] <<" > " <<pivotNum <<endl;;
            numbers[j] = numbers[i];        // 将找到的那个比枢轴大的数，放在枢轴右侧J的位置
            //swap(numbers[i], numbers[j]); // 也可以使用交换, 但是没有必要, 因为枢轴的位置并没有最后确定
        }

        numbers[i] = pivotNum;              //  最后的位置 i == j 就是枢轴的位置

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
     * [FindKth 查找数组中第K大的元素]
     * @Author    gatieme
     * @DateTime  2016-04-26T11:18:00+0800
     * @param     numbers                  [待查找元素所在的数组]
     * @param     left                     [数据起始元素的位置]
     * @param     right                    [数据终止元素的位置]
     * @param     k                        [第K大的元素]
     * @return                             [数组中第K大的元素的值]
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


        if(pivotIndex < k)          //  当前查找到的比第K个数小
        {
            // 第K大的的在pivot之前, 在[pivotIndex + 1, right]之间查找
            debug <<"K is in [" <<pivotIndex + 1 <<", " <<right <<"]" <<endl;
            return FindKth(numbers, pivotIndex + 1, right, k);
        }
        else if(pivotIndex > k)     //  当前查找到的比第K个数大
        {
            // 第K小的在pivot之前, 在[left, pivotIndex - 1]之间查找
            debug <<"K is in [" <<left <<", " <<pivotIndex - 1 <<"]" <<endl;
            return FindKth(numbers, left, pivotIndex - 1, k);
        }
        else      //  这里返回的是其位置
        {
            /// return pivotIndex; ///  error
            debug <<"pivotIndex == k, " <<numbers[pivotIndex] <<endl;
            return numbers[pivotIndex];
        }
    }


    /**
     * [CheckMoerThanHalf 检查num元素在数组numbers中出现的次数是否超过一半]
     * @AuthorHTL
     * @DateTime  2016-04-26T11:20:35+0800
     * @param     numbers                  [待处理的数组]
     * @param     num                      [待查询的元素]
     * @return                             [如果元素num在数组numbers中出现的次数超过数组长度的一半则返回true, 否则返回false]
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
