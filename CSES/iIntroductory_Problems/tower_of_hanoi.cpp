#include<bits/stdc++.h>
 
using namespace std;
vector<pair<int, int>> res;
 
 
void cnt(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << from << " " << to << endl;
 
        return ;
    }
    cnt(n - 1, from, aux, to);
    cout << from << " " << to << endl;
    cnt(n - 1, aux, to, from);
 
 
}
 
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int total = 0;
 
    for (int i = 1; i <= n; i++) {
        total += total;
        total += 1;
 
 
    }
 
    cout << total << endl;
    cnt(n, 1, 3, 2);
 
 
 
 
 
}
