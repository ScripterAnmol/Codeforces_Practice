#include <bits/stdc++.h>
using namespace std;
// #define ll long long
#define ll int
#define dd double
#define vl vector<ll>
#define vvl vector<vl>
#define vd vector<dd>
#define vvd vector<vd>
#define loop ll t; cin>>t; while(t--)
#define all(a) a.begin(), a.end()
#define sz 100005
#define MOD 1000000007
#define debug cout << "here" << endl;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define ff first
#define ss second
#define pl pair<ll, ll>
#define MAXN 200005
ll fac[MAXN];

ll add(ll a,ll b,ll mod){
    ll result =  (a+b)%mod;
    if(result<0){
        result+=mod;
    }
    return result;
}

ll mul(ll a,ll b,ll mod){
    ll result =  (1LL*a*b)%mod;
    if(result<0){
        result+=mod;
    }
    return result;
}

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    while(b){
        if((b%2)==1){
            res=mul(res,a,mod);
        }
        a=mul(a,a,mod);
        b/=2;
    }
    return res;
}

void solve(){
    ll n;
    cin>>n;
    vl arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    
    ll cnt=1;
    sort(arr.begin(),arr.end());
    priority_queue<ll> pq;
    
    for(ll i=1;i<=n;i++){
        if(i==n || arr[i]!=arr[i-1]){
            pq.push(cnt);
            cnt=1;
        }else{
            cnt++;
        }
    }
    
    while(pq.size()>1){
        ll temp1=pq.top();
        pq.pop();
        ll temp2=pq.top();
        pq.pop();
        
        if(temp1>1){
            pq.push(temp1-1);
        }
        if(temp2>1){
            pq.push(temp2-1);
        }
    }
    if(pq.size()==0){
        cout<<"0\n";
    }else{
        cout<<pq.top()<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    fac[0]=1;
    for(ll i=1;i<MAXN;i++){
        fac[i]=mul(fac[i-1],i,MOD);
    }
    
    loop
    solve();

    return 0;
}
