// nearly sorted array means, for position i, value which should be there after sorting is in the range of i-k to i+k

void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    fo(i,n) cin>>a[i];
    priority_queue<ll, vector<ll>, greater<ll> > q;
    ll cnt = 0;
    ll j = 0;
    for(int i=0;i<n;i++){
        cnt++;
        q.push(a[i]);
        if(cnt == k){
            a[j++] = q.top();
            q.pop();
            cnt--;
        }
    }
    while(!q.empty()){
        a[j++] = q.top();
        q.pop();
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
