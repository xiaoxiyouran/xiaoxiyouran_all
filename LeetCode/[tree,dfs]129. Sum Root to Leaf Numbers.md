### 129. Sum Root to Leaf Numbers

Given a binary tree containing digits from `0-9` only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path `1->2->3` which represents the number `123`.

Find the total sum of all root-to-leaf numbers.

For example,

```
    1
   / \
  2   3

```

The root-to-leaf path `1->2` represents the number `12`.
The root-to-leaf path `1->3` represents the number `13`.

Return the sum = 12 + 13 = `25`.

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
    int sumNumbers(TreeNode* root) {
        
        return dfs(root, 0);    
    }
    
    int dfs(TreeNode* root, int s){
        if( root == NULL )                                  ///  表示根为空
            return 0;
        if( root->left == NULL && root -> right == NULL ){  /// 判断是否是叶子节点
            return s*10 + root-> val;
        }
        
        return dfs( root->left,s*10 + root->val ) + dfs(root -> right,s*10 + root ->val);
    }
};
```

