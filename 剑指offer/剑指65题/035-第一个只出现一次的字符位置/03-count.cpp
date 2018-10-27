#include <iostream>
#include <cstring>


using namespace std;


#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



class Solution
{

protected:
    int count[256];

public:
    int FirstNotRepeatingChar(string str)
    {
        if(str.length( ) == 0)
        {
            return -1;
        }
        unsigned int i;
        //  ��������������0
        memset(count, '\0', sizeof(count));

        //  ���ַ����г��ֵ�ÿ���ַ����м���
        for(i = 0; i < str.length( ); i++)
        {
            debug <<(unsigned int)str[i] <<endl;
            count[(unsigned int)str[i]]++;
        }


        //  ��һ��ֻ����һ�ε��ַ�
        for(i = 0; i < str.length( ); i++)
        {
            debug <<str[i] <<", " <<count[(unsigned
                 int)str[i]] <<endl;
            if(count[(unsigned int)str[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

int __tmain( )
{
    int a = -1;
    unsigned int b = a;
    printf("%u\n", b);

    Solution solu;
    cout <<solu.FirstNotRepeatingChar("abcdefg") <<endl;

    return 0;
}
