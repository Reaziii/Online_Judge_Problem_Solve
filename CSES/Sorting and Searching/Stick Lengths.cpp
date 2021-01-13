#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
	int n;
	cin >> n;
	ll arr[n + 2];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);
	ll pre[n + 2] = {0};


	for (int i = 1; i <= n; i++) {
		pre[i] += pre[i - 1] + arr[i];
	}


	ll res = 1e18;

	for (int i = 1; i <= n; i++) {
		ll a1 = pre[i - 1];
		ll a2 = pre[n] - pre[i];

		ll t1 = i - 1;

		ll t2 = n - i;

		ll sum = 0;
		sum = (arr[i] * t1) - a1;
		sum += (a2 - (arr[i] * t2));


		res = min(res, sum);



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