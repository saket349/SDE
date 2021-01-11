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
void solve(Node* root, vector<int> &v){
    if(root!=NULL)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                if(i==0)
                v.push_back(temp->data);
                
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
        }
        
    }
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> v;
   solve(root,v);
   return v;
}
