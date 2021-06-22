- Build a hashmap to record the relation of value -> index for inorder, so that we can find the position of root in constant time.
- Initialize an integer variable preorderIndex to keep track of the element that will be used to construct the root.
- Implement the recursion function arrayToTree which takes a range of inorder and returns the constructed binary tree:
- - if the range is empty, return null;
- - initialize the root with preorder[preorderIndex] and then increment preorderIndex;
- - recursively use the left and right portions of inorder to construct the left and right subtrees.
- Simply call the recursion function with the entire range of inorder.

```cpp
TreeNode* solve(vector<int> &preorder, int left, int right, unordered_map<int, int> &mp, int &ind){
        if(left>right) return NULL;
        int value = preorder[ind++];
        TreeNode* root = new TreeNode(value);                        // root
        root->left = solve(preorder, left, mp[value]-1, mp, ind);    // left
        root->right = solve(preorder, mp[value]+1, right, mp, ind);  // right
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int ind = 0;     // it is used to consider which node is currently being used as root node
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;    // maping inorder value to index
        return solve(preorder, 0, preorder.size()-1, mp, ind);   
    }
```
