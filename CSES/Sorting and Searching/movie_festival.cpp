#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;
const ll N = 2e6;
int a[N], b[N];
void solve() {
	int n;
	cin >> n;
	map<int, int> cmpr;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = x;
		b[i] = y;
		cmpr[x], cmpr[y];
	}
	int ct = 1;

	for (auto &x : cmpr) {
		x.second = ct++;
	}

	vector<int> ab[ct + 10];
	for (int i = 0; i < n; i++) {
		a[i] = cmpr[a[i]], b[i] = cmpr[b[i]];
		ab[b[i]].push_back(a[i]);
	}
	ll res = 0;
	ll total[ct + 10] = {0};
	for (int i = 0; i < ct; i++) {
		if (i) total[i] = total[i - 1];
		for (auto x : ab[i]) {
			total[i] = max(total[i], total[x] + 1);

		}
		res = max(res, total[i]);
	}

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