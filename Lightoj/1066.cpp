/*
  Bismillahir Rahmanir Raheem
  
  
  **********Used BFS and dijkstra********
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

char graph[100][100];
pii position;
int si;
int total_char;
void take_data(int n){
    total_char=0;
    fri(n+2){
        frj(n+2){
            if(i==0 || j==0 || i==n+1 || j==n+1) graph[i][j]='#';
            else cin>>graph[i][j];
            if(graph[i][j]>='A' && graph[i][j]<='Z')total_char++;

            if(graph[i][j]=='A') position=make_pair(i,j);
        }
    }
    si=n;
}


void print(){
pn;
    fri(si+2){
        frj(si+2)cout<<graph[i][j];
        pn;
    }

}

int dijkstra(pii pos1,pii pos2){
    priority_queue <pii> q;
    q.push(pos1);
    int dist[100][100];
    clr(dist);

    pii x;


    while(!q.empty()){
        x=q.top();
        q.pop();
        int i=x.first;
        int j=x.second;

        if(graph[i][j+1]=='.'){
            if(dist[i][j+1]==0 || dist[i][j+1]>dist[i][j]+1){
                dist[i][j+1]=dist[i][j]+1;
                q.push(mp(i,j+1));

            }


        }
        if(graph[i][j-1]=='.'){
            if(dist[i][j-1]==0 || dist[i][j-1]>dist[i][j]+1){
                dist[i][j-1]=dist[i][j]+1;
                q.push(mp(i,j-1));

            }


        }
        if(graph[i-1][j]=='.'){
            if(dist[i-1][j]==0 || dist[i-1][j]>dist[i][j]+1){
                dist[i-1][j]=dist[i][j]+1;
                q.push(mp(i-1,j));

            }


        }
        if(graph[i+1][j]=='.'){
            if(dist[i+1][j]==0 || dist[i+1][j]>dist[i][j]+1){
                dist[i+1][j]=dist[i][j]+1;
                q.push(mp(i+1,j));

            }


        }









    }

    return dist[pos2.first][pos2.second];




}


string subt="BCDEFGHIJKLMNOPQRSTUVWXYZ";
void bfs(){
    queue<pii> q;
    q.push(position);
    pii x;
    graph[position.first][position.second]='.';
    int total=0;
    int vis[100][100];
    clr(vis);

    total_char--;


    while(!q.empty()){
        x = q.front();
        q.pop();
        int i=x.first;
        int j=x.second;

        if(vis[x.first][x.second]==0){
            vis[x.first][x.second]=1;


            if(graph[i][j+1]=='.') q.push(mp(i,j+1));
            if(graph[i][j-1]=='.') q.push(mp(i,j-1));
            if(graph[i+1][j]=='.') q.push(mp(i+1,j));
            if(graph[i-1][j]=='.') q.push(mp(i-1,j));

            if(graph[i][j+1]==subt[0]){
                total_char--;
                subt.erase(subt.begin());
                clr(vis);
                queue <pii> x;
                swap(x,q);
                q.push(mp(i,j+1));
                graph[i][j+1]='.';

                total+=dijkstra(position,mp(i,j+1));
                position=mp(i,j+1);

            }
            if(graph[i][j-1]==subt[0]){
                total_char--;
                subt.erase(subt.begin());
                clr(vis);
                queue <pii> x;
                swap(x,q);
                q.push(mp(i,j-1));
                graph[i][j-1]='.';

                total+=dijkstra(position,mp(i,j-1));
                position=mp(i,j-1);

            }if(graph[i+1][j]==subt[0]){
                total_char--;
                subt.erase(subt.begin());
                clr(vis);
                queue <pii> x;
                swap(x,q);
                q.push(mp(i+1,j));
                graph[i+1][j]='.';
                total+=dijkstra(position,mp(i+1,j));
                position=mp(i+1,j);


            }if(graph[i-1][j]==subt[0]){
                total_char--;
                subt.erase(subt.begin());
                clr(vis);
                queue <pii> x;
                swap(x,q);
                q.push(mp(i-1,j));
                graph[i-1][j]='.';
                total+=dijkstra(position,mp(i-1,j));
                position=mp(i-1,j);

            }

        }


    }


    if(total_char==0)cout<<total<<endl;
    else cout<<"Impossible"<<endl;





}





int main(){
    input;
    output;

    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        //start form here//
        subt="";
        subt="BCDEFGHIJKLMNOPQRSTUVWXYZ";
        int n;
        cin>>n;
        take_data(n);
        pcase(cn);
        bfs();




    }
}






