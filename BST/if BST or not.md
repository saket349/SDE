### for being BST
- The left subtree of a node contains only nodes with keys less than the node’s key
- The right subtree of a node contains only nodes with keys greater than the node’s key. 
- Both the left and right subtrees must also be binary search trees
- Each node (item in the tree) has a distinct key.

### so waht we do is keep acount of min and max value, initialy as INT_MIN and INT_MAX, and then keep updating it as move down the tree, for each level we narrow down min and max difference accordingly. 
### PS: change INT_MIN AND INT_MAX to value according to question, for question with large entries we may change it some valid min and max value
```
int solve(Node* root, int min,int max){
        if(root==NULL) return 1;
        if(root->data <= min || root->data >= max) return 0;
        
        return solve(root->left, min,root->data) && solve(root->right,root->data,max);
    }
    bool isBST(Node* root) 
    {
        if(root==NULL) return 1;
        return solve(root,INT_MIN,INT_MAX);
        // Your code here
    }
```
