/*
    Bismillahir Rahmanir Raheem
    Think Twice Code Once
    author : reaziii
*/
#include<bits/stdc++.h>
#define sc(x)        scanf("%lld",&x)
#define pcase(x)     printf("Case %d: ",x++)
#define pn           printf("\n")
#define fri(f)       for(int i=0;i<f;i++)
#define frj(f)       for(int j=0;j<f;j++)
#define reset(x,e)   memset(x,e,sizeof(x))
#define all(x)       x.begin(),x.end()
#define input        freopen("input.txt","r",stdin);
#define output       freopen("output.txt","w",stdout)
#define infi         INT_MAX
#define m_v          3000000
#define pii          pair<int,int>
#define pch          pair<char,char>
#define pll          pair<ll,ll>
#define mgraph       map<int,vector<int> >
#define mp           make_pair
#define pb           push_back
#define clr(x)       memset(x,0,sizeof(x))
#define frx(x,y)     for(int x=0;x<y;x++)
#define deb(x)       cout<<x
#define ideb(i,x)    cout<<i<<" "<<x
#define F            first
#define S            second
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
bool checkbitt(ll num, int pos);
ll setbitt(ll num, ll pos);
ll resetbitt(ll num, int pos);
//.................___Start from here___.................//
//.................._____________________................//
 
 
int solve() {
    ll x, y;
    cin >> x >> y;
    if (x >= y) {
        if (x % 2 == 0) {
            ll p = x * x;
            p -= (y - 1);
            cout << p << endl;
        }
        else {
            ll z = x - 1;
            ll p = z * z;
            p += 1;
            p += (y - 1);
            cout << p << endl;
        }
    }
    else {
        if (y % 2 == 1) {
            ll p = y * y;
            p -= (x - 1);
            cout << p << endl;
        }
        else {
            ll z = y - 1;
            ll p = z * z;
            p += 1;
            p += (x - 1);
            cout << p << endl;
        }
    }
 
 
 
 
 
    return 0;
}
int main() {
// #ifndef ONLINE_JUDGE
//     input;
//     output;
// #endif
    int cs = 1;
    int cn = 1;
    cin >> cs;
    while (cs--) {
        solve();
 
    }
}
 
 
bool checkbitt(ll num, int pos) {
    return (num >> pos) & 1;
}
 
ll setbitt(ll num, ll pos) {
    return (1 << pos) | num;
}
 
ll resetbitt(ll num, int pos) {
    if (!checkbitt(num, pos)) {
        return num;
    }
    else {
        return (1 << pos)^num;
    }
}
 
