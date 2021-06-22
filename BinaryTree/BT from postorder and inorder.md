- concept is same as previous question: BT from inorder and preoder 
- just here instead of preorder, reversed post order vector is used to determine root, 
- and instead of doing left->right->root for postorder, we do, root->right->left for reversed postorder

```cpp
TreeNode* solve(vector<int> &postorder, int left, int right, unordered_map<int, int> &mp, int &ind){
        if(left>right) return NULL;
        int value = postorder[ind--];
        TreeNode* root = new TreeNode(value);                        // root
        root->right = solve(postorder, mp[value]+1, right, mp, ind);  // right
        root->left = solve(postorder, left, mp[value]-1, mp, ind);    // left
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int ind = postorder.size()-1;       // we starts with end
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;   
        return solve(postorder, 0, postorder.size()-1, mp, ind);   
    }
```
