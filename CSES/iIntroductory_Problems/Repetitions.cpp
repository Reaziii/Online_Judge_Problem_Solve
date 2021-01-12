#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
	string s;
	cin >> s;
	s += '1';
	ll total = -1;
	ll now = 1 ;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			now++;
		}
		else {
			total = max(now, total);
			now = 1;
		}
	}

	cout << total << endl;

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
