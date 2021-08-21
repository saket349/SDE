Node* solve(Node* node, unordered_map<Node*, Node* > &copy){
    if(node==NULL) return NULL;
    if(copy.find(node) == copy.end()){
        copy[node] = new Node(node->val);
        for(auto i : node->neighbors){
            copy[node]->neighbors.push_back(solve(i, copy));
        }
    }
    return copy[node];
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node* > copy;
        return solve(node, copy);
    }
};
