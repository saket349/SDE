#### we use bottom up approach here, and recursion
#### each node must store some information and should pass that to its succesor node for furthur judgement, <br> for this purpose we build structure which stores information like
- size: size of subtree
- max value: maximum value of Binary subtree rooted at that node
- min value: minimum value of Binary subtree rooted at that node
- ans: size of max BST till that node
- isBST: is that node continues to be BST or not

#### structure- 
```
struct info{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};
```
#### next we need recursive function to solve 
```
info solve(Node* root){
    if(root==NULL) return {0, INT_MAX, INT_MIN, 0, true};       // first base case if root node is NULL, it is still a BST of size zero
    if(root->left==NULL && root->right==NULL) return {1, root->data, root->data, 1, true};   // if root is leaf node, BST of size one, min = max = node->data
    info leftInfo  = solve(root->left);   // left subtree info
    info rightInfo = solve(root->right);  // right info
    info curr;                            // curr judgement
    curr.size = (1 + leftInfo.size + rightInfo.size);  // size of current judgement
    
    if(leftInfo.isBST && rightInfo.isBST && (leftInfo.max < root->data) && (rightInfo.min > root->data)){     // BST condition check
        curr.max = max({root->data, leftInfo.max, rightInfo.max});
        curr.min = min({root->data, leftInfo.min, rightInfo.min});
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }    // if not BST
    curr.ans = max({leftInfo.ans, rightInfo.ans});
    curr.isBST = false;
    return curr;
}
```
