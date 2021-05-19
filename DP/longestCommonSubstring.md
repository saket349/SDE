### parent qn LCS

```
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); int m = nums2.size();
        int t[n+1][m+1];
        int M = 0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)
                    t[i][j] = 0;
                else if(nums1[i-1] == nums2[j-1])
                    t[i][j] = t[i-1][j-1] + 1;
                else t[i][j] = 0;
                M = max(M,t[i][j]);
            }
        }
        
        return M;
    }
};
```
