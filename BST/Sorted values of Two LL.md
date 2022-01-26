```cpp
void solve(TreeNode* root, vector<int> &v){
        if(root==NULL) return ;
        if(root->left != NULL) solve(root->left, v);
        v.push_back(root->val);
        if(root->right != NULL) solve(root->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2, v;
        solve(root1, v1);
        solve(root2, v2);
        int i = 0, j = 0;
        int n = v1.size(), m = v2.size();
        while(i<n && j<m) {
            if(v1[i] <= v2[j]) {
                v.push_back(v1[i++]);
            } else {
                v.push_back(v2[j++]);
            }
        }
        while(i<n) v.push_back(v1[i++]);
        while(j<m) v.push_back(v2[j++]);
        
        return v;
        
    }
```
