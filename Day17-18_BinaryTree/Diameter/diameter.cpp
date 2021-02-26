// Diamter of a tree
// longest path you can travel or max(distabce bw two nodes)
/*
 recursive code, for every node we find max of heght(left, right) and for that node longest path is left heght + right height + 1 
 then we find max of all path lenght, for this we we keep updating max lenght if encounter lenght more then currently stored max lenght 
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int ans;
int solve(TreeNode* node){
    if(node!=NULL){
        int l=0;int r=0;
        if(node->left != NULL)
        l = solve(node->left);
        if(node->right!=NULL)
        r = solve(node->right);
        ans=max(ans,l+r+1);
        //cout<<l<<" "<<r<<" "<<ans<<endl;
        return max(l+1,r+1);
    }
    return 0;
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        solve(root);
        if(ans!=0)
            ans--;
        
        return ans;
    }
};
