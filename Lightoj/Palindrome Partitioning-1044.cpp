 
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

string s;
int dp1[10000];
int dp2[1000+10][1000+10];

bool ispali(const ll &right ,const ll &left){
	if(left>=right){
		return 1;
	}
	if(dp2[left][right]!=-1) return dp2[left][right];
	return dp2[left][right] = ispali(right-1,left+1) && s[right]==s[left];
}



ll cal(ll pos=0){
	if(pos == s.size()) return 0;
	auto &tt = dp1[pos];
	if(tt!=-1) return tt;
	ll ans = infi;
	for(ll i = pos;i<s.size();i++){

		if(ispali(i,pos)){
			ans = min(ans,1+cal(i+1));
		}
	}

	return tt =  ans;
}

int main(){
    // input;
    // output;

    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
    	cin>>s;
    	reset(dp1,-1);
    	reset(dp2,-1);
    	pcase(cn);
    	cout<<cal()<<endl;
        
    }
}
