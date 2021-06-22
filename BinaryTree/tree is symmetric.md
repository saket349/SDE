```cpp
bool solve(TreeNode* l, TreeNode* r){
        if(l==NULL && r==NULL) return true;
        if(l==NULL || r==NULL) return false;
        if(l->val != r->val) return false;
        // cout<<l->val<<" "<<r->val<<endl;
        return (solve(l->left, r->right) && solve(l->right, r->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        TreeNode *l, *r;
        l = root->left;
        r = root->right;
        return solve(l,r);
    }
```
