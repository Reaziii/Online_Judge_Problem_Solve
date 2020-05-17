 
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
string y;
ll dp[100][100];
ll solve(){

	int n = y.size();
	for(int i = n-1 ; i>=0;i--){
		for(int j = 0 ; j < n ;j++){
			if(i>=j) {
				dp[i][j]=0;
				continue;
			}
			else if(y[i]==y[j]) dp[i][j]=dp[i+1][j-1];
			else{
				dp[i][j] = 1+min(dp[i+1][j],dp[i][j-1]);
			}
		}
	}

	return dp[0][n-1];


}


ll cal(){
	reset(dp,0);
	return solve();
}



int main(){
    // input;
    // output;

    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        
        cin>>y;
        pcase(cn);
        cout<<cal()<<endl;
        


    }
}
