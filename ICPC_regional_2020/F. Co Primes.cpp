#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;
ll x, y, m;
vector<ll> all;

bool checkbitt(ll num, int pos) {return (num >> pos) & 1;}

const long long int N = 2e6;

bitset<N>pr;
vector<ll> primes;
void seive() {
	pr[0] = pr[1] = 1;
	for (ll i = 2; i * i < N; i++) {
		if (pr[i]) continue;
		for (ll j = i * i; j < N; j += i) {
			pr[j] = 1;
		}
	}

	for (ll i = 0; i < N; i++) if (!pr[i]) primes.push_back(i);
}



ll cal(ll m) {
	ll ans = 0;
	ll tt = all.size();
	ll mmm = 1 << tt;
	for (ll i = 0; i < mmm; i++) {
		ll total = 1;
		ll s = 0;
		for (ll j = 0; j < tt; j++) {
			if (checkbitt(i, j)) {
				s += 1;
				total *= all[j];
				if (total > m) {
					total = m + 1;
				}
			}
		}
		if (total <= m && total != 1) {
			if (s % 2) {
				ans += (m / total);
			}
			else ans -= m / total;
		}
	}
	return ans;
}



void factorr(ll a, ll b) {
	ll div = a - b;
	for (ll i = 0; primes[i] * primes[i] <= div; ++i) {
		if (div % primes[i] == 0) {
			all.push_back(primes[i]);
			while (div % primes[i] == 0) {
				div /= primes[i];
			}
		}
	}
	if (div > 1) {
		all.push_back(div);
	}
}

ll solve() {
	scanf("%lld %lld %lld", &x, &y, &m);
	if (x == 1 && y == 1) {
		return 1;
	}
	if (x == y && x != 1) return 0;
	all.clear();
	if (x < y) swap(x, y);
	m += y;


	factorr(x, y);



	ll bad = cal(m) - cal(y - 1);





	return (m - y + 1) - bad;




}


int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int t = 1;
	seive();
	cin >> t;
	int cs = 1;
	while (t--) {
		printf("Case %d: %lld\n", cs++, solve());
	}
}
