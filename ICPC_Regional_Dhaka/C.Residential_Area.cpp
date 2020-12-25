#include<bits/stdc++.h>
using namespace std;
const int N = 11;
typedef long long int ll;
int n;

ll pre[N][N];

ll cnt(int si, int sj, int ei, int ej) {
    ll ret = 0;
    int size = 0;
    for (int i = si; i <= ei; i++) {
        for (int j = sj; j <= ej; j++) {
            ret |= (1 << pre[i][j]);
            size++;
            if (size > 10) return 0;
        }
    }
    if (size != 10) return 0;
    ll x = 1 << 10;
    x--;
    return x == ret;
}

ll solve() {
    memset(pre, 0, sizeof(pre));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> pre[i][j];
            pre[i][j]--;

        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= n; l++) {
                    ans += cnt(i, j, k, l);
                }
            }
        }
    }

    return ans;
}



int main() {
    int test_case;
    cin >> test_case;
    for (int i = 1; i <= test_case; i++) {
        printf("Case %d: ", i );
        cout << solve() << endl;
    }








}
