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
//template<typename T>

int maxprofit(vector<int> &prices)
{
    int i=0;
    int ans=0;
    int min=INT_MAX;
    int n=prices.size();
    fo(i,n)
    {
        if(prices[i]<min)
        min=prices[i];
        else
        ans=max(ans,prices[i]-min);
    }
    
    return ans;
}


int main()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    vector<int> v;
    int x;
    fo(i,n)
    {
            cin>>x;
            v.pb(x);
    }
    
    cout<<maxprofit(v);
    
return 0;
}
