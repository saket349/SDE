- first approach is brute force recursive solution where wes stores all permutations and sort them and then find the kth permutation
- time complexity will be O( n!\*n + n!log(n!) ), space complexity: O(n!) 

#### Optimised solution would be mathematical solution to find kth permutation, one we used to do in jee
- If example we have n = 4: (1 2 3 4); so total number of permutation is 4\*3\*2\*1 = n! = 24 = fact
- so let k = 17, i.e. we wants 17th permutation; 
- so how we start: we fix 1 => so total permutaion  with 1 as first index is 3! = 6 = fact< k so we decrease k as k =k-fact = 17 - 6 = 11, we move to 2 and do same; k=k-fact = 11 - 6 = 5 then 3, but here fact = 6 > k;
- so we get that "3" is our first index
- so we fix, mark 3 as visited, fact = fact/(m-1) and recur to smaller string and do same

```cpp
void solve(int n, int k, string &s, long long &fact, int m, bool vis[]){
        if(k==0 || m<=0) return;     // check statement;  desired string already achivied
        fact = fact/m;                     // max number of permutation if we fix first index
        if(fact==0) return;             
        for(int i=1;i<=n;i++){       // loop to check and fix current index 
            if(vis[i]) continue;         // if that number already considered before
            if(k>fact){                    // if current permutation is lexigrographically smaller then required permutation
                k = k - fact;
            }else{                        // if current index is to be considered
                s=s+char(i+'0');
                vis[i]=true;
                solve(n, k, s, fact, m-1, vis);
                break;
            }
        }
    }
    string getPermutation(int n, int k) {
        string res;
        long long factorial = 1;
        for(int i=2;i<=n;i++) factorial = factorial*i;     // max number of permutation
        bool vis[n+1];
        memset(vis,false, sizeof(vis));
        solve(n, k, res, factorial, n, vis);
        return res;
    }
```
