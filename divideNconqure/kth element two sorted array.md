```
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int m = 1, t = 1;
        int i = 1,j = 0;
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                t++;
                i++;
            }
            else if(arr[i]>dep[j]){
                t--;
                j++;
            }
            m=max(m,t);
        }
        return m;
        
    }
};
```
