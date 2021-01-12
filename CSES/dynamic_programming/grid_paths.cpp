#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;
int solve() {
	int n;
	cin >> n;

	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < n; j++) {

			if (s[j] == '*') dp[i + 1][j + 1] = -1;
		}

	}




	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) continue;
			if (dp[i][j] == -1) continue;
			ll ret = 0;

			if (dp[i - 1][j] != -1) ret += dp[i - 1][j];
			ret %= mod;

			if (dp[i][j - 1] != -1) ret += dp[i][j - 1];

			ret %= mod;

			dp[i][j] = ret;



		}

	}
	dp[n][n] = dp[n][n] == -1 ? 0 : dp[n][n];
	cout << dp[n][n] << endl;





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
