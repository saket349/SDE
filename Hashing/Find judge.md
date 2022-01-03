- [question link](https://leetcode.com/problems/find-the-town-judge/)
```
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

1. The town judge trusts nobody.
2. Everybody (except for the town judge) trusts the town judge.
3. There is exactly one person that satisfies properties 1 and 2.

You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
```

```
Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
```

```cpp
int findJudge(int n, vector<vector<int>>& trust) {
        int l = trust.size();
        unordered_map<int, int> cnt1, cnt2;
        for(int i=0;i<l;i++){
            cnt1[trust[i][0]]++;
            cnt2[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(cnt1[i]==0 && cnt2[i]==(n-1)) return i;
        }
        return -1;
    }
```
