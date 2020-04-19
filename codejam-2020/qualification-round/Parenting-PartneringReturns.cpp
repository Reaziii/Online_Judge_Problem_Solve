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
    else {
        for(int i=1;i<=n;i++){
            if(isafe(row,col,i,n)==true){
                matrix[row][col]=i;
                if(col==n-1 && row==n-1){
                    int sum=0;
                    for(int f=0;f<n;f++){
                        sum+=matrix[f][f];
                    }
                    if(sum==k) {
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                final_matrix[i][j]=matrix[i][j];
                            }
                        }

                        return 0;


                    }

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
        reset(matrix,0);
        matrix[0][0]=i;
        int g = solve(n,0,1,k);
        if(g==0) return 0;

    }



}



int main(){
//    input;
//    output;


    int cs;
    int cn=1;
    cin>>cs;
    while(cs--){
        ll n;
        cin>>n>>k;
        pcase(cn);

        if(k==n+1 || k==n*n-1){
            cout<<"IMPOSSIBLE";
            pn;
            continue;

        }



        reset(matrix,0);
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

