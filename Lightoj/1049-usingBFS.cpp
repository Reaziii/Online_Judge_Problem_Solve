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
 
mgraph graph1;
mgraph graph2;
int cost[1000][1000];
void take_data(int k){
    clr(cost);
    fri(k){
        int x,y,z;
        cin>>x>>y>>z;
        if(cost[x][y]==0)graph1[x].pb(y);
        if(cost[x][y]==0)graph2[y].pb(x);
        //graph2[x].pb(y);
        if(cost[x][y]==0 || cost[x][y]>z){
            cost[x][y]=z;
            cost[y][x]=z;
 
        }
 
        //cost[y].pb(z);
 
    }
}
 
void cleareverything(){
    graph1.clear();
    graph2.clear();
    clr(cost);
 
 
}
 
 
 
int  bfs(int root){
    //cout<<"bfs";
    queue <int> q;
    int x;
    bool vis[100000]={0};
    q.push(root);
 
    int cost2=0;
    int cost1=0;
    while(!q.empty()){
        int f = x;
        x = q.front();
        q.pop();
        if(x==root && vis[x]==1) break;
 
 
 
        if(!vis[x]){
            vis[x]=1;
 
            if(!graph1[x].empty()){
            int y=0;
                for(int i=0;i<graph1[x].size();i++){
                       y = graph1[x][i];
                       graph1[x].erase(graph1[x].begin()+i);
//                       cout<<y<<" "<<vis[y];pn;
                    if(!vis[y]){
                        q.push(y);
                        break;
 
                    }
                }
                cost1+=cost[x][y];
 
                fri(graph2[y].size()){
                    if(graph2[y][i]==x)graph2[y].erase(graph2[y].begin()+i);
 
                }
 
 
            }
 
            else if(!graph2[x].empty()){
                int y;
                fri(graph2[x].size()){
                    y = graph2[x][i];
                    if(!vis[y]){
                        q.push(y);
                        break;
 
 
 
                    }
                }
                fri(graph1[y].size()){
                    if(graph1[y][i]==x) graph1[y].erase(graph1[y].begin()+i);
 
                }
                cost2+=cost[y][x];
 
            }
 
 
 
 
        }
 
    //    cout<<"cost : "<<cost1<<" "<<cost2<<endl;
 
 
    }
 
    return min(cost1,cost2);
 
}
 
 
 
 
 
 
 
int main(){
    //input;
    //output;
 
    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        cleareverything();
        int n,k;
        cin>>k;
        take_data(k);
        pcase(cn);
        //pn;
        cout<<bfs(1);
        pn;
    }
}
 
