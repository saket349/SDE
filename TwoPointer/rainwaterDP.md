##### we have two extra space here , one which store right height size upto that index and other left height size upto that index
![trapping_rain_water (2)](https://user-images.githubusercontent.com/62437314/115459690-f82b5f80-a244-11eb-9eb0-66871897267c.png)

##### ans is sum of min(r[i],l[i])

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
     if(height.empty())
         return 0;
        
        int n = height.size();
        int r[n],l[n];
        int last = height[0];
        for(int i=0;i<n;i++){
            if(height[i]>last){
                r[i] = 0;
                last = height[i];
            }else{
                r[i]=last-height[i];
            }
        }
        last = height[n-1];
        for(int i=n-1;i>=0;i--){
            if(height[i]>last){
                l[i] = 0;
                last = height[i];
            }else{
                l[i]=last-height[i];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(r[i],l[i]);
        }
        
        return ans;
    }
};
```
