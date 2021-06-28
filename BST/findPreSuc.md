### To find inorder predessor and successor
### Algorithm ---
```
Input: root node, key
output: predecessor node, successor node

1. If root is NULL
      then return
2. if key is found then
    a. If its left subtree is not null
        Then predecessor will be the right most 
        child of left subtree or left child itself.
    b. If its right subtree is not null
        The successor will be the left most child 
        of right subtree or right child itself.
    return
3. If key is smaller then root node
        set the successor as root
        search recursively into left subtree
    else
        set the predecessor as root
        search recursively into right subtree
```
### Code ---
```cpp
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL) return;
    if(root->key == key){
        findPreSuc(root->left,pre,suc,key);
        findPreSuc(root->right,pre,suc,key);
        return;
    }
    if(root->key < key){
        pre = root;
        findPreSuc(root->right,pre,suc,key);
        return;
    }
    suc = root;
    findPreSuc(root->left,pre,suc,key);
    return;
// Your code goes here

}
```
