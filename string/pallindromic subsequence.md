##### First approach:  brute force approach is to start with index i, i from 0 to n-1, and then for each i we take j, last index , and then find if s[i] to s[j]  is pallindrome or not, time complexity: O(n^3)
// we gro from O(n^3) -> O(n^2 logn) -> O(n^2)
##### Second is DP:
- we start with centre, and move in both direction to see if it is pallindrome or not
- we look for even and odd lengt string for each possible centre
```cpp
string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        int start=0, len = 1;
        int low,high;
        for(int i=1;i<n;i++){
            
            // even length substring
            low = i-1;
            high = i;
            while(low>=0 && high<n && s[low]==s[high]){
                if(high-low+1 > len){
                    start = low;len = high - low + 1;
                }
                low--; high++;
            }
            
            // odd length substring
            low = i-1; high = i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                if(high-low+1 > len){
                    start = low; len = high - low + 1;
                }
                low--; high++;
            }
        }
        string a = s.substr(start, len);
        return a;
    }
```
#### this can be furthur more optimised usnig manacher's algorithm which has a time complexity of O(n)
