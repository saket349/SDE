### for being BST
- The left subtree of a node contains only nodes with keys less than the node’s key
- The right subtree of a node contains only nodes with keys greater than the node’s key. 
- Both the left and right subtrees must also be binary search trees
- Each node (item in the tree) has a distinct key.

### so what we do we do tree traversal and see if min, max if such that root->data is more then min and less then max strictly
### so while traversing we keep track of the narrowing min and max allowed values as it goes, looking at each node only once. The initial values for min and max should be INT_MIN and INT_MAX — they narrow from there. 
```
int solve(Node* root, int min,int max){
        if(root==NULL) return 1;
        if(root->data < min || root->data > max) return 0;
        
        return solve(root->left, min,root->data-1) && solve(root->right,root->data+1,max);
    }
    bool isBST(Node* root) 
    {
        if(root==NULL) return 1;
        return solve(root,INT_MIN,INT_MAX);
        // Your code here
    }
```
