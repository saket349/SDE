### Using Array
```cpp
#include <bits/stdc++.h> 
using namespace std;
#define MAX 1000
class Stack{
    int top;
    public:
        int a[MAX];
        Stack(){top = -1;}
        
        void push(int data){
            if(top>=MAX){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            top = top + 1;
            a[top]=data;
            cout<<a[top]<<endl;
        }
        void pop(){
            if(top<0) {
                cout<<"Stack underflow"<<endl;
                return;
            }
            top = top-1;
        }
        void peak(){
            if(top<0){
                cout<<"Stack underflow"<<endl;
                return;
            }
            cout<<a[top]<<endl;
        }
        void isEmpty(){
            if(top<0){
                cout<<"Stack is empty"<<endl;
                return;
            }
            cout<<"Not empty"<<endl;
        }
        
};
int main(){
    class Stack s;
    s.push(5);
    s.pop();
    s.peak();
}

```

### Using LinkedList
```cpp
#include <bits/stdc++.h> 
using namespace std;
#define MAX 1000
class Stack{
    public:
        int data;
        Stack* next;
};

Stack* newNode(int data){
    Stack* node = new Stack();
    node->data = data;
    node->next = NULL;
    return node;
}
void push(Stack* root, int data){
    Stack* temp = newNode(data);
    temp->next = root;
    root = temp;
    cout<<root->data<<endl;
}
void pop(Stack* root){
    if(!root){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    root = root->next;
}
void peak(Stack* root){
    if(!root){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    cout<<root->data<<endl;
}
void isEmpty(Stack* root){
    if(!root){
        cout<<"Stack empty"<<endl;
        return;
    }
    cout<<"Stack not empty"<<endl;
}
int main(){
    Stack* root = newNode(5);
    push(root, 6);
}
```
