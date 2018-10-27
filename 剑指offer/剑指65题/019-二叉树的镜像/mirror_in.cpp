#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

//  ���Կ���
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
	TreeNode(int x) :
			val(x), left(NULL), right(NULL)
    {
	}
};
#endif // __tmain


class Solution
{
public:
    void MirrorIn(TreeNode *root)
    {
        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
            return NULL;
        }

        stack<TreeNode *> nstack;
        TreeNode *node = root;

        //  ��ʼ��������������
        while(node != NULL || nstack.empty() != true)
        {
            // �������ǰ���ڵ㣬���ǵݹ�ֱ����ǰ���ڵ�node�������
            while(node != NULL)
            {
                nstack.push(node);
                node = node->left;
            }

            //  ��ʱջ����Ԫ���ǵ�ǰ����Ԫ��
            //  ��Ӧ�ñ����
            if(nstack.empty( ) != true)
            {
                node = nstack.top( );

                //  ��ԭ���������Ϊ����������������
                if(node->left != NULL || node->right != NULL)
                {
                    swap(node->left, node->right);
                }

                nstack.pop( );
                //  ������������������ת��
                //  ��ʱ���������������������ԭ��������������������������ת��
                node = node->left;
            }
        }
    }

};


int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
