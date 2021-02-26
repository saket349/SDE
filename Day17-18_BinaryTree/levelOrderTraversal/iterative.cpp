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
// normal bfs using queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root!=NULL){
            v.push_back({root->val});
            queue<pair<TreeNode*, int>> q;
            q.push({root,0});
            TreeNode* node = root;
            while(q.empty()==false){
                pair<TreeNode*, int> p;
                p = q.front(); q.pop();
                if(p.first->left!=NULL){
                    q.push({p.first->left,p.second+1});
                    if(v.size() < p.second+2)
                    {
                        vector<int> temp = {p.first->left->val};
                        v.push_back(temp);
                    }else{
                        v[p.second+1].push_back(p.first->left->val);
                    }
                }
                if(p.first->right!=NULL){
                    q.push({p.first->right, p.second+1});
                    if(v.size() < p.second+2){
                        vector<int> temp = {p.first->right->val};
                        v.push_back(temp);
                    }else{
                        v[p.second+1].push_back(p.first->right->val);
                    }
                }
            }
        }
        return v;
    }
};
