/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

void solve(Node* root, int level,int *max_level,vector<int> &v){
    if(root!=NULL)
    {
        if(*max_level < level)
        {
            v.push_back(root->data);
            *max_level = level;
        }
        
        solve(root->right,level+1,max_level,v);
        solve(root->left,level+1,max_level,v);
    }
}
vector<int> rightView(Node *root)
{
   // Your code here
   Node* p = root;
   int max_level = 0;
   vector<int> v;
   solve(p,1,&max_level,v);
   return v;
}
