#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
	int n;
	cin >> n;
	set<int> ss;

	while (n--) {
		int x;
		cin >> x;
		ss.insert(x);
	}

	cout << ss.size() << endl;

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