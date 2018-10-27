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
    void MirrorPost(TreeNode *root)
    {

        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
            return;
        }
        stack<TreeNode *> nstack;

        TreeNode *cur;                      //��ǰ���
        TreeNode *pre = NULL;                 //ǰһ�η��ʵĽ��
        nstack.push(root);

        while(nstack.empty( ) != true)
        {
            cur = nstack.top( );

            if((cur->left == NULL && cur->right == NULL)                     //  ���һ��Ǿ�ΪNULL, ���Ա����
            || (pre != NULL && ((pre == cur->left /*&& cur->right == NULL*/) || pre == cur->right)))     //  ���һ��Ǳ������, �ݹ鷵��

            {
                ///cout<<cur->val;  //�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ�
                            //  ��ԭ���������Ϊ����������������
                if(cur->left != NULL || cur->right != NULL)
                {
                    swap(cur->left, cur->right);
                }

                nstack.pop( );
                pre = cur;
            }
            else
            {
                // ����ջ���Ƚ����������������, �����ӿ��Ա�֤�ݹ鷵��ʱ�ȱ�������
                if(cur->right != NULL)
                {
                    nstack.push(cur->right);
                }

                if(cur->left != NULL)
                {
                    nstack.push(cur->left);
                }
            }
        }
    }


};


int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
