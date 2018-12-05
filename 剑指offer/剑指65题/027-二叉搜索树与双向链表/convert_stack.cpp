#include <iostream>
#include <stack>

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
    TreeNode* Convert(TreeNode* root)
    {
        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
        }

        stack<TreeNode *> nstack;
        TreeNode *currNode = root;
        TreeNode *preNode = NULL;
        TreeNode *head = NULL;

        //  ��ʼ��������������
        while(currNode != NULL || nstack.empty() != true)
        {
            // �������ǰ���ڵ㣬���ǵݹ�ֱ����ǰ���ڵ�node�������
            while(currNode != NULL)
            {
                nstack.push(currNode);
                currNode = currNode->left;
            }

            //  ��ʱջ����Ԫ���ǵ�ǰ����Ԫ��
            //  ��Ӧ�ñ����
            if(nstack.empty( ) != true)
            {
                currNode = nstack.top( );
                debug <<currNode->val;
                nstack.pop( );

                //  ��һ���ڵ�
                if(preNode == NULL)
                {
                    head = currNode;
                    // preNode = currNode;
                }
                else
                {
                    preNode->right = currNode;
                    currNode->left = preNode;
                    // preNode = currNode;
                }
                preNode = currNode;
                currNode = currNode->right;
            }
        }
        return head;
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
