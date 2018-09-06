#include <iostream>
#include <vector>

using namespace std;



#define __main main

class Solution
{
public:
    bool Find(vector<vector<int> > array,int target)
    {
        bool res = false;
        int row = array.size( );
        int col = array[0].size( );

        //  ���Ǵ����Ͻǵ�Ԫ������
        //  ������ҵ�Ԫ�رȵ�ǰλ��Ԫ��С, ��������
        //  ������ҵ�Ԫ�رȵ�ǰλ��Ԫ�ش�, ��������
        for(int i = row - 1, j = 0;
            (i >=0 && i < row) && (j >= 0 && j < col);)
        {
            if(target == array[i][j])
            {
                res = true;
                break;
            }
            else if(target < array[i][j])     // С��Ԫ���ڵ�ǰλ���ϲ�
            {
#ifdef __tmain
                cout <<target <<" < " <<array[i][j] <<" turn up" <<endl;
#endif // __tmain

                i--;
            }
            else
            {
#ifdef __tmain
                cout <<target <<" > " <<array[i][j] <<" turn rigt" <<endl;
#endif // __tmain
                j++;
            }
        }
        return res;
    }
};




int __main()
{
    int a1[] = { 1, 2, 8, 9, };
    int a2[] = { 2, 4, 9, 12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };
    vector<vector<int>> array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));

    Solution solu;
    cout <<solu.Find(array, 7) <<endl;
    return 0;
}
