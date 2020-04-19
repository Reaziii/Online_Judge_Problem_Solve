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
int cost[500][500];
int total = 0;
 
 
 
void take_data(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            total+=x;
            if(x!=0)graph[i].pb(j);
            if(x!=0)graph[j].pb(i);
            if(i==j) cost[i][j]=0;
            //else if(cost[i][j]==0) cost[i][j]=x;
            else if((cost[i][j]>x && x!=0) || cost[i][j]==0){
                cost[i][j]=x;
                cost[j][i]=x;
 
            }
 
 
        }
 
 
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
 
    vector<int>check;
    bool f=true;
    while(!q.empty()){
        pll x = q.top();
        q.pop();
 
        ll v = x.first;
        ll d = x.second;
        //cout<<v<<" "<<d<<endl;
        if(vis[v])continue;
        check.push_back(v);
        vis[v]=1;
        sum+=d;
        for(ll i=0;i<graph[v].size();i++){
            ll y = graph[v][i];
            if(!vis[y]){
               q.push(mp(y,cost[v][y]));
 
            }
 
 
        }
 
    }
    // printing the graph
    //ll sum =0;
    f=1;
    sort(check.begin(),check.end());
    for(int i=1;i<=n;i++){
        bool g = false;
        for(int j=0;j<check.size();j++){
            if(i==check[j]){
                g=true;
                break;
            }
        }
        if(!g){
            f=false;
            break;
 
        }
    }
 
 
    if(f) return sum;
    else return 0;
 
 
 
}
 
 
 
 
int main(){
//    input;
//    output;
 
    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        clr(cost);
        graph.clear();
        total=0;
 
 
 
        ll n,k;
        cin>>n;
 
 
 
 
 
        take_data(n);
        pcase(cn);
        if(n==1){
            cout<<total-0;pn;
            continue;
 
        }
        ll x = mst(1,n);
 
        if(!x) cout<<"-1";
        else cout<<total-x;
        pn;
    }
}
