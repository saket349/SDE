#### concept is same as of finding predessor of the given key, only difference is here floor can be key itself, but in predessor key can not be its own predessor
### Algorithm ---
```
1 Start at the root Node.
2 If root->data == key, 
     floor of the key is equal 
     to the root.
3 Else if root->data > key, then 
     floor of the key must lie in the
     left subtree.
4 Else floor may lie in the right subtree 
  but only if there is a value lesser than 
  or equal to the key.If not, then root is
  the key.
```
### code snippet from geeks
```
int floor(Node* root, int key)
{
    if (!root)
        return INT_MAX;
  
    /* If root->data is equal to key */
    if (root->data == key)
        return root->data;
  
    /* If root->data is greater than the key */
    if (root->data > key)
        return floor(root->left, key);
  
    /* Else, the floor may lie in right subtree
      or may be equal to the root*/
    int floorValue = floor(root->right, key);
    return (floorValue <= key) ? floorValue : root->data;
}
```

### similarly for ceil, equivalent to successor
### algorithm
```
Imagine we are moving down the tree, and assume we are root node. 
The comparison yields three possibilities,

A) Root data is equal to key. We are done, root data is ceil value.

B) Root data < key value, certainly the ceil value can't be in left subtree. 
   Proceed to search on right subtree as reduced problem instance.

C) Root data > key value, the ceil value may be in left subtree. 
   We may find a node with is larger data than key value in left subtree, 
   if not the root itself will be ceil node.
```
