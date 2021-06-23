#### Steps:
- Calculate the hash value for the pattern
- Calculte the Hash for the 1st window in text
- Repeat the following-
- - If the Hash(pattern) == Hash(text) then match characters onr by one
- - Subtract leftmost (MSB) from the hash value of window
- - Shift the window by one character and add the new character

```cpp
vector<int> solve(string text, string pattern){
    vector<int> ans;
    if(text.length()<pattern.length())
        return ans;
    int l = pattern.length();
    int hashPat = 0;
    int hashWindow = 0;int x;
    for(int i=0;i<l;i++){
        x = int(pattern[i]-'0') + 1;
        hashPat = hashPat + x;
    }
    for(int i=0;i<l;i++){
        x = int(text[i]-'0') + 1;
        hashWindow = hashWindow + x;
    }
    int i = 0;
    while((i+l)<=text.size()){
        if(hashPat==hashWindow){
            bool flag = 1;
            for(int k=0;k<l;k++){
                if(text[i+k]!=pattern[k]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) ans.puah_back(i+1);
        }
        
        if(i+l<text.size())
        {
            x = int(text[i]-text[i+l]) + 1 ;
            hashWindow = hashWindow-x;
            i++;
        }
        else break;
    }
    return ans;
}
```
