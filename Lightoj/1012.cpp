#include<bits/stdc++.h>
#define sc(x) scanf("%lld",&x)
#define pcase(x) printf("Case %d: ",x++)
#define pn printf("\n")
#define For(e,f,i) for(int i=e;i<f;i++)
#define reset(x,e) memset(x,e,sizeof(x))
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout)
#define infi INT_MAX
#define max_value 3000
#define lola 2000
 
#define pii          pair<int,int>
#define pch          pair<char,char>
#define mgraph       map<int,vector<int> >
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
 
char graph[1000][1000];
pii position;
int n,k;
void take_data(){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>graph[i][j];
            if(graph[i][j]=='@') {
                position=make_pair(i,j);
 
 
            }
        }
    }
 
    for(int i=0;i<=k+1;i++){
        graph[i][0]='#';
        graph[i][n+1]='#';
 
 
    }
 
    for(int i=0;i<=n+1;i++){
        graph[0][i]='#';
        graph[k+1][i]='#';
 
 
    }
}
 
int vis[1000][1000];
void print(){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cout<<vis[i][j]<<" ";
 
        }pn;
 
    }
 
 
}
 
 
 
int bfs(){
    queue <pii> q;
    pii x;
    int total=0;
    q.push(position);
   
    reset(vis,0);
 
    while(!q.empty()){
        //print();
        x = q.front();
        int g = x.first;
        int h = x.second;
        q.pop();
 
        if(vis[g][h]==0){
            total++;
            vis[g][h]=1;
            if(graph[g][h-1]=='.' ) q.push(make_pair(g,h-1));
            if(graph[g][h+1]=='.')q.push(make_pair(g,h+1));
            if(graph[g+1][h]=='.')q.push(make_pair(g+1,h));
            if(graph[g-1][h]=='.')q.push(make_pair(g-1,h));
 
 
        }
 
 
    }
 
    return total;
 
 
 
}
 
 
 
 
 
int main(){
/*    input;
    output;*/
    int cs;
    int cn=1;
    cin>>cs;
    while(cs--){
        cin>>n>>k;
        take_data();
        pcase(cn);
        cout<<bfs();
        pn;
 
    }
 
 
 
}
