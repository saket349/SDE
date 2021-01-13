
/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

vector <int> bottomView(Node *root)
{
   // Your Code Here
   vector<int> v;
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
       v.push_back(it->second);
       it++;
   }
   return v;
}