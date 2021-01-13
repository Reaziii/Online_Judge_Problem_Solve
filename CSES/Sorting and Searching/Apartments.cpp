#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];


	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int res = 0;
	int i = 0;
	int j = 0;
	while (i < n && j < m) {

		int x = b[j];
		int y = a[i];

		if (abs(x - y) <= k) {
			res++;
			i++, j++;

		}
		else if (y < x) {
			i++;

		}
		else j++;
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