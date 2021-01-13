#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
	int n, m;
	cin >> n >> m;

	map<int, int> pos;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		int y = m - x;

		if (y < 0) continue;

		if (pos[y] != 0) {
			cout << pos[y] << " " << i << endl;
			return ;

		}

		pos[x] = i;


	}

	cout << "IMPOSSIBLE" << endl;


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