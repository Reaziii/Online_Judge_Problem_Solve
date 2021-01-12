#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;
const ll N = 1e6;

ll dp[5001][5001][2];
int arr[N];
ll sol(int i, int j, int c) {
    if (i == j) {
        if (c == 0) return 0;
        return arr[i];
    }

    if (dp[i][j][c] != -1) return dp[i][j][c];




    if (c == 0) {
        return dp[i][j][c] = min(sol(i + 1, j, 1), sol(i, j - 1, 1));
    }

    else return dp[i][j][c] = max(sol(i + 1, j, 0) + arr[i], sol(i, j - 1, 0) + arr[j]);

}






void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cout << sol(1, n, 1) << endl;

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
