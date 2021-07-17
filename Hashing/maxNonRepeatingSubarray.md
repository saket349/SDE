### Basic idea is to keep track of all elements encountered, see if our block has any repeating element or not, and if it has let say at position 'x', then we move our left pointer to x + 1 (as we have to consider continous array)

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;        // to map element to index
        int c = 0, m = 0;int j =0;
        for(int i=0;i<s.size();i++) mp[s[i]] = -1;    // initializing with -1  as negative index not possible
        
        for(int i=0;i<s.size();i++){
            if(i==0) c++;    // base case considered separately for safety
            else if(mp[s[i]] == -1){     // if not repeating
                c++;
            }else {                            // if repeating
                if(mp[s[i]]>=j)           // repeating and inside our consideration block
                {
                    j = mp[s[i]] + 1;
                    c = i - mp[s[i]];
                } else{                  // repeating but not inside our consideration block
                    c++;
                }
            }
            mp[s[i]]=i;            // value to index mapping
            m = max(m,c);
        }
        return m;
    }
};
```
