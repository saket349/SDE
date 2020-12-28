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

void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
                
        for(int i=0;i<n;i++)
            for(int j=0;j<n/2;j++)
                swap(matrix[i][j],matrix[i][n-j-1]);
                
        fo(i,n)
           {   fo(j,n)
              { cout<<matrix[i][j]<<" "; }
                cout<<endl;
           }
}


int main()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    int x;
    fo(i,n)
    {
        fo(j,n)
        {
            cin>>x;
            v[i].pb(x);
        }
    }
    
    rotate(v);
    
return 0;
}
