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


#ifdef __tmain

struct ListNode
{
public :
    int val;
    struct ListNode *next;

};

#endif  //  #endif  __tmain



class Solution
{
public:
    ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode *rightHead)
    {
        ListNode *left = leftHead;
        ListNode *right = rightHead;

        stack<ListNode *> leftStack;
        stack<ListNode *> rightStack;

        /// ���������ջ
        while(left != NULL)
        {
            //debug <<left->val <<endl;
            leftStack.push(left);
            left = left->next;
        }

        while(right != NULL)
        {
            //debug <<right->val <<endl;
            rightStack.push(right);
            right = right->next;
        }

        ///  ��ʼͬ������Ԫ��
        while(leftStack.empty( ) != true
           && rightStack.empty( ) != true)
        {
            left = leftStack.top( );
            right = rightStack.top( );

            debug <<left->val <<", " <<right->val <<endl;

            ///  ����ͬ��Ԫ�ؾ��Ǻϲ���ǰһ�����
            if(left != right)
            {
                break;
            }
            leftStack.pop( );
            rightStack.pop( );
        }

        ///  ����ͬԪ�ص���һ�������ǹ�ͬ���
        if(left != right)
        {
            return left->next;
        }
        else
        {
            return NULL;
        }
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
