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

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


 //.................___Start from here___.................//
//.................._____________________................//

map<string,int> id;
mgraph graph;
mgraph cost;
int total_road=0;
//I have to take all data
void take_data(int n){
    string s1,s2;
    ll x;
    ll i=1;
    graph.clear();
    cost.clear();
    id.clear();
    while(n--){
        char ch;
        cin>>s1>>s2>>x;
        //Giving unique id to the places
        if(!id[s1])id[s1]=i++;
        if(!id[s2])id[s2]=i++;
        graph[id[s1]].push_back(id[s2]);
        graph[id[s2]].push_back(id[s1]);
        cost[id[s1]].pb(x);
        cost[id[s2]].pb(x);

    }
    total_road=i-1;
}

//Basic comparing class

class cmp{
public:
    bool operator()(pll a,pll b){
        return a.second>b.second;
    }
};

ll mst(ll n){
    n=total_road;
    int root = 1;
    priority_queue <pll, vector<pll>,cmp> q;
    vector <ll> dis(n+10,infi);
    q.push(mp(root,0));
    ll sum=0;
    vector<ll> vis(n+10,0);
    vector<ll> parent(n+10,0);
    
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
                parent[y]=v;
                q.push(mp(y,cost[v][i]));

            }


        }

    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            return -1;
        }

    }

    return sum;



}






int main(){
/*    input;
    output;*/
    int cn=1,cs;
    cin>>cs;
    while(cs--){
        int n;cin>>n;
        take_data(n);
        pcase(cn);

        int mh = mst(n);
        if(mh==-1)cout<<"Impossible";
        else cout<<mh;
        pn;
        

    }

}
