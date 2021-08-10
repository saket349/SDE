[Qn link](https://leetcode.com/problems/design-a-stack-with-increment-operation/submissions/)
- so we have stack , and we return value only when poped
- so even if we are asked to increase bottom k values and we have not done, no one will know until they ask for pop, which will return only the top value
- so you see we need to increase only one value at a time, so keep a map of index to Node, then increase the kth element of bottom k element with asked value
- and when you pop that element update its prev element so that become new top of bottom k elements
```cpp
class CustomStack {
public:
    class Node{
      public:
        int val;
        int leftInc;
        int index;
        Node* prev;
        Node(int data){
            val = data;
            leftInc = 0;
        }
    };
    unordered_map<int, Node*>  mp;
    int cap;
    Node* top;
    CustomStack(int maxSize) {
        cap = maxSize;
        top = new Node(-1);
        mp.clear();
    }
    
    void push(int x) {
        if(mp.size()==cap) return;
        Node* temp = new Node(x);
        temp->prev = top;
        top = temp;
        top->index = mp.size();
        mp[top->index]  = top;
    }
    
    int pop() {
        if(mp.size()==0) return -1;
        int delValue = top->val;
        mp.erase(top->index);
        int inc = top->leftInc;
        top = top->prev;
        if(mp.size()==0) return delValue;
        top->val = top->val + inc;
        top->leftInc = top->leftInc + inc;
        return delValue;
    }
    
    void increment(int k, int data) {
        if(mp.size()==0) return;
        if(k<mp.size()){
            mp[k-1]->leftInc += data;
            mp[k-1]->val += data;
            return;
        }
        mp[mp.size()-1]->leftInc += data;
        mp[mp.size()-1]->val += data;
    }
};
```
