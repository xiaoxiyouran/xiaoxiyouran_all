#����
------- 
>ţ��OJ��[ջ��ѹ�롢��������](http://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
> 
>�Ŷ�OJ��http://ac.jobdu.com/problem.php?pid=1522
> 
>GitHub���룺 [021-����min������ջ](https://github.com/gatieme/CodingInterviews/tree/master/021-����min������ջ)
>
>CSDN��⣺[��ָOffer--021-����min������ջ](http://blog.csdn.net/gatieme/article/details/51184578)


| ţ��OJ | �Ŷ�OJ | CSDN��� | GitHub���� | 
| ------------- |:-------------:| -----:| 
|[ջ��ѹ�롢��������](http://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) | [1522-����min������ջ](http://ac.jobdu.com/problem.php?pid=1522) | [��ָOffer--021-����min������ջ](http://blog.csdn.net/gatieme/article/details/51184578) | [021-����min������ջ](https://github.com/gatieme/CodingInterviews/tree/master/021-����min������ջ) |



<br>**��Ҳ����ѡ��[�ص�Ŀ¼-��ָOffer--�⼯Ŀ¼����](http://blog.csdn.net/gatieme/article/details/51916802)**


#����
-------


**��Ŀ����**


>����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������


#����
-------

˼·�ܼ򵥣�����ά������ջ��

*    ����ջdata���洢ջ���������ڳ����ջ����

*    ��Сջmin������ÿ��push��popʱ�����Сֵ��

��push-dataջ��ʱ�򣬽���ǰ��С����ѹ�룬

��pop-dataջ��ʱ�򣬽�minջջ������С���ݵ���

������֤minջ�д洢�ŵ�ǰ�ֳ�����Сֵ������������ջ�ĸ��¶�����

```cpp

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
```
