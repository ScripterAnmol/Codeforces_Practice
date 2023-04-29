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

void solve(){
    ll n;
    cin>>n;
    vvl arr;
    ll temp;
    for(ll i=0;i<n;i++){
        cin>>temp;
        vl temp_arr;
        for(ll j=0;j<=i;j++){
            if(j==i){
                temp_arr.pb(temp);
            }else{
                temp_arr.pb(0);
            }
        }
        arr.pb(temp_arr);
    }
    
    for(ll i=0;i<n;i++){
        ll len=n-i;
        ll j;
        for(j=0;j<len;j++){
            if(arr[j+i][j]==1){
                break;
            }
        }
        
        for(ll k=0;k<j;k++){
            arr[k+i+1][k]+=arr[k+i][k]-1;
        }
        for(ll k=j+1;k<len;k++){
            arr[k+i][k-1]+=arr[k+i][k]-1;
        }
    }
    
    for(ll i=n;i>=2;i--){
        for(ll j=0;j<n;j++){
            if(arr[j][j]==i){
                dfs(n,arr,j,j,j,0);
                break;
            }
        }
    }
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=i;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // loop
    solve();

    return 0;
}
