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
vl timer;
map<ll,ll> mp;

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
    ll h,m;
    cin>>h>>m;
    
    string str;
    cin>>str;
    
    ll hh=str[0]-'0';
    hh=hh*10+(str[1]-'0');
    
    ll mm=str[3]-'0';
    mm=mm*10+(str[4]-'0');

    ll ans_h=-1;
    ll ans_m=-1;
    ll minn=INT_MAX;
    
    if(find(timer.begin(),timer.end(),hh)!=timer.end() && mp[hh]<m){
        // cout<<mp[hh]<<"hh"<<endl;
        minn=INT_MAX;
        ans_m=-1;
        
        for(ll i=0;i<timer.size();i++){
            if(timer[i]<m && timer[i]>=mm && mp[timer[i]]<h){
                // cout<<timer[i]<<" "<<mp[timer[i]]<<endl;
                ll calc=timer[i]-mm;
                
                if(calc<minn){
                    minn=calc;
                    ans_m=i;
                }
            }
        }
        
        string temp_h=to_string(hh);
        if(temp_h.size()<2){
            temp_h="0"+temp_h;
        }
        string temp_m=to_string(timer[ans_m]);
        if(temp_m.size()<2){
            temp_m="0"+temp_m;
        }
        if(ans_m!=-1){
            cout<<temp_h<<":"<<temp_m<<"\n";
            return;
        }
    }
    
    
    minn=INT_MAX;
    ans_h=-1;
    
    for(ll i=0;i<timer.size();i++){
        // cout<<timer[i]<<" ";
        if(timer[i]<h && mp[timer[i]]<m){
            ll calc=timer[i]-hh;
            if(calc<=0){
                calc+=h;
            }
            
            if(calc<minn){
                minn=calc;
                ans_h=i;
            }
        }
    }
    ans_h=timer[ans_h];
    
    string temp_h=to_string(ans_h);
    if(temp_h.size()<2){
        temp_h="0"+temp_h;
    }
    cout<<temp_h<<":00"<<"\n";
    // cout<<ans_h<<" 0"<<endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll arr1[]={0,1,2,5,8};
    ll arr2[]={0,1,5,2,8};
    for(ll i=0;i<5;i++){
        for(ll j=0;j<5;j++){
            ll temp1=arr1[i]*10+arr1[j];
            ll temp2=arr2[j]*10+arr2[i];
            timer.pb(temp1);
            mp[temp1]=temp2;
        }
    }
    // cout<<timer.size()<<endl;
    loop
    solve();

    return 0;
}
