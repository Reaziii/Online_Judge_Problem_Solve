#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
	int n, x;
	cin >> n >> x;

	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	int res = 0;
	int i = 0;
	int j = n - 1;
	while (i < j) {
		if (arr[i] + arr[j] <= x) {
			i++, j--;
			res++;

		}
		else {
			j--;
			res++;
		}
	}
	if (i == j) {
		res++;

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