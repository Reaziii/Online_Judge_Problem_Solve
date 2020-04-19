#include<bits/stdc++.h>
#define sc(x)        scanf("%lld",&x)
#define pcase(x)     printf("Case %d: ",x++)
#define pn           printf("\n")
#define fr(f)        for(int i=0;i<f;i++)
#define reset(x,e)   memset(x,e,sizeof(x))
#define input        freopen("input.txt","r",stdin);
#define output       freopen("output.txt","w",stdout)
#define infi         INT_MAX
#define max_value    6000
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define pch          pair<char,char>
#define mgraph       map<int,vector<int> >
#define mp           make_pair
#define pb           push_back
#define clr(x)       memset(x,0,sizeof(x))
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
 
 
 //....................Start from here....................//
//.......................................................//
 
mgraph graph;
mgraph cost;
void take_data(){
    while(1){
        int x,y,z;
        cin>>x>>y>>z;
        if(z==0) break;
        x++;
        y++;
        graph[x].pb(y);
        graph[y].pb(x);
        cost[x].pb(z);
        cost[y].pb(z);
    }
}
class cmp{
public:
    bool operator()(pll a,pll b){
        return a.second>b.second;
    }
};
 
ll mst(ll  root,ll n){
    priority_queue <pll, vector<pll>,cmp> q;
    vector <ll> dis(n+10,infi);
    q.push(mp(root,0));
    ll sum=0;
    //first one is vertices
    //second one is distance between two vertices
    vector<ll> vis(n+10,0);
 
    dis[root]=0;
    vis[root]=root;
    vis[root]=0;
    while(!q.empty()){
        pll x = q.top();
        q.pop();
 
        ll v = x.first;
        ll d = x.second;
        //cout<<v<<endl;
 
        if(vis[v])continue;
        vis[v]=1;
        sum+=d;
        for(ll i=0;i<graph[v].size();i++){
            ll y = graph[v][i];
            if(!vis[y]){
                q.push(mp(y,cost[v][i]));
 
            }
 
 
        }
 
    }
    // printing the graph
    //ll sum =0;
 
    return sum;
 
 
 
}
 
 
 
 
 
 
class cmpl{
public:
    bool operator()(pll a,pll b){
        return a.second<b.second;
    }
};
 
ll mstl(ll  root,ll n){
    priority_queue <pll, vector<pll>,cmpl> q;
    vector <ll> dis(n+10,infi);
    q.push(mp(root,0));
    ll sum=0;
    //first one is vertices
    //second one is distance between two vertices
    vector<ll> vis(n+10,0);
 
    dis[root]=0;
    vis[root]=root;
    vis[root]=0;
    while(!q.empty()){
        pll x = q.top();
        q.pop();
 
        ll v = x.first;
        ll d = x.second;
        //cout<<v<<endl;
 
        if(vis[v])continue;
        vis[v]=1;
        sum+=d;
        for(ll i=0;i<graph[v].size();i++){
            ll y = graph[v][i];
            if(!vis[y]){
                q.push(mp(y,cost[v][i]));
 
            }
 
 
        }
 
    }
    // printing the graph
    //ll sum =0;
 
    return sum;
 
 
 
}
 
 
 
 
 
int main(){
//    input;
//    output;
 
    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        cost.clear();
        graph.clear();
        ll n,k;
        cin>>n;
        n++;
 
 
        take_data();
        pcase(cn);
 
        if((mst(1,n)+mstl(1,n))%2==0) cout<<(mst(1,n)+mstl(1,n))/2;
        else cout<<mst(1,n)+mstl(1,n)<<"/"<<2;
        pn;
    }
}
 
