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
    ll q;
    cin>>q;
    
    vl cus;
    priority_queue<pair<ll,ll>> pq;
   
   ll cur=1;
   ll start=0;
   ll query,m;
   vl visited;
   
   vl ans;
   for(ll i=0;i<q;i++){
       cin>>query;
       if(query==1){
           cin>>m;
           cus.pb(m);
           visited.pb(0);
           pq.push({m,-cur});
           cur++;
       }else if(query==2){
           while(visited[start]){
               start++;
           }

           visited[start]=1;
           ans.pb(start+1);
       }else if(query==3){
           while(visited[-(pq.top().second+1)]){
               pq.pop();
           }
           auto itr=pq.top();
           pq.pop();

           visited[-(itr.second+1)]=1;
           ans.pb(-itr.second);
       }
   }
   
   for(auto i=ans.begin();i!=ans.end();i++){
       cout<<*i<<" ";
   }
   cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // loop
    solve();

    return 0;
}
