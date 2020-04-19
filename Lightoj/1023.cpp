/*
  Bismillahir Rahmanir Raheem
 
*/
#include<bits/stdc++.h>
#define sc(x)        scanf("%lld",&x)
#define pcase(x)     printf("Case %d:",x++)
#define pn           printf("\n")
#define fri(f)       for(int i=0;i<f;i++)
#define frj(f)       for(int j=0;j<f;j++)
#define reset(x,e)   memset(x,e,sizeof(x))
#define all(x)     x.begin(),x.end()
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
 
 
 
 
 
 
 
int main(){
    // input;
    // output;
 
    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        pcase(cn);
        pn;
 
        string s= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
        int n,m;
        cin>>n>>m;
        s.erase(s.begin()+n,s.end());
        int x=infi;
        if(n==3) x = 6;
        if(n==4) x = 24;
        if(n==1) x = 1;
        if(n==2) x = 2;
 
        m = min(x,m);
 
        fri(m){
            cout<<s<<endl;
            next_permutation(s.begin(),s.end());
        }
 
 
 
 
 
       
 
    }
}
