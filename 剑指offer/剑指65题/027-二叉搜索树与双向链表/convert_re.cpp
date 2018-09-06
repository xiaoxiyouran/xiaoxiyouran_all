#include <iostream>

using namespace std;

//
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

#ifdef __tmain

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
//	TreeNode(int x)
//	:val(x), left(NULL), right(NULL)
//	{
//	}
};

#endif  //  __tmain

class Solution
{
public:
    /**
     * [Convert description]
     * @AuthorHTL
     * @DateTime  2016-04-23T21:02:08+0800
     * @param     pRootOfTree              [�����������ĸ�]
     * @return                             [ת���ɵ������ͷ���]
     */
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
        {
            return NULL;
        }
        TreeNode *pLastNode = NULL;
        ConvertRecursion(pRootOfTree, &pLastNode);

        // ���ݹ������,*pLastNodeָ����˫�������β���
        TreeNode *node = pLastNode;
        while(pLastNode != NULL
           && pLastNode->left != NULL)
        {
           pLastNode = pLastNode->left;
        }

        return pLastNode;
    }

    /**
     * [ConvertRecursion �ݹ�Ľ�rootΪ���Ķ���������ר�����ܳ�˫������]
     * @AuthorHTL
     * @DateTime  2016-04-23T22:33:00+0800
     * @param     root                     [��ǰ�ݹ�Ķ����������ĸ��ڵ�]
     * @param     pLastNode                [���������ָ��ǰһ���ڵ��ָ��]
     */
    void ConvertRecursion(TreeNode *root, TreeNode **pLastNode)
    {
        if(root == NULL)
        {
            return;
        }
        TreeNode *currNode = root;

        //////////////////////////
        /// �������� �ݹ�������
        //////////////////////////
        if(currNode->left != NULL)
        {
            ConvertRecursion(root->left, pLastNode);
        }


        //////////////////////////
        /// ��������ʼ���ʸ��ڵ�
        /// ��������ʵĹ����ݱ�Ϊ���������ĸ�����ڵ����ӳ�һ������
        //////////////////////////

        ///  ��ʼ�����������͵�ǰ���ڵ�
        //  *pLastNode -=> currNode
        currNode->left = *pLastNode; //
        if(*pLastNode != NULL)
        {
            (*pLastNode)->right = currNode;
        }
        else
        {
            debug <<"lastNode is NULL" <<endl;
        }

        debug <<((*pLastNode == NULL) ? -1 : (*pLastNode)->val) <<", " <<currNode->val <<endl;
        system("PAUSE");
        //  ������һ�����ʵ�ָ����
        //  ����Ҫ����ǰһ��ָ���ָ����
        //  �����Ҫʹ����ָ�����޸���ָ��
        *pLastNode = currNode;

        //  �������
        if(currNode->right != NULL)
        {
            ConvertRecursion(currNode->right, pLastNode);
        }
    }
};



int __tmain( )
{
    //    4
    //  3   5
    //2
    TreeNode tree[4];
    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[1].val = 3;
    tree[1].left = &tree[3];
    tree[1].right = NULL;
    tree[2].val = 5;
    tree[2].left = NULL;
    tree[2].right = NULL;
    tree[3].val = 2;
    tree[3].left = NULL;
    tree[3].right = NULL;


    Solution solu;
    TreeNode *head = solu.Convert(tree);
    while(head != NULL)
    {
        cout <<head->val <<" ";
        head = head->right;
    }
    return 0;
}
