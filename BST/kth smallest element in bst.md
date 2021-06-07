#### We kindaa do traversal to smallest and keep count, as in global variable

```
  Node* n = NULL;int c = 0; // global variables to keep account for kth smallest node and count
  int solve(Node* root, int k){
      if(root->left!=NULL){     // first we move to left subtree
          solve(root->left,k);
      }
      c = c + 1; //  then comes current node
      if(c==k) n = root;
      if(c<k && root->right!=NULL){   // then finally right subpart
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

```
