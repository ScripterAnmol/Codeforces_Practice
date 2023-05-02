#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define ll int
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
 
ll inverse(ll x, ll p) {
    return power(x, p - 2, p);
}

void solve(){
    ll n,m;
    cin>>n>>m;
    map<ll,ll> mp;
    ll temp;
    for(ll i=0;i<n;i++){
        cin>>temp;
        mp[temp]++;
    }
    vl arr(m+1);
    for(ll i=1;i<=m;i++){
        cin>>arr[i];
    }
    
    ll start=1;
    ll ans=0;
    for(auto i=mp.rbegin();i!=mp.rend();i++){
        ll flag=0;
        while(start<i->first && flag<i->second){
            ans+=arr[start];
            start++;
            flag++;
        }
        ans+=arr[i->first]*(i->second-flag);
    }
    
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    loop
    solve();

    return 0;
}
