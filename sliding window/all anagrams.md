- For any subarray to be our anagram, ot should have same count of same characters as of pattern, no other character should exist
- we map our patter characters with their frequency
- so if any subrray match that, we stores its starting point
- we use cnt to see how many charcter of our patterns got their exacc count, and if cnt == 0, that meant all character got their exacc count, and there we have our one solution
```cpp
vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        for(int i=0;i<p.size();i++){
            mp[p[i]]++;
        }
        int cnt = 0;
        cnt = mp.size();
        int l = 0;
        int  k = p.size();
        vector<int> v;
        for(int i=0;i<s.size();i++){
            l++;
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    cnt--;
            }
            if(l>k){
                if(mp.find(s[i-k])!=mp.end()){
                    if(mp[s[i-k]]==0) cnt++;
                    mp[s[i-k]]++;
                }
            }
            if(cnt==0)
                v.push_back(i-k+1);
        }
        return v;
    }
```
