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
    string str;
    cin>>str;
    ll len=str.length();
    
    ll ans=0;
    for(ll i=2;i<len;i++){
        ans=((str[i-1]-'A')+(str[i-2]-'A'))%26;
        if(ans!=(str[i]-'A')){
            
            cout<<"No\n";
            return;
        }
    }
    
    cout<<"YES\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // loop
    solve();

    return 0;
}
