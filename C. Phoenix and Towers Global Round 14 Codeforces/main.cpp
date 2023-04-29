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

void dfs(vl &arr,vl &visited,ll &count,ll cur){
    visited[cur]=1;
    if(arr[cur]==cur){
        arr[cur]=count;
    }else{
        dfs(arr,visited,count,arr[cur]);
        arr[cur]=count;
    }
}

void solve(){
    ll n,m,x;
    cin>>n>>m>>x;
    
    vector<pair<ll,ll>> arr;
    ll temp;
    for(ll i=0;i<n;i++){
        cin>>temp;
        arr.pb({temp,i});
    }
    sort(arr.begin(),arr.end());
    ll start=0;
    
    vl ans(n);
    
    set<pair<ll,ll>> st;
    for(ll i=1;i<=m;i++){
        st.insert({0,i});
    }
    
    for(ll i=0;i<n;i++){
        auto itr=*st.begin();
        st.erase(st.begin());
        itr.first+=arr[i].first;
        ans[arr[i].second]=itr.second;
        st.insert(itr);
    }
    
    cout<<"YES\n";
    for(auto i=ans.begin();i!=ans.end();i++){
        cout<<*i<<" ";
    }cout<<"\n";
    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    loop
    solve();

    return 0;
}
