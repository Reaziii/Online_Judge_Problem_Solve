/******************************************************/
/******************************************************/
/**                                                  **/
/**            BISMILLAHIR RAHMANIR RAHIM            **/
/**         REAZ AHAMMED CHOWDHURY - reaziii         **/
/**  Department of Computer Science and Engineering  **/
/*         INSTITUTE OF SCIENCE AND TECHNOLOGY       **/
/**                                                  **/
/******************************************************/
/******************************************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pcase(x)     printf("Case %d: ",x++)
#define fri(f)       for(int i=0;i<f;i++)
#define frj(f)       for(int j=0;j<f;j++)
#define reset(x)     memset(x,-1,sizeof(x))
#define all(x)       x.begin(),x.end()
#define input        freopen("input.txt","r",stdin);
#define output       freopen("output.txt","w",stdout)
#define infi         INT_MAX
#define linfi        LLONG_MAX
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define mgraph       map<int,vector<int> >
#define pb           push_back
#define clr(x)       memset(x,0,sizeof(x))
#define fro(i,x,y)   for(int i=x;i<y;i++)
#define ech(x,a)     for(auto &x : a)
#define ff           first
#define ss           second
#define vi           vector<int>
#define vl           vector<ll>
#define pi           acos(-1.0)
 
using namespace std;
using namespace __gnu_pbds;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> void read(T& x) {cin >> x;}
template<class H, class... T> void read(H& h, T&... t) {read(h); read(t...);}
template<class A> void read(vector<A>& x) {for (auto &a : x) read(a);}
template<class H> void print(vector<H> &x) {ech(a, x) cout << a << " "; cout << endl;}
template<class P> void debug(P h) {
#ifndef ONLINE_JUDGE
    cerr << h << " ";
#endif
}
template<class W, class... V> void debug(W h, V... t) {
#ifndef ONLINE_JUDGE
    debug(h);
    debug(t...);
    cerr << endl;
#endif
 
}
 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
 
bool checkbitt(ll num, int pos) {return (num >> pos) & 1;}
ll setbitt(ll num, ll pos) {return (1 << pos) | num;}
ll resetbitt(ll num, int pos) {if (!checkbitt(num, pos)) return num; else return (1 << pos)^num;}
ll bigmod(ll a, ll b, ll mod) {if (b == 0) return 1; if (b == 1) return a; if (b & 1) {return ((a % mod) * (bigmod(a, b - 1, mod) % mod)) % mod;} ll x = bigmod(a, b / 2, mod); return (x * x) % mod;}
ll geti() {ll x; read(x); return x;}
ll cdiv(ll a, ll b) {ll ret = a / b; if (a % b) ret++; return ret;}
const ll mod =  1e9 + 7;
const ll N   =  2e5 + 10;
int dx[4] = { +0, +0, +1, -1};
int dy[4] = { -1, +1, +0, +0};
 
//................................___Start from here___...............................//
//................................_____________________..............................//
 
string sss = "LRDU";
 
int vis[8][8];
string s;
int n;
 
bool valid(int x, int y) {
    if (x < 0 || y < 0 || x >= 7 || y >= 7) return false;
    return 1;
 
 
}
ll count(int pos = 0, int x = 0, int y = 0, char m = '0') {
    if (pos == 48) return 1;
    if (vis[0][6]) return 0;
 
 
    swap(x, y);
    if (m == 'L' && (x == 0 || vis[y][x - 1]) && y > 0 && y < 6 && !vis[y - 1][x] && !vis[y + 1][x]) return 0;
    if (m == 'R' && (x == 6 || vis[y][x + 1]) && y > 0 && y < 6 && !vis[y - 1][x] && !vis[y + 1][x]) return 0;
    if (m == 'U' && (y == 0 || vis[y - 1][x]) && x > 0 && x < 6 && !vis[y][x - 1] && !vis[y][x + 1]) return 0;
    if (m == 'D' && (y == 6 || vis[y + 1][x]) && x > 0 && x < 6 && !vis[y][x - 1] && !vis[y][x + 1]) return 0;
    swap(x, y);
 
 
 
    if (s[pos] == '?') {
        ll ret = 0;
        fri(4) {
 
            int ax = x + dx[i];
            int ay = y + dy[i];
 
            if (ax < 0 || ay < 0) continue;
            if (ax > 6 || ay > 6) continue;
            if (vis[ax][ay]) continue;
            vis[ax][ay] = 1;
            ret += (count(pos + 1, x + dx[i], y + dy[i], sss[i]));
            vis[ax][ay] = 0;
        }
        vis[x][y] = 0;
        return ret;
 
 
    }
    char t = s[pos];
    if (t == 'L') x--;
    if (t == 'R') x++;
    if (t == 'U') y--;
    if (t == 'D') y++;
 
 
    if (x < 0 || y < 0 || x > 6 || y > 6 || vis[x][y]) return 0;
    vis[x][y] = 1;
    ll ret = count(pos + 1, x, y, t);
    vis[x][y] = 0;
    return ret;
 
 
 
 
}
 
 
 
 
 
 
int solve() {
    read(s);
    n = s.size();
 
    vis[0][0] = 1;
    cout << count() << endl;
 
 
    return 0;
}
int main(int argc, char* argv[]) {
 
    if (argc <= 1) {
#ifndef ONLINE_JUDGE
        input;
        output;
#endif
#ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
#endif
    }
 
 
    int cs = 1, cn = 1;
    // read(cs);
    while (cs--) {
        solve();
 
    }
}
