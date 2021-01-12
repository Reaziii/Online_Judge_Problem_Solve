#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;
const ll N = 2e6 + 100;
const ll mod = 1e9 + 7;
ll dp[N][2];
void precal() {
    dp[1][0] = 1; // 2 tai alada alada thabe
    dp[1][1] = 1; // 2 tai linked
    for (int i = 2; i < N; i++) {
        ll a = dp[i - 1][0] + dp[i - 1][1]; // 2 ta new block boshabo 1 by 1 size er
        ll b = 2 * dp[i - 1][0]; // extend single one
        ll c = dp[i - 1][0]; // extend both single
        ll d = dp[i - 1][1]; // ager linked block extend korbo
        a %= mod;
        b %= mod;
        c %= mod;
        d %= mod;
        dp[i][0] = (a + b + c) % mod;
        dp[i][1] = (d + a) % mod;
    }
}




void solve() {
    int n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % mod << endl;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    precal();
    cin >> t;
    while (t--) {
        solve();
    }
}
