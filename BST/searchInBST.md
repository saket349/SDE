[Question link](https://leetcode.com/problems/search-in-a-binary-search-tree/)

```
You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node.
If such a node does not exist, return null.
```

### We do recursive search and see if any node value matches with given value or not, if for certain recursion neither of node, node->left, node->right matches with given value then we return null

```cpp 
TreeNode* solve(TreeNode* node, int x){
    if(node->val == x)
        return node;
    if(node->left!=NULL)
    {
        TreeNode* temp = solve(node->left,x);
        if(temp!=NULL && temp->val==x)
            return temp;
    }
    if(node->right!=NULL){
        TreeNode* temp2 = solve(node->right,x);
        if(temp2!=NULL && temp2->val==x)
            return temp2;
    }
    
    return NULL;
}

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return NULL;
        return (solve(root,val));
    }
};

```
