#include<bits/stdc++.h>
using namespace std;

int main() {
    int a = 3, b = 5;
    int n = 1000;
    int c = n / a;
    int d = n / b;
    int sum1 = ((c * (c + 1)) / 2) * a;
    int sum2 = ((d * (d + 1)) / 2) * b;
    int e = a * b;
    int f = n / e;
    int sum3 = ((f * (f + 1)) / 2) * e;

    cout << sum1 + sum2 - sum3 << endl;



    return 0;
}
