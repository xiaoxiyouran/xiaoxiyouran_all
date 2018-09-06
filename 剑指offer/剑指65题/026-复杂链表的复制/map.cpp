#include <iostream>
#include <map>

using namespace std;

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x)
    :label(x), next(NULL), random(NULL)
    {
    }
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
        map<RandomListNode *, RandomListNode *> nodeMap;

        RandomListNode *currNode = pHead;
        RandomListNode *newHead = NULL, *preNode = NULL, *newNode = NULL;

        ///  ���ȸ���ԭ�������ָͨ����, һ�α����������
        while(currNode != NULL)
        {
            newNode = new RandomListNode(currNode->label);
            nodeMap[currNode] = newNode;
            currNode = currNode->next;

            if(preNode == NULL)
            {
                newHead = newNode;
            }
            else
            {
                preNode->next = newNode;
            }

            preNode = newNode;
        }

        //  ���Ÿ������ָ����, ��Ҫ���α���
        currNode = pHead;
        newNode = newHead;
        while(currNode != NULL && newNode != NULL)
        {
            RandomListNode *randNode = currNode->random;                        ///  ���ָ����randNode
            RandomListNode *newRandNode = nodeMap[randNode];
            newNode->random = newRandNode;

            ///  ����ͬ���ƶ�
            currNode = currNode->next;
            newNode = newNode->next;
        }

        return newHead;
    }

};


int main( )
{

}


