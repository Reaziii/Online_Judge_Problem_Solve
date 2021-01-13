#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
	int n;
	cin >> n;
	map<int, int> cmpr;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = x;
		b[i] = y;
		cmpr[x], cmpr[y];
	}
	int ct = 0;

	for (auto &x : cmpr) {
		x.second = ct++;
	}
	int diff[ct] = {0};

	for (int i = 0; i < n; i++) {
		a[i] = cmpr[a[i]], b[i] = cmpr[b[i]];
		diff[a[i]]++, diff[b[i] + 1]--;
	}

	for (int i = 1; i < ct; i++) diff[i] += diff[i - 1];

	int res = *max_element(diff, diff + ct);
	cout << res << endl;






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