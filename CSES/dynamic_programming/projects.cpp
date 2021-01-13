#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

map<ll, ll> cmpr;
int ct = 0;

void solve() {
    int n;
    cin >> n;
    ll st[n], en[n], pa[n];
    for (int i = 0; i < n; i++) {
        cin >> st[i] >> en[i] >> pa[i];
        en[i]++;
        cmpr[st[i]], cmpr[en[i]];
    }
    for (auto &x : cmpr) {
        x.second = ct++;
    }


    vector<pair<ll, ll>> mp[ct + 1];
    for (int i = 0; i < n; i++) {
        mp[cmpr[en[i]]].push_back({cmpr[st[i]], pa[i]});
    }

    ll cost[ct] = {0};
    ll res = 0;
    for (int i = 0; i < ct; i++) {
        if (i) cost[i] = cost[i - 1];

        for (auto x : mp[i]) {
            cost[i] = max(cost[i], cost[x.first] + x.second);


        }




    }
    cout << cost[ct - 1] << endl;





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
