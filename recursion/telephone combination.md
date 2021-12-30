- [question link](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```
```cpp
void solve(string digits, vector<string> &ans, string temp, int ind){
        if(ind==digits.size()) {
            ans.push_back(temp);   
            return;
        }
        int k = int(digits[ind]-'0');
        int start = k/8, end = k/7 + 3;
        if(k==9) end++;
        
        k = (k-2) * 3;
        for(int i=start;i<end;i++){
            temp = temp + char('a'+ k + i);
            solve(digits, ans, temp, ind+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> ans;
        solve(digits, ans, "", 0);
        return ans;
    }
```
