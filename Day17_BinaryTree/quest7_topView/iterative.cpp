//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    // Your Code Here
   queue<pair<Node*,int>> q;
   map<int,int> mp;
    //solve(root,0,q);
    if(root!=NULL)
    q.push(make_pair(root,0));
    
    while(q.empty()==false){
        int n = q.size();
        for(int i=0;i<n;i++){
            pair<Node*,int> p;
            p = q.front();
            q.pop();
            if(mp[p.second]==0)
            mp[p.second] = p.first->data;
            if(p.first->left!=NULL)
            q.push(make_pair(p.first->left,p.second-1));
            if(p.first->right!=NULL)
            q.push(make_pair(p.first->right,p.second+1));
        }
    }

   auto it=mp.begin();
   while(it!=mp.end())
   {
       cout<<it->second<<" ";
       it++;
   }
}