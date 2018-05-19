# [hard, tree] 124. Binary Tree Maximum Path Sum

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain **at least one node** and does not need to go through the root.

For example:
Given the below binary tree,

```
       1
      / \
     2   3
```

Return `6`.

------

Here’s my ideas:

- A path from start to end, goes up on the tree for 0 or more steps, then goes down for 0 or more steps. Once it goes down, it can’t go up. Each path has a highest node, which is also the lowest common ancestor of all other nodes on the path.
- A recursive method `maxPathDown(TreeNode node)` (1) computes the maximum path sum with highest node is the input node, update maximum if necessary (2) returns the maximum sum of the path that can be extended to input node’s parent.

Code:

寻找二叉树的最大路径和，就是需要求出每个节点左边的最大值和右边的最大值。

其次，有可能不需要经过该节点，所以有一个选择的过程。



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

#include<bits/stdc++.h>

class Solution {
public:
    int maxValue;
    int maxPathSum(TreeNode* root) {
        maxValue = INT_MIN;
        maxPathDown(root);
        return maxValue;
    }
    
    int maxPathDown(TreeNode* root){
        if( root == NULL ) return 0;
        
        int left = max(0,maxPathDown( root -> left ));          /// why 0?
        int right = max(0, maxPathDown( root -> right ));
        maxValue = max( maxValue, left + right + root->val );   // whether get this nodes
        
        return max(left, right) + root -> val ;                 // select one from left between right.  
    }
};
```







