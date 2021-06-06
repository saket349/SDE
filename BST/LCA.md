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
Node* LCA(Node *root, int n1, int n2)
{
    if(root==NULL) return NULL;
    if (root->val > n1 && root->val > n2) 
        return LCA(root->left, n1, n2);
    if (root->val < n1 && root->val < n2) 
        return LCA(root->right, n1, n2); 
  
    return root; 
   //Your code here
}
```
