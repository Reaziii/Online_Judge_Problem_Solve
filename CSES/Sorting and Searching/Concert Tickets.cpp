#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
	int n, m;
	cin >> n >> m;
	multiset<int> tickets;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		tickets.insert(x);
	}
	while (m--) {
		int x;
		cin >> x;
		if (tickets.empty()) {
			cout << -1 << endl;
			continue;
		}
		auto it = tickets.upper_bound(x);
		if (it == tickets.begin()) {
			cout << -1 << endl;
			continue;
		}
		it--;


		cout << (*it) << endl;
		tickets.erase(it);


	}

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