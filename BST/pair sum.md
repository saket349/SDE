### We need to search if there exist a pair in BST such that their sum = Target
##### we can store the values of BST in sorted array by inorder traversal and then solve using two pointer technique. TC: O(n), SC: O(n), <br> or we can use stack for that, we sue two stack ds, one for normal inorder and other for reverse inorder TC: O(n), SC: O(log(n))

```
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
```
```
  void pushLeft(stack<Node*> &left, Node* root){
      while(root){
          left.push(root);
          root = root->left;
      }
  }
  void pushRight(stack<Node*> &right, Node* root){
      while(root){
          right.push(root);
          root = root->right;
      }
  }
  // root : the root Node of the given BST
  // target : the target sum
  int isPairPresent(struct Node *root, int target)
  {
      if(root==NULL) return 0;
      stack<Node*> left,right;
      pushLeft(left,root);
      pushRight(right,root);
      Node* l = left.top();  left.pop();
      Node* r = right.top(); right.pop();
      while(l && r && (l->data < r->data)){
          int sum = l->data + r->data;
          if(sum==target) return 1;
          if(sum < target) {
              pushLeft(left,l->right);
              l = left.top();
              left.pop();
          }
          if(sum > target) {
              pushRight(right,r->left);
              r = right.top();
              right.pop();
          }
      }
      return 0;
  }

```
