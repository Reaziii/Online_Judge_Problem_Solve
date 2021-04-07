/* BISMILLAHIR RAHMANI RAHIM*/
#include<bits/stdc++.h>
using namespace std;
/*policy based*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
//order_of_key (k) : Number of items strictly smaller than k in set.
//find_by_order(k) : K-th element in a set (counting from zero) in set.
 
/*policy based end*/
 
#define tk cout<<"Case "<<"#"<<i<<": ";
#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt","w",stdout);
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define sf(x) cin>>x;
#define sff(x,y) cin>>x>>y;
#define sfff(x,y,z) cin>>x>>y>>z;
#define fori(x,y) for(ll i=x;i<y;i++)
#define forj(x,y) for(ll j=x;j<y;j++)
#define eachs(y) for(auto &x:y)cin>>x
#define each(y) for(auto x:y)
#define eachp(y) for(auto x:y)cout<<x<<" ";cout<<endl;
#define fs(y) for(auto &x:y)cin>>x
#define fp(y) for(auto x:y)cout<<x<<" "
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define pi acos(-1.0)
#define inf  LLONG_MAX
#define testcase ll t;sf(t);
#define flash fflush(stdout)
#define all(x) x.begin(),x.end()
#define high(x) __builtin_popcount(x)
#define comdebug(a) cout<<#a<<": ";for(auto i:a)cout<<i<<" ";cout<<'\n';
#define minheap priority_queue<ll,vector<ll>, greater<ll>>
#define reset(x,y) memset(x,y,sizeof(x));
typedef long long ll;
typedef unsigned long long llu;
typedef pair<ll, ll> pii;
typedef vector<ll> vl;
typedef vector<int> vi;
 
bool checkbit(llu N, int pos) {return (bool)(N & (1LL << pos));}
llu setbit(llu N, int pos) {  return N = N | (1LL << pos);}
llu resetbit(llu N, int pos) {if (!checkbit(N, pos))return N; else return (1LL << pos)^N;}
 
 
int xx[4] = {0, 0, 1, -1};
int yy[4] = { -1, 1, 0, 0};
#define mod 998244353
 
void solve() {
    ll n;
    sf(n);
    vector<ll>vec;
    ll got0=0;
    for(int i=0;i<n;i++){
    	ll x;
    	sf(x);
    	if(x==0){
    		got0=1;
    	}
    	else{
    		vec.pb(x);
    	}
    }
    n=vec.size();
    ll res = 0, start = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (vec[i] > 0 && start == -1) {
            start = i;
        }
        if (vec[i] > 0)last = i;
        if (vec[i] > 0)res += vec[i];
    }
 
    if (start == -1) {
    	ll mx;
    	if(got0==1){
        	mx=0;
        }
		else mx = *max_element(vec.begin(), vec.end());
 
        cout << mx << " " << 0 << endl;
    }
    else {
    	ll cnt = 0;
        for (int i = start; i <= last; i++) {
            if (vec[i] < 0) {
                if (i == 0)cnt++;
                else if (vec[i - 1] > 0)cnt++;
            }
        }
        cout << res << " " << cnt << endl;
    }
 
}
 
int main() {
    FAST
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}
