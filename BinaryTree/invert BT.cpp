// mirror a binary tree
TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        if(root->left == NULL && root->right==NULL) return root;
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
