#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;

void solve() {

    int n;
    cin >> n;
    int arr[n + 1];

    for (int i = 1; i <= n; i++) cin >> arr[i];



    std::vector<int> v;

    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        if (it == v.end()) v.push_back(arr[i]);
        else *it = arr[i];
    }
    cout << v.size() << endl;


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
