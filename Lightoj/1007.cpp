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
#define max_value    5000000+10
#define pii          pair<int,int>
#define pch          pair<char,char>
#define pll          pair<ll,ll>
#define mgraph       map<int,vector<int> >
#define mp           make_pair
#define pb           push_back
#define clr(x)       memset(x,0,sizeof(x))

using namespace std;
typedef long long int ull;
typedef unsigned long long int ll;


 //.................___Start from here___.................//
//.................._____________________................//



ll phi[max_value];
void PHI(){


    for(ll i=0;i<=max_value;i++){
        phi[i]=i;
    }
    for(ll i=2;i<=max_value;i++){
        if(phi[i]==i){
            for(ll j=i;j<=max_value;j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }



}


void calculatesum(){
phi[1]=0;
    for(ll i=2;i<=max_value;i++){
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];

    }


}




int main(){
    input;
    output;
    PHI();
    calculatesum();
    ll cs;
    ll cn=1;
    cin>>cs;
    while(cs--){
        ll n,k;
        cin>>n>>k;
        pcase(cn);
        cout<<phi[k]-phi[n-1];
        pn;





    }
}







