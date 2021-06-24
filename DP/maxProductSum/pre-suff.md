### We create two arrays, one for prefix product and other for suffix product and ans is max(max of prefix products, max of suffix products)
### cummulative product become 0 if num at that position is 0, so we start with 1 again for taking cummulative of nums of later indices

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long pre[nums.size()];
        long long suf[nums.size()];
        long long m = max(nums[0],nums[nums.size()-1]);
        long long a,b; a=b=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                a = 1;
                pre[i]=0;
            }else{
                a = a*nums[i];
                pre[i]=a;
            }
            
            if(nums[nums.size() - (i+1)]==0){
                b=1;
                suf[i]=0;
            }else{
                b=b*nums[nums.size()-(i+1)];
                suf[i]=b;
            }
            
            m = max(m,max(pre[i],suf[i]));
        }
        
        return m;
    }
};
```
