#include<bits/stdc++.h>
using namespace std;
long long int __lcm(long long int a, long long int b) {
    return (a * b) / __gcd(a, b);


}




int main() {
    long long int lcm = 1;
    for (long long int i = 1; i <= 20; i++) {
        lcm = __lcm(i, lcm);
    }

    cout << lcm / 16 << endl;

    return 0;
}
