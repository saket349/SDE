
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ull unsigned long long
#define ld long double

#define pb push_back
#define si(x)	scanf("%d",&x)
#define fo(i,n) for(int i=0;i<n;i++)
#define foc(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
//==================================================================================
const int mod = 1000000007;
//==================================================================================
//template<typename T>
void sortColors(vector<int>& nums) {
        int low,mid,high;
        low = mid = 0;
        high = nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }    
            else if(nums[mid] == 1){
                mid++;                
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
    }

int main()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    int k;
     
    vector<int> nums;
    fo(i,n)
    {
        cin>>k;
        nums.pb(k);
    }
    
    sortColors(nums);
    
         
    for(auto i:nums)
    cout<<i;
    
return 0;
}
