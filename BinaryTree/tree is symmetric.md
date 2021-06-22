```cpp
bool solve(TreeNode* l, TreeNode* r){
        if(l==NULL && r==NULL) return true;
        if(!l || !r || (l->val != r->val)) return false;
        return (solve(l->left, r->right) && solve(l->right, r->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return solve(root->left,root->right);
    }
```
