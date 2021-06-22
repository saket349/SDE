
```cpp
TreeNode* solve(vector<int> &preorder, int left, int right, unordered_map<int, int> &mp, int &ind){
        if(left>right) return NULL;
        int value = preorder[ind++];
        TreeNode* root = new TreeNode(value);
        root->left = solve(preorder, left, mp[value]-1, mp, ind);
        root->right = solve(preorder, mp[value]+1, right, mp, ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int ind = 0;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;
        return solve(preorder, 0, preorder.size()-1, mp, ind);
    }
```
