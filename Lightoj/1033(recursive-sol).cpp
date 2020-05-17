 
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

//If the sentence is abcadc then :
//if right one and left one is same then they are lovely couple so I dont want to do with them
//But if they are not same then I m goint left-1,right and left,right-1 with adding 1 and asking which is minimum
//And this is answer




string s;
int dp[100][100];
ll solve(ll left,ll right){
	if(left>right) return 0;
	// cout<<left<<" "<<right<<endl;
	if(dp[left][right]!=-1) return dp[left][right];
	if(s[right]==s[left]){
		return dp[left][right] = solve(left+1,right-1);
	}

	else{
		return dp[left][right] = min(solve(left+1,right)+1,solve(left,right-1)+1);
	}
}


ll cal(){
	reset(dp,-1);
	return solve(0,s.size()-1);
}



int main(){
    // input;
    // output;

    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        
        cin>>s;

        pcase(cn);
        cout<<cal()<<endl;
        


    }
}
