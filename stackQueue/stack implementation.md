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
// C++ program for linked list implementation of stack
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a stack
class StackNode {
public:
	int data;
	StackNode* next;
};

StackNode* newNode(int data)
{
	StackNode* stackNode = new StackNode();
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(StackNode* root)
{
	return !root;
}

void push(StackNode** root, int data)
{
	StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	cout << data << " pushed to stack\n";
}

int pop(StackNode** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

// Driver code
int main()
{
	StackNode* root = NULL;

	push(&root, 10);
	push(&root, 20);
	push(&root, 30);

	cout << pop(&root) << " popped from stack\n";

	cout << "Top element is " << peek(root) << endl;
	
	cout<<"Elements present in stack : ";
	//print all elements in stack :
	while(!isEmpty(root))
	{
		// print top element in stack
		cout<<peek(root)<<" ";
		// remove top element in stack
		pop(&root);
	}

	return 0;
}

```
