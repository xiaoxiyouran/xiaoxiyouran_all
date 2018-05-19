#include <iostream>

using namespace std;

//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

#ifdef __tmain

struct ListNode
{
public :
	int val;
	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL)
//    {
//	}
};


#endif // __tmain

/// 1 -> 2 -> 3 -> 4 -> 5
/// ����Ҫ�ߵ�����3���ڵ�
/// ��ôright���ߵ���3 - 1���ڵ�&[2]
/// ��ôrightָ����ǰ�ߵ�����һ���ڵ�ΪNULLʱ, left�ڵ���ǵ�����K���ڵ�
///  ��ʱ����ָ�����ΪK - 1


/// 1 -> 2 -> 3 -> 4 -> 5
/// ����Ҫ�ߵ�����3���ڵ�
/// ��ôright���ߵ���3���ڵ�&[2]
/// ��ôrightָ����ǰ�ߵ�����β��ΪNULLʱ, left�ڵ���ǵ�����K���ڵ�
/// ��ʱ����ָ�����ΪK
class Solution
{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        if(pListHead == NULL)
        {
            return NULL;
        }
        unsigned int i = 0;
        ListNode *right = pListHead;

        //  leftָ������ǰ��K��
        while(i < k && right != NULL)
        {
            debug <<"index  = " <<i <<", value = " <<right->val <<endl;
            right = right->next;
            i++;
        }

        if(right == NULL && i < k)
        {
            cout <<"the list length = " <<i <<" < " <<k <<endl;
            return NULL;
        }

        ListNode *left = pListHead;
        while(right != NULL)
        {
            debug <<"index  = " <<i++ <<", value = " <<right->val <<endl;

            left = left->next;
            right = right->next;
        }

        return left;

    }
};

int __tmain( )
{
    ListNode list[5];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = &list[4];
    list[4].val = 5;
    list[4].next = NULL;


    ListNode *node = list;
    while(node != NULL)
    {
        cout <<node->val;
        node = node->next;
    }
    cout <<endl;



    Solution solu;
    cout <<solu.FindKthToTail(list, 5)->val <<endl;
    return 0;
}
