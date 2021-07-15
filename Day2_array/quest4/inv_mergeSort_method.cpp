/*
    time complexity: O(nlogn)
    space complexity: O(n)
*/

//******Jai Hanuman*****************
//******Saket Kumar*****************
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

// function to count the numbers of inverse for given array1  and array2
ll countInv(int l[],int k[],int n,int m)
{
    int i=n-1,j=m-1;
    ll ans=0;
    while(i>=0 && j>=0)
    {
        if(l[i]>k[j])
        {
            ans = ans + j + 1;
            i--;
        }
        else
            j--;
    }
    return ans;
}

//function to merge the input array
ll merge(int a[],int first,int mid,int last)
{
    int n1 = mid-first + 1;
    int n2 = last-mid;
    int l[n1],k[n2];
    fo(i,n1)
    l[i] = a[first + i];
    fo(i,n2)
    k[i] = a[mid + 1 + i];
    //find the nu,numbers of inverse 
    ll ans = countInv(l,k,n1,n2);
    
    // after finding total inverse merge the arrays
    int i=0,j=0,r=first;
    while(i<n1 && j<n2)
    {
        if(l[i]<k[j])
            a[r] = l[i++];
        else
            a[r] = k[j++];
        r++;
    }
    while(i<n1)
    {a[r] = l[i];r++;i++;}
    while(j<n2)
    {a[r] = k[j];r++;j++;}
    //------------------------------------------------
    
    return ans;
}
ll mergesort(int a[],int first,int last)
{
    ll ans = 0;
    int mid = (last+first)/2;
    if(first<last)
    {
        ans = ans + mergesort(a,mid+1,last);
        ans = ans + mergesort(a,first,mid);
        ans = ans + merge(a,first,mid,last);
    }
    return ans;
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
    cout<<mergesort(a,0,n-1);

return 0;
}
