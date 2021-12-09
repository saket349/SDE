#### Question: [link](https://leetcode.com/problems/regular-expression-matching/)
```
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial)
```

```
Example :

Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab"
```

#### Recursion Approach
```
public boolean isMatch(String text, String pattern) {
        if (pattern.isEmpty()) return text.isEmpty();
        boolean first_match = (!text.isEmpty() &&
                               (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.'));

        if (pattern.length() >= 2 && pattern.charAt(1) == '*'){
            return (isMatch(text, pattern.substring(2)) ||
                    (first_match && isMatch(text.substring(1), pattern)));
        } else {
            return first_match && isMatch(text.substring(1), pattern.substring(1));
        }
    }
```

#### DP Approach:
```
int dp[31][31];
bool isMatch(string s, string p) {
    memset(dp,-1,sizeof(dp));
    return dp1(s, p, 0, 0);
}

bool dp1(string s, string p, int i, int j) {
    // base case
    if (dp[i][j] != -1)  //if solution is already present then return it
        return dp[i][j];
    if (i >= s.size() && j >= p.size()) {
        return true;
    } else if (j >= p.size()) {
        return false;
    }
    
    //check that the char at i and j are matches or not
    bool match = (i < s.size()) && (s[i] == p[j] || p[j] == '.'); 
    
    
    if (j+1 < p.size() && p[j+1] == '*') {
        dp[i][j] = dp1(s, p, i, j+2)/*ignore that char*/ || (match && dp1(s, p, i+1, j))/*match is true so make i+1*/;
        return dp[i][j];
    }
    
    if (match) {
        dp[i][j] = dp1(s, p, i+1, j+1);
        return dp[i][j];
    }
    
    return false;
}
```
- TC: O(N<sup>2</sup>)
- SC: O(N<sup>2</sup>)
