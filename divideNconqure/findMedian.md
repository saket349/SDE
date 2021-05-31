#### Steps:- 
- we know that limit of our consideration is 1 to INT_MAX, here 2000
- we know for given sorted array median is value at middle index
- using binary search we calculate mid, for current limits, and 
- see how many numbers are there in each row which are smaller or equal to current mid, and take sum of all, we do this again by using binary search method
- if cnt > k(desired cnt) then we decrease h
- else if cnt < k, we increase l
- and if cnt == k, then too we increase l, cause is how many number are lesser or equal to mid, so it is including mid, but be want ans such that on left it there should be k numbers

```
int upper_count(vector<int> &v, int x){
    int l=0,r=v.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(v[mid]>x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

class Solution{   
public:             
    int median(vector<vector<int>> &matrix, int r, int c){
        int l,h;
        l = 1, h = 2000;
        int k = (r*c + 1)/2;
        int cnt = 0;
        while(l<h){
            int mid = (l+h)/2;
            cnt = 0;
            for(int i=0;i<r;i++)
                cnt = cnt + upper_count(matrix[i], mid);
            
            if(cnt<k) l = mid + 1;
            else h = mid;
        }
        
        return l;
    }
};
```
