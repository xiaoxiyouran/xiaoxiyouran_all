#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

#define MIN(x, y) ((x) < (y) ? (x) : (y))

class Solution
{
public:
    void push(int value)
    {
        this->m_data.push(value);
//        if(this->m_min.size( ) <= 1)
//        {
//            this->m_min.push(value);
//        }
//        int min_data = MIN(value, this->m_min.top( ));
//        this->m_min.push(min_data);

        if(this->m_min.size( ) == 0 || value < this->m_min.top( ))
        {
            this->m_min.push(value);
        }
        else
        {
            this->m_min.push(this->m_min.top( ));
        }
    }

    void pop()
    {
        assert(this->m_data.size( ) > 0 && this->m_min.size( ) > 0);

        this->m_data.pop( );
        this->m_min.pop( );
    }

    int top()
    {
        assert(this->m_data.size( ) > 0 && this->m_min.size( ) > 0);


        return this->m_data.top( );
    }

    int min()
    {
        if(this->m_data.empty( ) == true)
        {
            return 0;
        }

        return this->m_min.top( );
    }
protected:
    stack<int>  m_data;     //  ����ջ
    stack<int>  m_min;      //  �洢ÿ��ջ����Сֵ��ջ��Ϣ
};


int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
