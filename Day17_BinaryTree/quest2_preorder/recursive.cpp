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
void solve(TreeNode* node,vector<int> &v){
      
        if(node!=NULL){
            v.push_back(node->val);
            if(node->left!=NULL)
                solve(node->left,v);
            if(node->right!=NULL)
                solve(node->right,v);
        }
}
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
            solve(root,v);
        return v;
    }
};