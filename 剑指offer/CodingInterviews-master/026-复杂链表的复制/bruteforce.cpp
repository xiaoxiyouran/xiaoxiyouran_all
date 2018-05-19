class Solution
{
public:
    ///  �ҵ�newHeadָ�������������ԭ������oldHead��randNode�ڵ��Ӧ���Ǹ��ڵ�
    ///
    ///  ���Ƶ�����newHead��ԭ����oldHead����һһ��Ӧ�Ĺ�ϵ
    ///  ���ʹ������ָ��(һ��ָ��ԭ������һ��ָ��������)ͬ���ƶ�
    ///  �����ҵ�newHeadָ�������������ԭ������oldHead��randNode�ڵ��Ӧ���Ǹ��ڵ�
    RandomListNode* FindInNew(RandomListNode *oldHead, RandomListNode *newHead, RandomListNode *randNode)
    {
        RandomListNode *currNode = oldHead;
        RandomListNode *newNode = newHead;

        while(currNode != NULL && newNode != NULL)
        {
            if(randNode == currNode)
            {
                return newNode;
            }
            currNode = currNode->next;
            newNode = newNode->next;
        }

        return NULL;
    }

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
        while(currNode != NULL)
        {
            newNode = new RandomListNode(currNode->label);
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
            RandomListNode *newRandNode = FindInNew(pHead, newHead, randNode);  ///  ���ҵ�����������randNode��Ӧ��ָ����
            newNode->random = newRandNode;

            ///  ����ͬ���ƶ�
            currNode = currNode->next;
            newNode = newNode->next;
        }

        return newHead;
    }

};
