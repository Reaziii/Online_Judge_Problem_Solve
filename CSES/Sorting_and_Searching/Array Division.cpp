#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

ll n, k;
ll arr[10000000 + 100];


bool ok(ll mid) {
	ll sum = 0;
	ll cnt = 1;
	for (ll i = 1; i <= n; i++) {
		if (arr[i] > mid) return 0;
		if (sum + arr[i] > mid) cnt++, sum = arr[i];
		else sum += arr[i];

	}
	return cnt <= k;
}



void solve() {
	cin >> n >> k;
	ll total = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	ll low = 0;
	ll high = total;

	ll mid = -1;
	ll ans = -1;
	while (low < high) {
		mid = (low + high) / 2;

		if (ok(mid)) high = mid, ans = mid;
		else low = mid + 1;
	}

	cout << (k == 1 ? total : ans) << endl;

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
