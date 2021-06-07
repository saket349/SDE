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

// we do simple things here, use queue and do level wise traversal, while traversing a row, we already had it stored in queue
// we start with first element, then move along the row, while doing this we stores their both child in queue.

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root==NULL) return root;
        q.push(root);
        while(!q.empty()){
            Node* p = q.front();
            q.pop();
            int n = q.size();
            if(p->left!=NULL) q.push(p->left);
            if(p->right!=NULL) q.push(p->right);
            while(n--){
                Node* t = q.front();
                q.pop();
                p->next = t;
                p = t;
                if(p->left!=NULL) q.push(p->left);
                if(p->right!=NULL) q.push(p->right);
            }
            p->next = NULL;
        }
        return root;
    }
};
