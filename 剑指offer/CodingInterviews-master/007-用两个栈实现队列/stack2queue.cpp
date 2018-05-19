#include <iostream>
#include <stack>
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
    void push(int node)
    {
        stackIn.push(node);
    }

    int pop()
    {
        int node = -1;

        //  ����ջ����NULL��ʱ����������Ϊ��
        if(this->empty( ) == true)
        {
            debug <<"��������ΪNULL" <<endl;

            return -1;
        }
        else
        {
            //  �����������Ԫ��
            //  ��ʱ�����������
            //  �����ջ��Ϊ�յ�ʱ��, ֱ�ӽ����ջ��Ԫ�ص�������
            //  �����ջΪNULL, ��������ջ��Ϊ�յ�ʱ����Ҫ������ջ��Ԫ��ȫ���������ջ��

            if(stackOut.empty() == true)     //  ��ʱ���ջΪ��, ����ջ�ز�Ϊ��
            {
                //  ��ʱ����ջ�����ջ����û��Ԫ��
                //  ��Ҫ������ջ�е�Ԫ�ص������ջ
                // ������ջ����û��Ԫ��

                //  ����Ԫ�ش�����ջ�������ջ
                while(stackIn.empty( ) != true)
                {
                    node = stackIn.top( );
                    stackIn.pop( );
                    stackOut.push(node);
                    debug <<node <<"�������ջ" <<endl;
                }
            }

            node = stackOut.top( );
            stackOut.pop( );

            debug <<"��ͷԪ��" <<node <<endl;
        }

        return node;
    }

    bool empty( )
    {
        return (stackIn.empty() == true && stackOut.empty() == true);
    }

private:
    stack<int> stackIn;
    stack<int> stackOut;
};


int __tmain( )
{
    Solution solu;
    solu.push(1);
    solu.push(2);
    solu.push(3);
    solu.push(4);

    int node;
    while(solu.empty() != true)
    {

        cout <<solu.pop( );
    }

    return 0;
}
