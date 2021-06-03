```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // fitting to our asumption =>  nums1 should be smallest
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        
        int l = 0, h = n;
        
        while(l<=h){
            // partion for nums1 
            int mid = (l + h)/2;
            // partition for nums2
            int x = (n + m + 1)/2 - mid;
            
            // see if index are valid or not and get their values, left and right
            int left1  = (mid-1<0) ? INT_MIN : nums1[mid-1];
            int left2  = (x-1 < 0) ? INT_MIN : nums2[x-1];
            int right1 = (mid==n) ? INT_MAX : nums1[mid];
            int right2 = (x == m) ? INT_MAX : nums2[x];
            
            if(left1<=right2 && left2<=right1) {  // perfect partition
               
                if((n+m)%2 == 0){
                    double val = (double)(max(left1,left2)+min(right1,right2));
                    // cout<<val;
                    val = double(val/2);
                    return val;
                }
                
                return max(left1,left2);
            }
            if(left1 > right2) {  // we should move left
                h = mid-1;
            }
            if(left2 > right1) { // we should move right
                l = mid+1;
            } 
        }
        return 0.0;
    }
};
```
