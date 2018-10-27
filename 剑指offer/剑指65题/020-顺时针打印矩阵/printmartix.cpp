#include <iostream>
#include <vector>
#include <cassert>
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
    vector<int> printMatrix(vector<vector<int> > matrix)
    {

        int row = matrix.size( );
        int col = matrix[0].size( );

        int left = 0, right = col, up = 0, down = row;      //  ���Ƶ�ǰ���������ķ�Χ����ROW[left, right), COL[left, right)

        int x = 0, y = 0;                                   //  ��ǰ�������±�
        int count = 0, max_count = row * col;               //  ��ǰ���������ݵĸ���

        vector<int> res;
        res.push_back(matrix[x][y]);

        for(count = 1; count < max_count;)
        {
            //  turn right y++
            for(y++; y < right && count < max_count; y++)
            {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " <<count <<endl;
                count++;
            }
#ifdef __tmain
            assert(right == y);
            assert(up == x);
            system("PAUSE");
#endif // __tmain
            y--;        //  ���һ�ε�ʱ��, y == right��, �����˷�Χ��Ҫ����
            up++;       //  �������Ժ�, ��ô��ǰ���up == x�Ѿ��������ˣ��������ٱ�����, ���up++



            //  turn down x++
            for(x++; x < down && count < max_count; x++)
            {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " <<count <<endl;
                count++;
            }
#ifdef __tmain
            assert(down  == x);
            assert(right - 1 == y);
            system("PAUSE");
#endif // __tmain
            x--;            //  ���һ�ε�ʱ��, x == down, �����˷�Χ��Ҫ����
            right--;        //  �������Ժ�, ��ô��ǰ������right - 1 == y�Ѿ��������ˣ��������ٱ�����, ���right--



            //  turn left y--
            for(y--; y >= left && count < max_count; y--)
            {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " <<count <<endl;
                count++;
            }
#ifdef __tmain
            assert(down - 1 == x);
            assert(left - 1 == y);
            system("PAUSE");
#endif // __tmain
            y++;            //  ���һ�ε�ʱ��, y == left - 1, �����˷�Χ��Ҫ����
            down--;         //  �������Ժ�, ��ô��ǰ������(down - 1) == x�Ѿ��������ˣ��������ٱ�����, ���down--

            //  turn uo x--
            for(x--; x >= up && count < max_count; x--)
            {
                res.push_back(matrix[x][y]);
                debug <<"right-[" <<x <<", " <<y <<"] = " <<matrix[x][y] <<", count = " <<count <<endl;
                count++;
            }
#ifdef __tmain
            assert(up - 1 == x);
            assert(left == y);
            system("PAUSE");
#endif // __tmain
            x++;            //  ���һ�ε�ʱ��, x == up - 1, �����˷�Χ��Ҫ����
            left++;         //  �������Ժ�, ��ô��ǰ������left == y�Ѿ��������ˣ��������ٱ�����, ���left--

#ifdef __tmain
            system("PAUSE");
#endif // __tmain
        }

        return res;
    }
};


int __tmain( )
{
    int a1[] = {  1,  2,  3,  4 };
    int a2[] = {  5,  6,  7,  8 };
    int a3[] = {  9, 10, 11, 12 };
    int a4[] = { 13, 14, 15, 16 };
//    int a1[] = { 1 };
//    int a2[] = { 2 };
//    int a3[] = { 3 };
//    int a4[] = { 4 };

    vector<int> vec1(a1, a1 + 4);
    vector<int> vec2(a2, a2 + 4);
    vector<int> vec3(a3, a3 + 4);
    vector<int> vec4(a4, a4 + 4);


    vector< vector<int> > vec;
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);

    Solution solu;
    vector<int> res = solu.printMatrix(vec);
    for(int i = 0; i < res.size( ); i++)
    {
        cout <<res[i] <<" ";
    }
    return 0;
}
