#include <iostream>

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

class Solution {
public:
    bool HasSubtree(TreeNode* parent, TreeNode* child)
    {
        if(child == NULL || parent == NULL)
        {
            return false;
        }

        bool result;
        //  �����ǰ�����Ľڵ��������ĸ��ڵ���ͬ����ֱ�ӴӸ����ĵ�ǰλ�ÿ�ʼ�ж�
        if(parent->val == child->val)
        {
            result = DoesParentHaveChild(parent, child);
        }
        if(result != true)
        {
            return HasSubtree(parent->left, child)      //  ������������
            || HasSubtree(parent->right, child);        //  ���������в���
        }
        else
        {
            return true;
        }

    }

    bool DoesParentHaveChild(TreeNode *parent, TreeNode *child)
    {
        if(child == NULL)      //  ����ΪNULL����ô��Ȼ������
        {
            return true;
        }
        else if(parent == NULL)      //  ��������NULL, ���Ǹ�������NULL
        {
            return false;
        }

        //  �����ڵ��ֵ����ȣ���ô��������Ȼ���Ǹ��ӹ�ϵ
        if(parent->val != child->val)
        {
            return false;
        }
        else      // ����ǰ�ڵ㵱ǰ��ȣ���ݹ���ж�����������������Ӧ�ڵ��Ƿ���ͬ
        {

            return DoesParentHaveChild(parent->left, child->left)
                && DoesParentHaveChild(parent->right, child->right);
        }
    }
};

int __tmain( )
{
    debug <<"test" <<endl;
    return 0;
}
