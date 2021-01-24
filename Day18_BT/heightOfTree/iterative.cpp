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

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int level = 0;
        if(root!=NULL){
            q.push({root,0});
            while(q.empty()==false){
                pair<TreeNode*,int> p = q.front();
                q.pop();
                level = max(level, p.second);
                if(p.first->left!=NULL){
                    level = max(level,p.second+1);
                    q.push({p.first->left,p.second+1});
                }
                if(p.first->right!=NULL){
                    level = max(level,p.second+1);
                    q.push({p.first->right,p.second+1});
                }
            }
            level++;
        }
        return level;
    }
};
