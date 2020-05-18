 
/*
  Bismillahir Rahmanir Raheem
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
#define max_value    3000000
#define pii          pair<int,int>
#define pch          pair<char,char>
#define pll          pair<ll,ll>
#define mgraph       map<int,vector<int> >
#define mp           make_pair
#define pb           push_back
#define clr(x)       memset(x,0,sizeof(x))

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


 //.................___Start from here___.................//
//.................._____________________................//

ll k,lim;
vector<ll> digits;
ll dp[15][3][100][100];
void getdigit(ll n){
	while(n){
		digits.pb(n%10);
		n/=10;
	}
}
ll solve(ll pos,bool isp,ll value, ll sum){
	if(pos == lim){
		if(value==0 && sum%k==0 && sum){
			return 1;
		}
		return 0;
	}
	if(dp[pos][isp][value][sum]!=-1) return dp[pos][isp][value][sum];
	ll mx = isp?9:digits[pos];
	ll ans = 0;
	for(ll i = 0;i<=mx;i++){
		bool h = (i==digits[pos])?isp:1;

		ans += solve(pos+1,h,(((value*10)%k)+i)%k,sum+i);
	}
	return dp[pos][isp][value][sum]= ans;
}
ll sol(ll n){
	reset(dp,-1);
	ll ans = 0;
	digits.clear();
	getdigit(n);


	lim = digits.size();
	reverse(all(digits));
	ans = solve(0,0,0,0);
	return ans;
}

int main(){
	int cn=1;
	int cs;
	cin>>cs;
	while(cs--){
		ll a,b;
		cin>>a>>b>>k;
		if(a>b)swap(a,b);
		pcase(cn);
		if(k==1) cout<<b-a+1<<endl;
		else if(k>81) cout<<0<<endl;
		else cout<<sol(b)-sol(a-1)<<endl;
	}

}
