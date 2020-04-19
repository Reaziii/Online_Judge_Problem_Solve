#include<bits/stdc++.h>
#define scnf(x) scanf("%lld",&x)
#define pcase(x) printf("Case #%d: ",x++)
#define pn printf("\n")
#define For(e,f,i) for(int i=e;i<f;i++)
#define reset(x,e) memset(x,e,sizeof(x))
#define input freopen("input.txt","r",stdin)
#define output  freopen("output.txt","w",stdout);
using namespace std;
typedef long long int ll;
ll arr[100+20];
ll arr2[100+20][100+20];
bool f,f2[100+20]={false};
int main(){
//    input;
//    output;
    ll cs,cn=1;
    cin>>cs;
    while(cs--){
        ll rc;
        cin>>rc;
        ll d=0,c=0,t=0,r=0,x;
        pcase(cn);
        reset(arr2,0);
        reset(arr,0);
        reset(f2,0);
        for(ll i=0;i<rc;i++){
            reset(arr,0);

            bool f=false;
            for(ll j=0;j<rc;j++){
                //ll x;
                cin>>x;
                if(i==j)d+=x;
                arr[x]++;
                if(arr[x]==2 && !f){
                    r++;
                    f=true;

                }

                arr2[j][x]++;
                //cout<<arr2[j][x]<<" ";
                if(arr2[j][x]==2 && !f2[j]){
                    c++;
                    //cout<<c<<endl;
                    f2[j]=true;

                }


            }




        }


        cout<<d<<" "<<r<<" "<<c;
        pn;




    }




}

