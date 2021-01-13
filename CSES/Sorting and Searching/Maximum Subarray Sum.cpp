#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
	int n;
	cin >> n;

	ll res = -1e18;
	ll t = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		t += x;
		res = max(res, t);


		if (t < 0) t = 0;




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