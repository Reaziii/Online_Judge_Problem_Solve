#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;
const ll N = 1e6;

ll dp[5001][5001];
ll arr[N];
ll pre[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] += arr[i];
        pre[i] += pre[i - 1];
    }
    for (int sz = 1; sz <= n; sz++) {
        for (int i = 1; i <= n - sz + 1; i++) {
            if (sz == 1) {
                dp[sz][i] = arr[i];
                continue;
            }
            ll sum1 = pre[i + sz - 1] - pre[i];
            ll sum2 = pre[i + sz - 2] - pre[i - 1];
            ll t1 = arr[i] + (sum1 - dp[sz - 1][i + 1]);
            ll t2 = arr[i + sz - 1] + (sum2 - dp[sz - 1][i]);
            dp[sz][i] = max(t1, t2);
        }
    }
    cout << dp[n][1] << endl;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
