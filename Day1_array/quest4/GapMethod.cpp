// Merging two sorted arrays with O(1)
// extra space
// time complexity: O((n+m)log(n+m))
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

// Function to find next gap.
int newgap(int gap)
{
    if(gap<=1)
    return 0;
    else
    return ( (gap/2) + (gap%2) );
}
int merge(int *a,int *b,int n,int m)
{
    int gap = (n+m);
    int i,j;
    for(gap = newgap(gap);gap > 0;gap = newgap(gap))
    {
        // comparing elements in the first array.
        for(i = 0;i+gap < n;i++)
        {
            if(a[i]>a[i+gap])
            swap(a[i],a[i+gap]);
        }
        
        // comparing elements in both arrays.
        for(j = gap > n ? gap - n : 0 ; i<n && j<m ; i++,j++)
        {
            if(a[i]>b[j])
            swap(a[i],b[j]);
        }
        
        
        if(j<m)
        {
            // comparing elements in the second array.
            for(j = 0; j+gap < m;j++)
            if(b[j]>b[j+gap])
            swap(b[j],b[j+gap]);
        }
    }
    
    
}

int main()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); cout.tie(0);
    
     int n,m;
     cin>>n>>m;
     int a[n],b[m];
     fo(i,n)
     cin>>a[i];
     fo(i,m)
     cin>>b[i];
     
     // Function Call
     merge(a,b,n,m);
     
     for(auto i:a)
     cout<<i<<" ";
     for(auto i:b)
     cout<<i<<" ";
return 0;
}
