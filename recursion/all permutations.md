#### for a given string we need to print all permutation possible for that string
- we di this using backtracking and recursion
- we use loop and the consider different possiblities for first index by swaping with other elements, e.g. abcd, here first element can be a or swap it with b or swap it with c or with d
- so by this we get four possibilities, we fix first index and solve for rest, in next recursive call first index is already fixed, so our consideration string is now length-1
- so now we do same for second index and so on
- and while returning we print our string
- when we return we undo the change we did so we can have other consideration this time
```cpp
void solve(string &s, int ind, vector<string> &res, int n){
	        if(ind>=n) {
	            res.push_back(s);
	            return;
	        }
	        for(int i=ind;i<n;i++){
	            swap(s[ind],s[i]);
	            solve(s,ind+1,res,n);
	            swap(s[ind],s[i]);
	        }
	        
	        return;
	    }
		vector<string>find_permutation(string s)
		{
		    vector<string> res;
		    solve(s,0,res,s.size());
		    sort(res.begin(),res.end());
		    return res;
		    // Code here there
		}
```
