# 112 Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and `sum = 22`,

```
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

```

return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.

这个题相对来说比较简单，只是需要注意，最好不要每次累加的sum返回，因为，每次二二向上分叉，就会造成要返回的结果较多。

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void sum_dfs( TreeNode* root, int sum ,bool& res ){
        if( root->left == NULL && root -> right == NULL  && sum == root->val ){
            res =  true;
            return;
        } 
        
        if(root->left != NULL )   sum_dfs( root->left, sum - root->val,res );
        if( root->right!=NULL ) sum_dfs(root->right,sum -root->val, res);

    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if( root == NULL ) 
           return false;
        
        bool res = false;
        
       sum_dfs(root,sum,res);
       return res;
    }
};
```

