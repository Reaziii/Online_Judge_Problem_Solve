#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
	int n;
	int res = 1;
	cin >> n;

	int x;
	cin >> x;

	for (int i = 1; i < n; i++) {
		int y;
		cin >> y;

		if (y < x)res++;

		y = x;


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