#define ll long long
#define fo(i,n)	for(int i=0;i<n;i++)

ll countInv(int l[],int k[],int n,int m)
{
    int i=n-1,j=m-1;
    ll ans=0;
    long double z;
    long double x;
    while(i>=0 && j>=0)
    {   z=double((l[i]*1.0)/2);
        x=double(k[j]*1.0);
        if(z>x)
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
ll merge(vector<int> & a,int first,int mid,int last)
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
ll mergesort(vector<int> &a,int first,int last)
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

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
    }
};
