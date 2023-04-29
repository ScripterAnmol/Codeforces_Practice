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
#define MAXN   10000007
ll spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
        spf[i] = i;
        
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (ll i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (ll j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

void calc(map<ll,ll> &mp,ll temp){
    while (temp != 1)
    {
        mp[spf[temp]]++;
        temp = temp / spf[temp];
    }
}

void solve(){
    ll n;
    cin>>n;
    
    map<ll,ll> mp;
    // ll count=0;
    
    ll temp;
    for(ll i=0;i<n;i++){
        cin>>temp;
        calc(mp,temp);
    }
    
    ll ans=0;
    ll count=0;
    for(auto i=mp.begin();i!=mp.end();i++){
        temp=i->second;
        ans+=temp/2;
        count+=temp%2;
    }
    
    cout<<ans+count/3<<"\n";
        
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    sieve();
    loop
    solve();

    return 0;
}
