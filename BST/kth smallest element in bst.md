```
class Solution{
  public:
    Node* n = NULL;int c = 0;
    int solve(Node* root, int k){
        if(root->left!=NULL){
            solve(root->left,k);
        }
        c = c + 1;
        if(c==k) n = root;
        if(c<k && root->right!=NULL){
            solve(root->right,k);
        }
    }
    // Return the Kth smallest element in the given BST 
    int KthSmallestElement(Node *root, int K)
    {
        // int c = 0;
        solve(root,K);
        if(root==NULL || n==NULL) return -1;
        else return n->data;
        //add code here.
    }
};
```
