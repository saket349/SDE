//code to output nth row of pascal triangle with time complexity O(n)
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

//-------------function to calculate factorial of n-----------
int fact(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 
//------------------------------------------------------------
//------------function to calculate nCr-----------------------
int nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
//------------------------------------------------------------

void findRow(int n)
{
    if(n==1)
    cout<<1;
    else
    {
        std::vector<int> v;
        v.resize(n);
        v[0] = 1;
        v[1] = n-1;
        for(int i = 1;i<n;i++)
        {
            v[i+1] = (v[i]*(n-1-i))/(i+1);
        }
        
        fo(i,n)
        cout<<v[i]<<" ";
    }
}

int main()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    findRow(n);
return 0;
}
