```cpp
string longestCommonPrefix(vector<string>& s) {
        int n = s.size();     // Size of vector s
        if(n==1) return s[0];     // Special case
        string a = "";                // string which we will be returning
        sort(s.begin(),s.end()); //  lexigraphic sorting, on the alphabetical order basis
        int l = min(s[0].length(),s[n-1].length());  
        int i = 0;
        while(i<l && s[0][i]==s[n-1][i]){   // condition 
            a = a + s[0][i];
            i++;
        }
        return a;
    }
```
