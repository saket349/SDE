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
int *findTwoElement(int *arr, int size) {
        // code here
        int i;
       static int r[2];
    //cout << " The repeating element is ";
 
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            r[0] = abs(arr[i]);
    }
 
    //cout << "and the missing element is ";
    for (i = 0; i < size; i++) {
        if (arr[i] > 0)
            r[1] =  (i + 1);
    }
    return r;
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
    auto p = findTwoElement(a,n);
    cout<<p[0]<<" "<<p[1];
    
return 0;
}
