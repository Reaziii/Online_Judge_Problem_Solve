#include<bits/stdc++.h>
#define sc(x) scanf("%lld",&x)
#define pcase(x) printf("Case %d:",x++)
#define pn printf("\n")
#define For(e,f,i) for(int i=e;i<f;i++)
#define reset(x,e) memset(x,e,sizeof(x))
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
map<int,vector<int> > graph;
int matrix[1000][1000];
int n,k;
int vis[1000];
 
 
void take_data(){
for(int i=0;i<k;i++){
    int x,y,z;
    cin>>x>>y>>z;
    if(matrix[x][y]==0)graph[x].push_back(y);
    if(matrix[x][y]==0)graph[y].push_back(x);
 
    if(matrix[x][y]>z || matrix[x][y]==0) {
    matrix[x][y]=z;
    matrix[y][x]=z;
    }
}
 
 
}
 
void printmatrix()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
 
        }
        pn;pn;
 
    }
 
 
 
}
 
 
void find_parent(int x,int y){
    for(int i=0;i<graph[y].size();i++){
        if(graph[y][i]==x) {
            graph[y].erase(graph[y].begin()+i);
 
        }
    }
 
}
void bfs(int t){
    queue<int>q;
    q.push(t);
    int parent[1000];
    vis[t]=0;
    parent[t]=t;
    int x;
    int y=0;
    int mini;
    int temp;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++){
            y= graph[x][i];
 
            temp=max(vis[x],matrix[y][x]);
 
            if(temp<vis[y]){
                q.push(y);
                vis[y]=temp;
 
            }
 
        }
 
    }

 
}
 
int main(){
//    input;
//    output;
    int cs;
    int cn=1;
 
    cin>>cs;
    while(cs--){
        reset(matrix,0);
 
        graph.clear();
        cin>>n>>k;
        take_data();
        int t;
        cin>>t;
        //printmatrix();
        for(int i=0;i<n;i++)vis[i]=1000000;
        bfs(t);
        pcase(cn);
        pn;
 
        for(int i=0;i<n;i++){
            //cout<<vis[i]<<" ";
            if(i==t) cout<<0;
            else if(vis[i]==1000000)cout<<"Impossible";
            else if(vis[i]) cout<<vis[i];
            pn;
 
        }
 
    }
}
