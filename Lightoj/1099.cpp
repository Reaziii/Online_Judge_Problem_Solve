
/*       _____  ______           ______
        |  __ \|  ____|   /\    |___  /
        | |__) | |__     /  \      / /
        |  _  /|  __|   / /\ \    / /  
        | | \ \| |____ / ____ \  / /__
        |_|  \_\______/_/    \_\/_____|
*/
 
 
#include<bits/stdc++.h>
#define sc(x) scanf("%lld",&x)
#define pcase(x) printf("Case %d: ",x++)
#define pn printf("\n")
#define For(e,f,i) for(int i=e;i<f;i++)
#define reset(x,e) memset(x,e,sizeof(x))
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout)
#define infi        INT_MAX
#define max_value    6000
#define pii          pair<int,int>
#define pch          pair<char,char>
#define mgraph       map<int,vector<int> >
#define mp           make_pair
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
 
 
 //..............Code start from here//...........//
//...............................................//
 
map<int, vector<int>>cost;
mgraph graph;
int distances[max_value];
int distances2[max_value];
 
//taking graph data
 
void take_data(int k){
    for(int i=0;i<k;i++){
        int x,y,z;
        cin>>x>>y>>z;
        graph[x].push_back(y);
        graph[y].push_back(x);
        cost[x].push_back(z);
        cost[y].push_back(z);
       
     
    }
 
 
}
int m = infi;
 
void dj(){
    distances[1]=0;
    distances2[1]=infi;
    priority_queue <pii> q;
    q.push(make_pair(1,0));
    int x;
    pii f;
 
    while(!q.empty()){
        f = q.top();
        x = f.first;
        int l = f.second;
        q.pop();
            for(int i=0;i<graph[x].size();i++){
 
                int y=graph[x][i];
                if(distances[y]>l+cost[x][i]){
                    m = min(m,cost[x][i]);
                    distances2[y]=distances[y];
                    distances[y]=cost[x][i]+l;
                    q.push(mp(y,distances[y]));
 
 
                }
                else if(distances2[y]>cost[x][i]+l && distances[y]<l+cost[x][i]+l){
                    distances2[y]=cost[x][i]+l;
                    q.push(mp(y,distances2[y]));
                }
               // cout<<x<<" "<<y<<" "<<distances[y]<<" "<<distances2[y]<<endl;
 
            }
 
 
    }
 
}
 
 
 
int main(){
/*    input;
    output;
*/
    int cs;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        int n,k;
        cin>>n>>k;
        graph.clear();
        for(int i=1;i<=n;i++){
            distances[i]=infi;
            distances2[i]=infi;
 
        }
        m=infi;
        cost.clear();
 
       
        take_data(k);
/*        for(int i=1;i<=n;i++){
            for(int j=0;j<cost[i].size();j++){
                cout<<cost[i][j]<<" ";
 
            }
            pn;
        }
 
*/      
        pcase(cn);//pn;
 
        dj();
        if(distances[n]==distances2[n])m*=2;
        else m = 0;
        cout<<distances2[n]+m<<endl;
 
 
 
    }
}
