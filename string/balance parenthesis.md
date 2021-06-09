#### in this we version we can only swap adjascent string characters
##### any opening bracket should have its closing bracket and it should come before it so to make it perfect parenthesis sequence
##### we keep count and increase it if we encounter \[ and decrease for ] thus if out count become negative we know we had ] without precedding \[, thus to make it right we need to use closest \[ and numbe of swaps will become index of closest \[ - current index  
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
