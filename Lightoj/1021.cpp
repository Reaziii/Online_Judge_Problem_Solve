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
const int MAX = 1e5+10;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


 //.................___Start from here___.................//
//.................._____________________................//

bool check(int mask,int pos){
    if(1<<pos & mask) return 1;
    else return 0;


}
ll setbit(ll mask,ll pos){
    mask = (1<<pos)|mask;
    return mask;

}


int total = 0;
ll n,base,k;
int nmbr[100];
ll dp[MAX][22];

ll sol(ll mask, ll rem){
    //cout<<rem<<endl;

    if(mask == n && rem ==  0) return rem = 1;

    else if(mask == n) return 0;

    if( dp[mask][rem] != -1 ) return dp[mask][rem];

    ll ans = 0;

    fri( total ){
        if( check( mask,i ) ) continue;
        ans += sol( setbit(mask,i) , (rem*base + (nmbr[i]))%k );
    }
    
    return dp[mask][rem] = ans;

}



int main(){
//input;
//output;
    int cn=1;
    int cs;
    cin>>cs;
    while(cs--){
        cin>>base>>k;
        string st;
        cin>>st;
        reset(dp,-1);
        clr(nmbr);
        string pk;
        total = st.size();
        fri(st.size()){
            if(st[i]>='0' && st[i]<='9') {
                nmbr[i]=st[i]-'0';
            }

            else{
                nmbr[i]=(st[i]-'A')+10;


            }



        }
        n = (1<<total)-1;
        pcase(cn);
        cout<<sol(0,0);
        pn;
    }



}

