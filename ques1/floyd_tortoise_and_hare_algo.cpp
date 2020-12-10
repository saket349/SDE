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
 int findDuplicate(vector<int>& nums) {
     //initialise both tortoise and hare with nums[0];
        int tortoise = nums[0];
    int hare = nums[0];
    
    //now hare moves two step at time while tortoise moves just one till they both meet at some point
    do {
      tortoise = nums[tortoise];
      hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Find the "entrance" to the cycle.
    //now both toroise and hare moves one step each
    tortoise = nums[0];
    while (tortoise != hare) {
      tortoise = nums[tortoise];
      hare = nums[hare];
    }

    return hare;
    }
    
    
int main()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); cout.tie(0);
    //intput the length of array;
       int n;
        cin>>n;
    //input elements;
       vector<int> v;
       int x;
       fo(i,n)
       {
           cin>>x;
           v.pb(x);
       }
       
       cout<<solve(v);
    
return 0;
}
