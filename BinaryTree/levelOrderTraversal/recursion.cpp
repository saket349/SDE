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

// recursive method which insert the node->val at different index in  vector.
void solve(TreeNode* node, vector<vector<int>> &v, int p){
    if(node!=NULL){
        if(p!=0){ // not the root node
            if(v.size() < p+1) // if it is the first element of that index
            {
                vector<int> temp;
                temp.push_back(node->val);
                v.push_back(temp);
            } 
            else v[p].push_back(node->val);
        }
        if(node->left!=NULL) solve(node->left, v, p+1);
        if(node->right!=NULL) solve(node->right, v, p+1);
     }
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root!=NULL){
            vector<int> temp = {root->val};
            v.push_back(temp);
            solve(root,v,0);
        }
        return v;
    }
};