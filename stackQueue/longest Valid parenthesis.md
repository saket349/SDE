- Given a string, return longest valid parenthesis
```
Constraint
0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
```
```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
```
```cpp
int longestValidParentheses(string s) {
       int ans = 0;
       stack<int> st;
        st.push(-1);
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else {
                st.pop();
                if(st.empty()) st.push(i);
                else ans = max(ans, i-st.top());
            }
        }
        return ans;
    }
```
