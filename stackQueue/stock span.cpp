vector <int> calculateSpan(int a[], int n)
    {
        stack<int> s;
        vector<int> v;
        for(int i=0;i<n;i++){
            while(!s.empty() && a[s.top()] <= a[i])
                s.pop();
            
            int val = s.empty()?(i+1):(i-s.top());
            v.push_back(val);
            s.push(i);
        }
        return v;
       // Your code here
    }
