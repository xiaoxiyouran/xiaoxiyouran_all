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
        TreeNode *pLastNode = ConvertRecursion(pRootOfTree);

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
     */
    TreeNode* ConvertRecursion(TreeNode *root)
    {
        if(root == NULL)
        {
            debug <<"NULL" <<endl;
            return NULL;
        }

        //////////////////////////
        /// ���� �ݹ�������
        //////////////////////////
        TreeNode *lastNode = NULL;
        if(root->left != NULL)
        {
            ///  �ݹ齫������ת��Ϊ˫������, ���ҷ����������ĸ��ڵ�
            lastNode = ConvertRecursion(root->left);

            //  �ݹ���������ɺ�
            //  lastNode�ڵ�ָ�����������ĸ��ڵ�
            //  ����root��ǰ��Ӧ����ԭ���������������ӽڵ�, ��ת������������һ���ڵ�,
            while(lastNode != NULL && lastNode->right != NULL)
            {
                lastNode = lastNode->right;
            }

            root->left = lastNode; //
            lastNode->right = root;     ///  �����ж�lastNode�Ƿ�ΪNULL, ��Ϊ���ǵĺ���Ϊroot = NULL���ǲ����еݹ��
            debug <<lastNode->val <<", " <<root->val <<endl;

        }


        //////////////////////////
        /// ���� �ݹ�������
        //////////////////////////
        TreeNode *nextNode = NULL;
        if(root->right != NULL)
        {
            //  �ݹ齫������ת��Ϊ˫������, ���ҷ����������ĸ��ڵ�
            nextNode = ConvertRecursion(root->right);

            //  �ݹ���������ɺ�
            //  lastNode�ڵ�Ӧ�����������������ҽڵ�
            //  ��ת������������һ���ڵ�
            while(nextNode->left != NULL)
            {
                nextNode = nextNode->left;
            }
            nextNode->left = root;
            root->right = nextNode;
            debug <<root->val <<", " <<nextNode->val <<endl;
        }

        return root;
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
