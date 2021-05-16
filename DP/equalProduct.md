## this is type of 0-1 Knapsack problem or subset sum problem
```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        
        // calculate total sum of array
        for(auto i:nums){
            sum = sum + i;
        }
        
        // partition posible onlhy if sum is divisible by 2
        if(sum%2 == 1) return false;
        else{
            
            sum = sum/2;
            if(sum == 0) return true;
            
            int n = nums.size();
            if(n==0) return false;
            
            bool t[n+1][sum+1];
            
            // n == 0
            for(int i=0;i<=sum;i++) t[0][i] = 0;
            
            // sum == 0
            for(int i=0;i<=n;i++) t[i][0] = 1;
            
            // main body
            for(int i=1;i<=n;i++){
                for(int j=1;j<=sum;j++){
                    if(nums[i-1] <= j){
                        t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j]; 
                    }else t[i][j] = t[i-1][j];
                }
            }
            
            return t[n][sum];
        }
    }
};
```
