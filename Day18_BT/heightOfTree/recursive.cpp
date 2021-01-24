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
int solve(TreeNode* node){
    int p = 0;
    if(node!=NULL){
        p++;
        p=p+max(solve(node->left), solve(node->right));
    }
    return p;
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};