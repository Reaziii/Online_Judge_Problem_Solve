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

//mgraph graph1;
//mgraph graph2;
//int cost[1000][1000];
//void take_data(int k){
//    clr(cost);
//    fri(k){
//        int x,y,z;
//        cin>>x>>y>>z;
//        graph1[x].pb(y);
//        graph2[y].pb(x);
//        //graph2[x].pb(y);
//        cost[x][y]=z;
//        cost[y][x]=z;
//        //cost[y].pb(z);
//
//    }
//}
//
//void cleareverything(){
//    graph1.clear();
//    graph2.clear();
//    clr(cost);
//
//
//}
//
//
//
//int bfs(int root,int dir){
//
//
//
//
//
//
//
//
//
//
//
//
//}






int main(){
    input;
    output;

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






