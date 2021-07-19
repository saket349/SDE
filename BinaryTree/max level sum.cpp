// we do simple level traversal
int maxLevelSum(Node* root) {
        // Your code here
        queue<Node*> q;
        int ans = 0;
        if(root==NULL) return ans;
        ans = root->data;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int temp = 0;
            for(int i=0;i<n;i++){
                Node* p = q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                temp = temp + p->data;
            }
            
            ans = max(ans, temp);
        }
        
        return ans;
    }
