#include<bits/stdc++.h>
#define scnf(x) scanf("%lld",&x)
#define pcase(x) printf("Case #%d: ",x++)
#define pn printf("\n")
#define For(e,f,i) for(int i=e;i<f;i++)
#define reset(x,e) memset(x,e,sizeof(x))
#define input freopen("input.txt","r",stdin);
#define output freopen("output2.txt","w",stdout)
using namespace std;
typedef long long int ll;

int matrix[100][100];



int diag[100];



void diag_(ll n,ll k){
    if(k%n==0){
        for(int i=0;i<n;i++) diag[i]=k/n;
    }

    else if(k%n==1) {
        for(int i=0;i<n;i++)diag[i]=k/n;
        diag[n-1]=(k/n)+(k%n);
        diag[n-2]+=1;
        diag[0]-=1;

    }

    else{
        for(int i=0;i<n;i++) diag[i]=k/n;
        for(int i=0;i<k%n;i++) diag[i]++;
    }
    int h=0;
    for(int i=1;i<n;i++){
        if(diag[0]!=diag[i]) h++;
    }

    if(h==1){
        diag[0]-=1;
        diag[1]+=1;

    }


}


void reset_m(int n){
    for(int i=0;i<n;i++){
        matrix[i][i]=diag[i];
    }


}













int final_matrix[100][100];
int k=19;
void printm(ll n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<final_matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}
bool isafe(int x,int y,int z,int n){
    for(int i=0;i<n;i++){
        if(matrix[x][i]==z) return false;

    }
    for(int i=0;i<n;i++){
        if(matrix[i][y]==z) return false;

    }

    return true;

}



int solve(ll n,ll row, ll col,ll k){
    if(col==n){
        col=0;
        row=row+1;
        solve(n,row,col,k);

    }
    else if(col==row){
        solve(n,row,col+1,k);

    }
    else {
        for(int i=1;i<=n;i++){
            if(isafe(row,col,i,n)==true){
                matrix[row][col]=i;
                if(row==n-1 && col==n-2){
                    for(int v=0;v<n;v++){
                        for(int s=0;s<n;s++){
                            final_matrix[v][s]=matrix[v][s];

                        }
                    }

                    return 0;

                }
                int cd=solve(n,row,col+1,k);
                if(cd==0) return 0;


            }
            matrix[row][col]=0;

        }



    }

    return 1;


}

int mainsolve(ll n,ll k){

    for(int i=1;i<=n;i++){
        if(isafe(0,1,i,n)){
        matrix[0][1]=i;
        int g = solve(n,0,2,k);
        if(g==0) return 0;
        }

    }



}



int main(){
//   input;
//    output;


    int cs;
    int cn=1;
    cin>>cs;
    while(cs--){
        ll n;
        cin>>n>>k;
//        pcase(cn);
//        diag_(n,k);
//        for(int i=0;i<n;i++) cout<<diag[i]<< " ";
//        pn;
        pcase(cn);
        diag_(n,k);
        if(k==n+1 || k==n*n-1 || diag[0]==0){
            cout<<"IMPOSSIBLE";
            pn;
            continue;

        }
//
//

//        reset(matrix,0);
//
//
//        reset_m(n);
//        mainsolve(n,k);
//        printm(n);
//        pn;







        reset(matrix,0);
        reset_m(n);
        reset(final_matrix,0);

        mainsolve(n,k);
        if(final_matrix[0][0]==0){
            cout<<"IMPOSSIBLE";
            pn;
            continue;
        }
        cout<<"POSSIBLE";
        pn;
        printm(n);

    }




}

