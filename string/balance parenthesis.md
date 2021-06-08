#### in this we version we can only swap adjascent string characters

```
int minimumNumberOfSwaps(string s){
      // code here 
      int n = s.size();
      queue<int> q;
      for(int i=0;i<n;i++){
          if(s[i]=='[')
          q.push(i);
      }
      int count = 0; int ans = 0;
      for(int i=0;i<n;i++){
          if(s[i]=='['){
              count++;
              q.pop();
          }
          else count--;
          if(count<0){
              int p = q.front();
              ans = ans + (p - i);
              // cout<<ans<<endl;
              swap(s[i],s[p]);
              q.pop();
              count = 1;
          }
      }
      return ans;
  }
```
