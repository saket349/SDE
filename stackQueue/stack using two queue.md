- one queue will acts as stack : q1, while other will be used to maintain lIFO during push
- this is stack using queue at cost of push data
```cpp
class Stack(){
    queue<int> q1,q2;
    public:
    void push(int data){
        q2.push(data);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    void pop(){
        if(!q1.empty()){
            q1.pop();
            return;
        }
        cout<<"Underflow"<<endl;
    }
};
```
