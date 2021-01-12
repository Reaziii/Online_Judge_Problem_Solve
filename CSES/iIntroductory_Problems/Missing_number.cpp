#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {
    int n;
    cin >> n;
    ll total = 0;
    if (n % 2 == 0) {
        ll x = n / 2;
        ll y = (n + 1);

        total = x * y;

    }
    else {
        ll x = n;
        ll y = (n + 1) / 2;
        total = x * y;
    }
    n--;
    while (n--) {
        ll x;
        cin >> x;

        total -= x;
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
