- we solve the problem using hash-table and doubly linked list
- linkedlist is used to maintain the order of our cache
- and hashtable is used to map key to node
```cpp
class LRUCache {
public:
// structure of our doubly linked list
    class Node{
        public:
        int key, val;
        Node *next, *prev;
        Node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    
    // head nd tail initialised to null value
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;  // capacity of our cache
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {        // constructor of our cache
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    } 
    
    void delNode(Node* delnode){
        Node* delnodeNext = delnode->next;
        Node* delnodePrev = delnode->prev;
        delnodeNext->prev = delnodePrev;
        delnodePrev->next = delnodeNext;
    }
    void addNode(Node* addnode){
        Node* temp = head->next;
        addnode->prev = head;
        head->next = addnode;
        addnode->next = temp;
        temp->prev = addnode;
    }
    
    int get(int _key) {
        if(mp.find(_key) != mp.end()){
            Node* resnode = mp[_key];
            int res = resnode->val;
            mp.erase(_key);
            delNode(resnode);
            addNode(resnode);
            mp[_key] = resnode;
            return res;
        }
        
        return -1;
    }
    
    void put(int _key, int value) {
        if(mp.find(_key)!=mp.end()){
            Node* existingNode = mp[_key];
            mp.erase(_key);
            delNode(existingNode);
        }else if(mp.size()==cap){
            Node* temp = tail->prev;
            mp.erase(temp->key);
            delNode(temp);
        }
        Node* newNode = new Node(_key, value);
        addNode(newNode);
        mp[_key] = newNode;
    }
};
```
