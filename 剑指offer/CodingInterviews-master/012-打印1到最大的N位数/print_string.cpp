#include <iostream>
#include <cstring>
using namespace std;

//  ���Կ���
//#define DEBUG
#define __tmain main

#ifdef DEBUG

#define debug cout

#else

#define debug 0 && cout

#endif // DEBUG



class Solutin
{
public :
    Solutin(int n)
    {
        this->m_N = n;
        this->m_isOverFlow = false;

        this->m_number = new char[n + 1];
        memset(m_number, '\0', n + 1);
        this->m_number[n - 1] = '1';
        this->m_length = 1;

        //  m_N ���� >= m_length
        //  ��������Ϣ���洢��m_number[m_N - length, m_N);
    }

    void Print( )
    {
        if(m_N <= 0)
        {
            return;
        }
        while(this->m_isOverFlow != true)
        {
            PrintNumber( );
            Increment( );

        }




    }

    void PrintNumber( )
    {
        //  m_N ���� >= m_length
        //  ��������Ϣ���洢��m_number[m_N - length, m_N);
        debug <<"number is stroge in [" <<m_N - m_length <<", " <<m_N <<")" <<endl;
        for(int i = m_N - m_length; i < m_N; i++)
        {
            cout<<m_number[i];
        }
        cout <<endl;
    }


    bool Increment( )
    {
        int nSum = 0;               //  ��ǰλ
        int takeOver = 0;           //  ��λ
        for(int i = m_N - 1; i >= m_N - m_length; i--)
        {
            if(m_number[i] != '\0')
            {
                nSum = m_number[i] - '0' + takeOver;
            }
            else
            {
                nSum = 0;
            }
            nSum++;
            debug <<"nSum = " <<nSum <<endl;

            if(nSum >= 10)      //  ��Ҫ��λ
            {
                if(i == 0)      //  �����, ��ѭ����ֹ
                {
                    m_isOverFlow = true;
                    debug <<"Over Flow now" <<endl;
                    delete m_number;
                }
                else
                {
                    nSum -= 10;
                    m_number[i] = '0' + nSum;

                    takeOver = 1;                   //  ��Ҫ��λ, ����ѭ��
                    if(i == m_N - m_length)           //  ��ʱ˵����λ�����λ, ���Ȼ�����1
                    {
                        m_length++;
                        debug <<"take over now ( length = " <<m_length <<" )";
                    }
                }
            }
            else                //  û�н�λ, ��ǰλ����1�Ժ�ѭ����������
            {
                if(takeOver == 1)
                {
                    debug <<"it's a take over" <<endl;
                }
                m_number[i] = '0' + nSum;
                break;
            }
        }
    }

private :
    int             m_N;                    //  Nλ��
    char            *m_number;              //  �洢���ݵ��ַ���
    bool            m_isOverFlow;           //  �Ƿ����, ���ʱ˵������������
    volatile int    m_length;               //  ��ǰ���ֵ�λ��

};


int __tmain( )
{


    int n;
    while(cin >> n)
    {
        Solutin solu(n);
        solu.Print( );
    }
    return 0;
}
