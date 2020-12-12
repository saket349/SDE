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

int main()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int nums[n];
    fo(i,n)
    cin>>nums;
    
    //--------Kadane algo-------------------------
    int sum=nums[0],k=0;
        for(auto i:nums)
        {
            k=k+i;
            sum=max(sum,k);
            if(k<0)
                k=0;
        }
        
    cout<<sum;
return 0;
}
