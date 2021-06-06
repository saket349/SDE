### almost same to LCA for Binary Tree, just more easier as we know where two values can be found, as BST is sorted tree

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(TreeNode* node, TreeNode* p, TreeNode* q){
    if(node!=NULL){
        if(p->val > q->val) return solve(node,q,p);
        if(node==p || node==q) return node;
        if(p->val < node->val && q->val > node->val) return node;
        if(p->val > node->val) return solve(node->right,p,q);
        return solve(node->left,p,q);
    }
    return NULL;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};
```
