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
//    input;
//    output;
 
    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        int x,y,z;
        int n;
        cin>>n;
 
        int right[10000],left[10000];
        clr(right);
        clr(left);
        int a = n;
        int cost1=0,cost2=0;
        while(n--){
            cin>>x>>y>>z;
            if(!right[x] && !left[y]){
                cost1+=z;
                right[x]++;
                left[y]++;
 
 
            }
            else {
                right[y]++;
                left[x]++;
                cost2+=z;
            }
 
 
        }
        pcase(cn);
        cout<<min(cost2,cost1)<<endl;
 
 
 
    }
}
 
 
