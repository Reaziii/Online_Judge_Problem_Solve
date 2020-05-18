 
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
ll cal();
int n,m;
int k;
string grid[100];
deque< pii > positions;

bool check(int pos, int number){
	return number>>pos & 1;
}

ll setb(int pos,int number){
	return 1<<pos | number;
}
void take_data(){
	cin>>n>>m;
	fri(n){
		cin>>grid[i];
	}

	cal();
}
ll distance(int x,int y){
	int a = fabs(positions[x].first-positions[y].first);
	int b = fabs(positions[x].second-positions[y].second);
	return max(a,b);
}


int dp[100000][30];
ll solve(int mask = 1, int before=0){
	if(dp[mask][before]!=-1) return dp[mask][before];
	auto &a = dp[mask][before];
	if(mask == k) return a = distance(before,0);


	ll ans = infi;

	for(int i = 0 ; i <positions.size();i++){
		if(!check(i,mask)){
			ans = min(solve(setb(i,mask),i)+ distance(before,i),ans);
		}
	}

	return a = ans;
}
ll cal(){
	positions.clear();
	reset(dp,-1);
	fri(n){
		frj(m){
			if(grid[i][j]=='x') positions.push_front({i,j});
			else if(grid[i][j]=='g') {
				positions.pb({i,j});
			}
		}
	}
	
	// for(auto &x : positions) cout<<x.first<<" "<<x.second<<endl;

	k = (1<<positions.size())-1;
	cout<<solve()<<endl;
}

int main(){
    // input;
    // output;
    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
    	pcase(cn);
        take_data();

    }
}
