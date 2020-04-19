nclude<bits/stdc++.h>
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
vector<int> indegree(1000000,0);
void take_data(int k){
    fr(k){
        int x,y;
        cin>>x>>y;
        indegree[y]++;
        graph[x].pb(y);
 
    }
 
 
 
}
 
bool vis[1000000];
void bfs(int root){
    queue<int> q;
 
    int x;
    q.push(root);
    int z = root;
    bool f = false;
    while(!q.empty()){
 
        int x = q.front();
        q.pop();
        if(!vis[x]){
            vis[x]=true;
            //cout<<x<<endl;
 
            fr(graph[x].size()){
                int y = graph[x][i];
                if(!vis[y]){
                    q.push(y);
                }
            }
        }
    }
 
    if(!f)vis[z]=false;
 
 
}
 
 
int main(){
   //  input;
   // output;
 
    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        int n,k;
        graph.clear();
        indegree.clear();
        cin>>n>>k;
        for(int i=0;i<=n+10;i++){
            vis[i]=false;
            indegree[i]=0;
        }
        take_data(k);
        int total=0;
        pcase(cn);
 
        if(k==0){
            cout<<n<<endl;
            continue;
        }
 
        //cout<<" "<<indegree[1]<<endl;
       
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
             //   cout<<"ii "<<i<<endl;
                bfs(i);
 
            }
 
 
        }
        for(int i=1;i<=n;i++){
            if(!vis[i] && indegree[i]!=0){
               bfs(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                total++;
                //cout<<i<<endl;
            }
        }
       // cout<<n<<" "<<k<<endl;
        cout<<total;
        pn;
        graph.clear();
        clr(vis);
        //indegree.clear();
 
    }
}
 
