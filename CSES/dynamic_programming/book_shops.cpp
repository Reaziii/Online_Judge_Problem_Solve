#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

const ll N = 1e6;
int x, n;
struct dd {
    int cost = 0, page = 0;
};

dd arr[N];
ll dp[N + 1];



int solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].cost;
    }
    for (int i = 1; i <= n; i++)cin >> arr[i].page;

    for (int j = 1; j <= n; j++) {
        for (int i = N; i >= arr[j].cost; i--) {
            dp[i] = max(dp[i], dp[i - arr[j].cost] + arr[j].page);
        }
    }

    ll res = *max_element(dp, dp + x + 1);
    cout << res << endl;







    return 0;
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
