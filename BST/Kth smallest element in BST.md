[question link](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

given an BST, return Kth smallest element of it
```
Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
```
```
Input: root = [3,1,4,null,2], k = 1
Output: 1
```
- approach 1: simply iterate over tree inorder traversal and store value in array, and then our answer will be kth element of the array
```cpp
void inorder(TreeNode* root, vector<int> &arr){
        if(root==NULL) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    int kthSmallest(TreeNode* root, int k) {
       vector<int> arr;
       inorder(root, arr);
       for(auto i:arr) cout<<i<<" "; cout<<endl;
       return arr[k-1];
    }
```
- approach 2: again we do inorder, just instead of using array we store it in stack
- TC: O(logN + K) , worst O(N+K), SC: O(logN), worst O(N) 
```cpp
int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while(true){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            root = s.top();
            s.pop();
            if(--k == 0) return root->val;
            root = root->right;
        }
    }
```
