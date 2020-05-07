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


ll arr[200];
ll n,x,y,z;
ll dp[1000][1000];
ll sol(ll start,ll moves){
    if(start>=n) return 0;
    if(moves>=y) return 0;
    if(dp[start][moves]!=-1)  return dp[start][moves];
    ll sum = 0;
    ll aux = arr[start];
    ll j = start;
    ll i=0;
    int u=0;
    while(i<=x && j<n){
        if(arr[j]!=aux){
            i++;
            aux++;
        }
        else{
            j++;
            sum++;

        }
    }
  // cout<<arr[start]<<" "<<sum<<" "<<j<<endl;
     return dp[start][moves] = max(sum+sol(start+sum,moves+1),sol(start+1,moves));
     //Maximum  between if we brush this cordinate and if we dont brush this cordinate
     //If we brush this cordintate that means we have lost our one move so we have to increase it
     //If we dont brush this cordinate then we don't have to increase our move


}



int main(){
//input;
//output;
    ll cn=1;
    ll cs=1;
    cin>>cs;
    while(cs--){
        //n = total crodinate
        //x = width of the brush
        //y = how much move I have
        cin>>n>>x>>y;
        clr(arr);
        reset(dp,-1);
        for(ll i=0;i<n;i++){
            cin>>z>>arr[i];

        }
        //there is no need of x axis we need only y
        //because we have to brush on y cordinate
        sort(arr,arr+n);
        pcase(cn);
        cout<<sol(0,0)<<endl;


    }







}
