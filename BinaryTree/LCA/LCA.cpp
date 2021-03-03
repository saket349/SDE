/*
    
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* n=NULL;
int solve(TreeNode* node, TreeNode* p, TreeNode* q){
    if(node!=NULL){
        int l=0,r=0;
        l = solve(node->left,p,q);
        r = solve(node->right,p,q);
        
        if(l+r==2)
            n = node;
        else if(l+r>0)
        {
            if(node==p || node==q)
            n = node;
        }
        
        if(node==p || node==q)
            return 1;
        else if(l+r!=0)
            return 1;
    }
    return 0;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        n = NULL;
        solve(root,p,q);
        return n;
    }
};