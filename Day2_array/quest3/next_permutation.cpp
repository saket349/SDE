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

//-------------function to calculate factorial of n--------
int fact(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 
//-------------------------------------------------------------
//------------function to calculate nCr--------------------
int nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
//-------------------------------------------------------------
void nextPer(int *a,int n)
{
    int first, second;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {first = i;break;}
    }
    //cout<<first<<endl;
    for(int i=n-1;i>first;i--)
    {
        if(a[i]>a[first])
        {second = i;break;}
    }
    swap(a[first],a[second]);
    sort(a+first+1,a+n);
    fo(i,n)
    cout<<a[i]<<" ";
}
int main()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    int a[n];
    fo(i,n)
    cin>>a[i];
    /*
    next_permutation(a,a+n);
    
    fo(i,n)
    cout<<a[i]<<" ";
    */
    
    nextPer(a,n);
return 0;
}
