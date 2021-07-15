/*
  time complexity: O(logn)
  space complexity: O(1)
*/ 
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
//--------functions---------------------------------
//----------Pow(x,n)--------------------------------
ll power(int x,int n)
{
  int m = abs(n);
  ll ans=1;
    while(m)
    {
        if(m%2==0)
        x=x*x;
        else
        {
            ans=ans*x;
            x=x*x;
        }
    	m=m/2;
    }
    return ans;
}

int main()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); cout.tie(0);
    int x,n;
    cin>>x>>n;
    cout<<power(x,n);
return 0;
}
