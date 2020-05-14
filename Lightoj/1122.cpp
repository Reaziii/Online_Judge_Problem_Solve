 
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
//................._____________________.................//
int n,m;
int arr[15];
int dp[20][20];
//Here We will store the last value and the position in dp


ll sol(vector<int>v,ll point,ll ln){
	if(point==m) return 1;
	if(dp[point][ln]!=-1) return dp[point][ln];
	ll ans = 0;
	fri(v.size()){
		//we can not use all number for next digit cz we have restriction
		//So we are cheking if the number is available for us
		//Next if its the first number then we can take it and so we use ln == 0
		//If ln (last number) is 0 then we can take it cz it is first digit
		//We can also use point (position).
		//If possition is 0 then we can take every number
		if(ln == 0 || abs(ln-v[i])<=2){
			ans += sol(v,point+1,v[i]);
		}
	}
	return dp[point][ln] = ans;

}

int main(){
	//input;
    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        cin>>n>>m;
        vector<int> v;
        std::vector<int> x;
        reset(dp,-1);
        fri(n){
        	int x ;cin>>x;
        	v.pb(x);
        }
        pcase(cn);
        cout<<sol(v,0,0)<<endl;

        


    }
}
