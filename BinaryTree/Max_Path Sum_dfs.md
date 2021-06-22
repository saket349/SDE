##### Since it is the recursive approach be  calculate max path length for each subtree, and comapare it with global ans.
<b>Key concept</b> : for each subtree, what all can be max path length, it can be -
- root node itself
-  or root node plus left node
-   or root node plus right node 
-   or root node plus left plus right,
##### So we calculate max path lenght for each subtree in this way and compare with global ans at each step.
```cpp
int ans = INT_MIN;  //global ans, defined globally
int solve(TreeNode* node){
    if(node!=NULL){
        int tans=0;  // local ans for each subtree, defined locally
        int l=0,r=0;
        l = solve(node->left);
        r = solve(node->right);
        tans = node->val;
        if(l>0)
            tans=tans+l;
        if(r>0)
            tans=tans+r;
        ans=max(ans,tans);
        return (node->val)+max({0,l,r});
    }
    return 0;
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN; // intialize global ans for each run
         solve(root);
        return ans;
    }
};
```
