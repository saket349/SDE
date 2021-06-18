##### First we sort the array accd to profit, for anytask mostpreferable to do it is last available day, i.e. if deadline for one task is 6 then most preferable is to do it on 6, if avialble and if not then on 5, if not then 4...1 which ever day is availbale   

```cpp
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

//Function to find the maximum profit and the number of jobs done
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> ans;
        if(n==0){
            ans.push_back(0); ans.push_back(0);
            return ans;
        }
        
        sort(arr,arr+n, comp); // sorting
        
        bool d[101];
        memset(d,false,sizeof(d));   // bool of all time, availablity check
        
        int c = 0, sum = 0;
        for(int i=0;i<n;i++){
            for(int k=arr[i].dead;k>0;k--){
                if(!d[k]){
                    c++; 
                    sum = sum+arr[i].profit;
                    d[k]=true;
                    break;
                }
            }
        }
        ans.push_back(c);
        ans.push_back(sum);
        return ans;
    } 
```

#### Time Complexity O(n^2) , Extra Space O(n)
