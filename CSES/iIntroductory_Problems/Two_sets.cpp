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
#define ff           first
#define ss           second
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
bool checkbitt(ll num, int pos);
ll setbitt(ll num, ll pos);
ll resetbitt(ll num, int pos);
 
 
//.................___Start from here___.................//
//.................._____________________................//
 
 
 
 
int solve() {
	ll n;
	cin >> n;
 
	ll sum = (n * (n + 1)) / 2;
 
	if (sum % 2 == 1) {
		cout << "NO" << endl;
		return 0;
	}
 
 
	cout << "YES" << endl;
 
 
	bool done[n + 10] = {0};
 
	sum /= 2;
	int cnt = 0;
	for (int i = n; i >= 1; i--) {
		if (sum >= i) {
			done[i] = 1;
			cnt++;
			sum -= i;
		}
	}
 
	cout << cnt << endl;
	for (int i = 1; i <= n; i++) {
		if (done[i] == 1) cout << i << " ";
	}
	cout << endl;
 
	cout << n - cnt << endl;
 
	for (int i = 1; i <= n; i++) {
		if (done[i] == 0) cout << i << " ";
	}
 
	return 0;
}
int main() {
// #ifndef ONLINE_JUDGE
// 	input;
// 	output;
// #endif
// #ifdef ONLINE_JUDGE
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// #endif
	int cs = 1;
	int cn = 1;
	//cin>>cs;
	while (cs--) {
		solve();
 
	}
}
 
 
bool checkbitt(ll num, int pos) {return (num >> pos) & 1;}
ll setbitt(ll num, ll pos) {return (1 << pos) | num;}
ll resetbitt(ll num, int pos) {if (!checkbitt(num, pos)) return num; else return (1 << pos)^num;}
 
