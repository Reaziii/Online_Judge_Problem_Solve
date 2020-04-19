#include<bits/stdc++.h>
#define scnf(x) scanf("%lld",&x)
#define pcase(x) printf("Case #%d: ",x++)
#define pn printf("\n")
#define For(e,f,i) for(int i=e;i<f;i++)
#define reset(x,e) memset(x,e,sizeof(x))
#define input freopen("input.txt","r",stdin)
#define output  freopen("output.txt","w",stdout);
using namespace std;
typedef int ll;


ll jsh=0;
ll csh=0;
bool is_j_free(int s,int e){
    if(jsh<=s)
    {
        jsh=e;
        return 1;

    }
    else return 0;

}


bool is_c_free(int s,int e){
    if(csh<=s){
        csh=e;
        return 1;

    }
    else return 0;

}





struct times{
    int start;
    int stop;
    int rnk;

};

bool comp(times x,times y){
    if(x.start<y.start)return true;
    else return false;


}

int main(){
    ll cs,cn=1;
    cin>>cs;
    while(cs--){
        jsh=0;
        csh=0;
        ll n;
        cin>>n;
        vector<times>times(n);

        for(ll i=0;i<n;i++){

            cin>>times[i].start;
            cin>>times[i].stop;
            times[i].rnk=i;
//            times[i].start/=60;
//            times[i].stop/=60;

        }

        sort(times.begin(),times.end(),comp);
//
//        for(int i=0;i<n;i++){
//            cout<<times[i].start<<" "<<times[i].stop;
//            cout<<endl;
//
//        }

        pcase(cn);
        bool f2=true;
        string s;

        for(int i=0;i<n;i++)s+=".";
        for(int i=0;i<n;i++){

            if(is_j_free(times[i].start,times[i].stop)){
                s[times[i].rnk]='C';

            }
            else {
                if(is_c_free(times[i].start,times[i].stop)){
                    s[times[i].rnk]='J';

                }
                else {
                    f2=false;

                }

            }

            //cout<<jsh<<" "<<csh<<endl;


        }






        //cout<<imp<<endl;
        if(f2)cout<<s<<endl;
        else cout<<"IMPOSSIBLE"<<endl;










    }




}
