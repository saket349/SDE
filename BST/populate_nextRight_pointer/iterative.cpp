/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        
        if(root!=NULL){
            q.push(root);
            
            while(q.empty()!=true){
                
                int n=q.size();
                Node* p = q.front();
                
                if(p->left!=NULL)
                    q.push(p->left);
                if(p->right!=NULL)
                    q.push(p->right);
                q.pop();
                n--;
                
                while(n>=1){
                    Node* t = q.front();
                    p->next = t;
                    p=t;
                    if(p->left!=NULL)
                        q.push(p->left);
                    if(p->right!=NULL)
                        q.push(p->right);
                    q.pop();
                    n--;
                }
                p->next = NULL;
            }
        }
        return root;
    }
};