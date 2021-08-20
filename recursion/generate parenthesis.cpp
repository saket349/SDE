void solve(int n, int m, vector<string> &res, string &temp){
        if(n==0 && m==0){
            res.push_back(temp);
            return;
        }
        if(n!=0){
            temp.push_back('(');
            solve(n-1, m, res, temp);
            temp.pop_back();
        }
        if(m!=0 && n<m){
            temp.push_back(')');
            solve(n, m-1, res, temp);
            temp.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> res;
        string temp = "";
        solve(n, n, res, temp);
        return res;
    }
