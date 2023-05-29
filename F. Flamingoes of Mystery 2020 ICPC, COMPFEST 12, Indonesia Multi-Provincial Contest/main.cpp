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
#define F first
#define S second
#define pl pair<ll, ll>
#define pd pair<dd, dd>
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
// #define endl "\n";
dd arr[ 200010 ], b[ 200010 ], c[ 200010 ], sum1[ 200010 ], sum2[ 200010 ];
// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}

template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

ll add(ll a, ll b, ll mod) {
    ll result =  (a + b) % mod;
    if (result < 0) {
        result += mod;
    }
    return result;
}

ll mul(ll a, ll b, ll mod) {
    ll result =  (1LL * a * b) % mod;
    if (result < 0) {
        result += mod;
    }
    return result;
}

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if ((b % 2) == 1) {
            res = mul(res, a, mod);
        }
        a = mul(a, a, mod);
        b /= 2;
    }
    return res;
}

ll inverse(ll x, ll p) {
    return power(x, p - 2, p);
}


/*/ ......................................Code Begins....................................../*/
// question padh lo sir pls
// contrainsts bih dekh lo sir plz
// have trust on urself jo tu kr rha hai best approach hai
// aur sir plz shortcut k chkr m ghode mat lagwao, bhot kand ho chuke h ish chkr m
// sir jo dimag m testcase ara hai uspe chala k dekh lo 1 baar code

ll query(ll x,ll n)
{
    if (1 <= x && x <= n)
    {
        cout<<"? "<<x<<endl;
        fflush(stdout);
        ll temp;
        cin>>temp;
        return temp;
    }
}

void solve() {
    ll n;
    cin>>n;
    vl ans;
    ll lastt=0;
    for(ll i=1;i<=n/3;i++){
        ll start=(i-1)*3+1;
        ll endd=i*3;

        ll sum1=0,sum2=0,sum3=0;
        cout<<"? "<<start<<" "<<(start+1)<<endl;
        cin>>sum1;
        cout<<"? "<<(start+1)<<" "<<endd<<endl;
        cin>>sum2;
        cout<<"? "<<start<<" "<<endd<<endl;
        cin>>sum3;

        ll b=sum1+sum2-sum3;
        ll a=sum1-b;
        ll c=sum2-b;

        ans.pb(a);
        ans.pb(b);
        ans.pb(c);
        lastt=c;
    }

    if(n%3==1){
        cout<<"? "<<n-1<<" "<<n<<endl;
        ll sum1=0;
        cin>>sum1;

        ans.pb(sum1-lastt);
    }else if(n%3==2){
        ll sum1=0,sum2=0;
        cout<<"? "<<n-2<<" "<<n-1<<endl;
        cin>>sum1;
        cout<<"? "<<n-1<<" "<<n<<endl;
        cin>>sum2;

        ans.pb(sum1-lastt);
        lastt=sum1-lastt;
        ans.pb(sum2-lastt);
    }
    cout<<"! ";
    for(auto i=ans.begin();i!=ans.end();i++){
        cout<<*i<<" ";
    }cout<<endl;
}

int main()
{
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // loop
    solve();

    return 0;
}
