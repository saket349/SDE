//******Jai Hanuman*****************
//******Saket Kumaer*****************
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
//-----------------------FUNCTIONS-------------------------------------------------------------------------------------------------------
//---Returns Pow(x,n)---------
ll power(int x,int n)
{
  int m = abs(n);
  ll ans=1;
    while(m)
    {
        if(m%2==0)
        x=x*2;
        else
        {
            ans=ans*x;
            x=x*x;
        }
    	m=m/2;
    }
    return ans;
}

// Returns factorial of n --------
ll fact(int n) 
{ 
    ll res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

//Returns nCr--------------------
int nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
//--------------------------------------------------------------------------------------------------------------------------------------
vector<int> majorityElement(vector<int> &nums)
{
    vector<int> count(2,0);
    vector<int> ans(2,-1);
    for(auto i:nums)
    {
        if(i==ans[0])
        count[0]++;
        else if(i==ans[1])
        count[1]++;
        else if(count[0]==0)
        {
            ans[0]=i;
            count[0]++;
        }
        else if(count[1]==0)
        {
            ans[1]=i;
            count[1]++;
        }
        else
        {
            count[0]--;
            count[1]--;
        }
    }
    
    count[0]=count[1]=0;
    for(auto i:nums)
    {
        if(ans[0]==i)
        count[0]++;
        if(ans[1]==i)
        count[1]++;
    }
    vector<int> v;
    
    if(count[0]>(nums.size()/3))
    v.pb(ans[0]);
    if(count[1]>(nums.size()/3))
    v.pb(ans[1]);
    
    return v;
}


int main()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    std::vector<int> v(n);
    for(auto &i:v)
    cin>>i;
    vector<int> ans;
    ans=majorityElement(v);
    for(auto i:ans)
    cout<<i<<" ";
return 0;
}
