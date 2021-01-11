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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* node;
        node = root;
        while(node!=NULL || s.size()!=0){
            while(node!=NULL){
                if(node->right!=NULL)
                    s.push(node->right);
                s.push(node);
                node=node->left;
            }
            node = s.top();
            s.pop();
            if(node->right==NULL){
                v.push_back(node->val);
                node=NULL;
            }
            else if(s.size()!=0 && node->right==s.top()){
                TreeNode* temp = s.top();
                s.pop();
                s.push(node);
                node=temp;
            }
            else{
                v.push_back(node->val);
                node=NULL;
            }
        }
       return v;
    }
};
