#include <iostream>

using namespace std;

//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
//    RandomListNode(int x)
//    :label(x), next(NULL), random(NULL)
//    {
//    }
};


class Solution
{
public:

    ///  ���Ʋ���
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
        {
            return NULL;
        }

        RandomListNode *currNode = pHead;
        RandomListNode *newHead = NULL, *preNode = NULL, *newNode = NULL;

        ///  ���ȸ���ԭ�������ָͨ����, һ�α����������
        ///  ���µĽڵ�������ԭ���ڵ��ĩβ
        while(currNode != NULL)
        {
            if((newNode = new RandomListNode(currNode->label)) == NULL)
            {
                perror("new error : ");
                exit(-1);
            }


            /// ���µĽڵ�newNode������currNode�ĺ���
            newNode->next = currNode->next;
            currNode->next = newNode;

            ///  ָ��ָ����һ���ڵ�
            currNode = newNode->next;
        }

        ///  ���Ÿ������ָ����
        ///  ԭ���ڵ����һ��λ�þ������Ӧ���½ڵ�
        currNode = pHead;
        newNode = pHead->next;
        while(currNode != NULL)
        {
            RandomListNode *randNode = currNode->random;                        ///  ���ָ����randNode
            RandomListNode *newNode = currNode->next;
            if(randNode != NULL)
            {

                newNode->random = randNode->next;

            }
            else
            {
                newNode->random = NULL;
            }
            ///  ����ͬ���ƶ�
            currNode = newNode->next;
        }

        /// ��������һ����¾����������ֿ�
        /// ���������¸������nextָ��
        currNode = pHead;
        newNode = newHead = pHead->next;
        while(currNode != NULL)
        {
            /// curr  new new->next
            currNode->next = newNode->next;
            debug <<currNode->label <<", " <<newNode->label <<endl;
            if(newNode->next != NULL)
            {
                newNode->next = newNode->next->next;
            }
            else
            {
                newNode->next = NULL;
            }

            currNode = currNode->next;
            newNode = newNode->next;
        }

        return newHead;
    }

};






int __tmain( )
{

    RandomListNode list[4];
    list[0].label = 1;
    list[0].next = &list[1];
    list[1].label = 1;
    list[1].next = &list[2];
    list[2].label = 2;
    list[2].next = &list[3];
    list[3].label = 2;
    list[3].next = NULL;


    Solution solu;
    RandomListNode *head = solu.Clone(list);
    while(head != NULL)
    {
        cout <<head->label;
        head = head->next;
    }
    return 0;
}
