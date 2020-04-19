#include<bits/stdc++.h>
#define scnf(x) scanf("%lld",&x)
#define pcase(x) printf("Case #%lld: ",x++)
#define pn printf("\n")
#define For(e,f,i) for(int i=e;i<f;i++)
#define reset(x,e) memset(x,e,sizeof(x))
#define input freopen("input.txt","r",stdin)
#define output  freopen("output.txt","w",stdout);
using namespace std;
typedef long long int ll;

int main(){
//    input;
//    output;
    ll cs,cn=1;
    cin>>cs;

    while(cs--){
        ll lp=0;
        string s;
        cin>>s;
        string ans;
        for(ll i=0;i<s[0]-'0';i++){
            ans+='(';
            lp++;
        }


        ans+=s[0];


        for(ll i=1;i<s.size();i++){
            //cout<<ans<<" "<<lp<<endl;
            if(s[i]=='0'){
                for(ll i=0;i<lp;i++){
                    ans+=')';
                }
                ans+='0';
                lp=0;
            }
            else if(s[i]==s[i-1]){
                ans+=s[i];


            }
            else if(lp>s[i]-'0'){
                ll x=0;
                for(ll j=0;j<lp-(s[i]-'0');j++){
                    ans+=')';
                    x++;

                }
                lp-=x;
                ans+=s[i];

            }

            else if(lp<=s[i]-'0'){
                ll x=0;
                for(ll j=0;j<(s[i]-'0')-lp;j++){
                    ans+='(';
                    x++;

                }
                lp+=x;
                ans+=s[i];



            }







        }


        for(ll i=0;i<lp;i++){
            ans+=')';
        }





}
        pcase(cn);
        cout<<ans<<endl;



    }



}

