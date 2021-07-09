//******Jai Hanuman*****************
//******Saket Kumaer*****************
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ull unsigned long long
#define ld long double

#define pb	push_back
#define scd(x)	scanf("%d",&x)
#define scld(x)	scanf("%ld",&x)
#define sclld(x)	scanf("%lld,&x)
#define fo(i,n)	for(int i=0;i<n;i++)
#define foc(i,k,n)	for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
//==================================================================================
const int mod = 1000000007;
//==================================================================================
//-----------------------FUNCTIONS-------------------------------------------------------------------------------------------------------
//---Returns Pow(x,n)---------
ll power(int x,int n)
{
  int m = abs(n);
  ll ans=1;
    while(m)
    {
        if(m%2==0)
        x=x*2;
        else
        {
            ans=ans*x;
            x=x*x;
        }
    	m=m/2;
    }
    return ans;
}

// Returns factorial of n --------
ll fact(int n) 
{ 
    ll res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

//Returns nCr--------------------
int nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
//----------------------------------------------------------------------------------------------------------------------------------------

struct Node{
  int data;
  Node* next;
};

Node* reverse(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    Node *head = NULL;
    
    int n;
    cin>>n;
    int x;
    Node* temp;
    cin>>x;
    Node *new_node = new Node();
    new_node->data = x;
    new_node->next=NULL;
    head = new_node;
    temp = new_node;
    
    while(n--)
    {
        cin>>x;
        Node *new_node = new Node();
        new_node->data = x;
        new_node->next=NULL;
        temp->next = new_node;
        temp=new_node;
    }

    head = reverse(head);
    cout<<head->data;
    
return 0;
}
