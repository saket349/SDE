- first stack is to reverse the previous queue operation to make it stack first
- then add new value, then reverse again to make it queue

```cpp
void StackQueue :: push(int x)
{
    
    
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    s1.push(x);
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    // Your Code
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    int x = -1;
    if(s2.empty()) return x;
    x = s2.top();
    s2.pop();
    return x;
        // Your Code       
}
```
