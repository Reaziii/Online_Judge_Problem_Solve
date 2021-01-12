#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

int solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	int x = n / 2;

	int y = x;
	int z = x;
	//If 1>n <= 3 then It mission impossible :D
	if (n <= 3) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	if (n == 4) {
		cout << "2 4 1 3" << endl;
		return 0;
	}
	int i = 1;
	if (n % 2 == 1) x += 1;
	while (x--) {
		cout << i << " ";
		i += 2;
	}
	i = 2;
	while (y--) {
		cout << i << " ";
		i += 2;
	}
	cout << endl;

	return 0;

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
