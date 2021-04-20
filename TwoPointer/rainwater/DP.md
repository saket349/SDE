##### we have two extra space here , one which store right height size upto that index and other left height size upto that index
![trapping_rain_water](https://user-images.githubusercontent.com/62437314/115459463-b6021e00-a244-11eb-84a4-5d0288f556e4.png)
##### ans is sum of min(r[i],l[i])

```
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
![trapping_rain_water](https://user-images.githubusercontent.com/62437314/115459382-9d920380-a244-11eb-927a-09f5eb1891a0.png)
