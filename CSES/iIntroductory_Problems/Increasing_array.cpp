#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	for (auto &x : arr) cin >> x;

	ll x = 0;
	ll p = -1;
	ll ans = 0;
	for (auto x : arr) {
		if (p == -1) {
			p = x;
			continue;
		}
		if (x < p) {
			ans += (p - x);
		}
		else p = x;

	}

	cout << ans << endl;





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
