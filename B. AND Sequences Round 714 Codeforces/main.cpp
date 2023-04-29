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
    ll temp;
    map<ll,ll> mp;
    vl arr(32,0);
    for(ll i=0;i<n;i++){
        cin>>temp;
        mp[temp]++;
        for(ll j=0;j<32;j++){
            if(temp&(1<<j)){
                arr[j]++;
            }
        }
    }
    
    ll ans=0;
    
    for(auto i=mp.begin();i!=mp.end();i++){
        // if(i->first==0){
        //     ans=mul(mp[0],mp[0]-1,MOD);
        // }else{
        if(i->second>1){
            ll flag=1;
            temp=i->first;
            for(ll j=0;j<32;j++){
                if(temp&(1<<j) && arr[j]!=n){
                    flag=0;
                    break;
                }
            }
            
            if(flag){
                temp=mul(i->second,i->second-1,MOD);
                temp=mul(temp,fac[n-2],MOD);
                ans=add(ans,temp,MOD);
            }
        }
    }
    cout<<ans<<"\n";
    
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
