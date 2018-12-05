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
    /*

     TreeNode(int x)
	:val(x), left(NULL), right(NULL)
	{
	}*/
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
        TreeNode *pLastNode = ConvertRecursion(pRootOfTree);

        // ���ݹ������,*pLastNodeָ����˫�������β���
        TreeNode *node = pLastNode;
//        debug <<pLastNode->val <<endl;
        while(pLastNode != NULL
           && pLastNode->left != NULL)
        {
//            debug <<pLastNode->val <<" ";
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
    TreeNode* ConvertRecursion(TreeNode *root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        TreeNode *currNode = root;
        static TreeNode *lastNode = NULL;
        //////////////////////////
        /// �������� �ݹ�������
        //////////////////////////
        if(currNode->left != NULL)
        {
            lastNode = ConvertRecursion(root->left);
        }


        //////////////////////////
        /// ��������ʼ���ʸ��ڵ�
        /// ��������ʵĹ����ݱ�Ϊ���������ĸ�����ڵ����ӳ�һ������
        //////////////////////////

        ///  ��ʼ�����������͵�ǰ���ڵ�
        //  *pLastNode -=> currNode
        currNode->left = lastNode; //
        if(lastNode != NULL)
        {
            lastNode->right = currNode;
        }
        else
        {
            debug <<"lastNode is NULL" <<endl;
        }
        debug <<((lastNode == NULL) ? -1 : lastNode->val) <<", " <<currNode->val <<endl;

        //  ������һ�����ʵ�ָ����
        //  ����Ҫ����ǰһ��ָ���ָ����
        //  �����Ҫʹ����ָ�����޸���ָ��
        if(currNode != NULL)
        {
            lastNode = currNode;
        }
        //  �������
        if(currNode->right != NULL)
        {
            lastNode = ConvertRecursion(currNode->right);
        }

        return lastNode;
    }
};



int __tmain( )
{
    //    4
    //  3
    //2
    TreeNode tree[3];
    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = NULL;
    tree[1].val = 3;
    tree[1].left = &tree[2];
    tree[1].right = NULL;
    tree[2].val = 2;
    tree[2].left = NULL;
    tree[2].right = NULL;


    Solution solu;
    TreeNode *head = solu.Convert(tree);
    while(head != NULL)
    {
        cout <<head->val <<" ";
        head = head->right;
    }



    TreeNode tree2[4];
    tree2[0].val = 4;
    tree2[0].left = &tree2[1];
    tree2[0].right = &tree2[2];
    tree2[1].val = 3;
    tree2[1].left = &tree2[3];
    tree2[1].right = NULL;
    tree2[2].val = 5;
    tree2[2].left = NULL;
    tree2[2].right = NULL;
    tree2[3].val = 2;
    tree2[3].left = NULL;
    tree2[3].right = NULL;

    Solution solu2;
    head = solu2.Convert(tree2);
    while(head != NULL)
    {
        cout <<head->val <<" ";
        head = head->right;
    }
    return 0;
}
