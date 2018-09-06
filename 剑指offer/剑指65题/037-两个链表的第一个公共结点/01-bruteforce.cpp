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

};
#endif


class Solution
{
public:
    ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode *rightHead)
    {
        ListNode *left = NULL;
        ListNode *right = NULL;

        //  ѭ����һ�������ÿ�����
        for(left = leftHead;
            left != NULL;
            left = left->next)
        {
            debug <<endl <<left->val <<" : ";

            //  �����ж����ڲ��ڵڶ���������
            for(right = rightHead;
                right != NULL;
                right = right->next)
            {
                debug <<right->val <<", ";
                if(left == right)
                {
                    break;
                }
            }
            if(left == right)
            {
                break;
            }
        }

        return left;
    }
};




int __tmain( )
{
    ListNode common[2];
    common[0].val = 6;
    common[0].next = &common[1];
    common[1].val = 7;
    common[1].next = NULL;

    ListNode left[3];
    left[0].val = 1;
    left[0].next = &left[1];
    left[1].val = 2;
    left[1].next = &left[2];
    left[2].val = 3;
    left[2].next = &common[0];

    ListNode right[2];
    right[0].val = 4;
    right[0].next = &right[1];
    right[1].val = 5;
    right[1].next = &common[0];

    Solution solu;
    ListNode *node = solu.FindFirstCommonNode(left, right);
    while(node != NULL)
    {
        debug <<node->val <<" ";
        node = node->next;
    }
    debug <<endl;

    return 0;
}
