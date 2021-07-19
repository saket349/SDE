- Inoder traversal
- While visiting each node, keep track of DLL’s head and tail pointers, insert each visited node to the end of DLL using tail pointer

```cpp
Node* solve(Node * root, Node **head, Node **tail){
        if(root==NULL) return NULL;
        Node *left = root->left;
        Node *right = root->right;
        
        solve(root->left, head, tail);
        if(*head==NULL) *head = root;
        
        root->left = *tail;
        if(*tail != NULL) (*tail)->right = root;
        *tail = root;
        
        solve(root->right, head, tail);
        return root;
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if(root==NULL) return root;
        
        Node* head = NULL;
        Node* tail = NULL;
        
        solve(root, &head, &tail);
        return head;
        // your code here
    }
```
