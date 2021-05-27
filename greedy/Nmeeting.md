<p>There are two variations of this qn, one is to calculate the no of max meeting which can be held and other is to return the indices of those meeting.</p>

#### the idea for the codee is to store the endtime along with index as pair in one dataStructure and then store according to end time, then iterate over that DS, and keep updating current time 

```
int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],i});
        }
        int c = -1; int ans = 0;
        sort(v.begin(),v.end());
        for(auto i:v){
            if(start[i.second]>c) {     // if next event starts in some time latter to current meeting end time then meeting can be held
                ans++;                  // for type 2 variation stores indices of meeting two in some DS and return that instead of ans
                c = i.first;
            }
        }
        return ans;
        // Your code here
    }
```
