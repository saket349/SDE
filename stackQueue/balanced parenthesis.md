- Stack is based on LIFO(last in first out) 
- We push entry barckets in stack
- and when ever we encounter any closing bracket, we take top element from stack, which will we most currently encountered entry bracket
- we know that last encounter entry bracket must have first encounter closing bracket of same type, for e.g. [ ( ] ) is not balanced, as last for "(" we must have ")" as closing  bracket, but we have "]"
```cpp
 bool isValid(string s) {
        stack<char> st;       // stack
        for(int i=0;i<s.size();i++){         // iteration
            if(s[i]==']' || s[i]=='}' || s[i]==')'){         // when we encounter any closing bracket
                if(st.empty()) return false;               // if closing bracket and no entry bracket
                char c = st.top();                      
                st.pop();      
				// closing bracket must be same type as entry bracket was
                if(!((s[i]==')' && c=='(') || (s[i]=='}' && c=='{') || (s[i]==']' && c=='['))) return false;
                continue;
            }
            st.push(s[i]);      // push only for entry brackets
        }
        if(!st.empty()) return false;
        return true;
    }
```
