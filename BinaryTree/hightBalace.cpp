/*
    a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

*/

/*
    same as diameter, just in this case we donot save the max lenght instead compare left and right height ;
    if difference is more than 1 then mark ans as false
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
        int l=0,r=0;
        if(node->left!=NULL)
           l = solve(node->left);
        if(node->right!=NULL)
           r = solve(node->right);
        
        if(abs(l-r)>1)
            ans=0;
        
        return max(l+1,r+1);
    }
    return 0;
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        ans=1;
        solve(root);
        if(ans==1)
            return true;
        else
            return false;
    }
};
