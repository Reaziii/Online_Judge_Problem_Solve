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
 
ll dp[1000][1000];
ll dp2[40][40][100];
string nibba,nibbi;
ll sol1(ll nibbasize ,ll nibbisize){
    if(nibbisize == -1 || nibbasize == -1) return 0;
    if(nibba[nibbasize] == nibbi[nibbisize]) {
        if(dp[nibbasize][nibbisize]==-1){
            dp[nibbasize][nibbisize]=1+sol1(nibbasize-1,nibbisize-1);
        }
        return dp[nibbasize][nibbisize];
    }
    if(dp[nibbasize][nibbisize]==-1){
        dp[nibbasize][nibbisize]=max(sol1(nibbasize-1,nibbisize),sol1(nibbasize,nibbisize-1));
    }
 
    return dp[nibbasize][nibbisize];
}
 
 
ll sol2(ll i, ll j, ll x, ll nibbasize, ll nibbisize){
    if(i==nibbasize && j==nibbisize && !x) return 1;
    else if(i==nibbasize && j==nibbisize) return 0;
 
    if(dp2[i][j][x]!=-1) return dp2[i][j][x];
    ll f;
    if(i==nibbasize) {
        f = sol2(i,j+1,x-1,nibbasize,nibbisize);
 
    }
 
    else if(j==nibbisize){
        f = sol2(i+1,j,x-1,nibbasize,nibbisize);
 
 
    }
 
    else if(nibba[i]==nibbi[j]){
        f = sol2(i+1,j+1,x-1,nibbasize,nibbisize);
 
    }
 
    else {
        f = sol2(i+1,j,x-1,nibbasize,nibbisize)+sol2(i,j+1,x-1,nibbasize,nibbisize);
 
    }
 
    return dp2[i][j][x]=f;
 
 
 
 
}
 
 
 
 
 
int main(){
    ll cn=1;
    ll cs;
    cin>>cs;
    while(cs--){
 
        reset(dp,-1);
        cin>>nibba>>nibbi;
        ll nibbasize=nibba.size();
        ll nibbisize=nibbi.size();
        ll x = (nibbasize+nibbisize)-sol1(nibbasize-1,nibbisize-1);
        pcase(cn);
        reset(dp2,-1);
        ll y = sol2(0,0,x,nibbasize,nibbisize);
        printf("%lld %lld",x,y);
        cout<<endl;
    }
}
