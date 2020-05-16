 
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

int n;
vector<int>binary;
bool check(int &nu, int &pos){
	return nu>>pos & 1;
}

ll dp[100][2][2][100];
ll solve(int pos = 0,int isp=0,int prev=0,int value=0){
	if(pos == binary.size()) return value;
	if(dp[pos][isp][prev][value]!=-1) return dp[pos][isp][prev][value];
	bool mx = isp?1:binary[pos];
	ll ans = 0;
	for(int i=0;i<=mx;i++){
		bool h = i==mx?isp:1;

		ans += solve(pos+1,h,i,(prev==1 && i==1)+value);
	}

	return dp[pos][isp][prev][value]=ans;
}




ll cal(int n){
	binary.clear();
	for(int i = 0;i<=32;i++){
		if(n>>i <= 0) break;
		binary.pb(check(n,i));

	}
	reverse(all(binary));
	reset(dp,-1);
	return solve();
	// return ans;
}


int main(){
    // input;
    // output;

    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        cin>>n;
        pcase(cn);
        cout<<cal(n)<<endl;

    }
}
