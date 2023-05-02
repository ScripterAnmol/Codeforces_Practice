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
    ll n,q;
    cin>>n>>q;
    vl arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    
    vl dp(n+1,0);
    for(ll i=3;i<=n;i++){
        ll no1=arr[i-1];
        ll no2=arr[i-2];
        ll no3=arr[i-3];
        dp[i]=dp[i-1];
        if(no3>=no2 && no2>=no1){
            dp[i]++;
        }
    }
    
    ll l,r;
    for(ll i=0;i<q;i++){
        cin>>l>>r;
        ll ans=r-l+1;
        if(ans>2)
            ans-=(dp[r]-dp[l+1]);
        cout<<ans<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // loop
    solve();

    return 0;
}
