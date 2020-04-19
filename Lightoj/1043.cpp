#include<bits/stdc++.h>
using namespace std;
#define scanf(x) scanf("%lld",&x)
#define pcase(x) printf("Case %d: ",x++)
#define For(e,f,i) for(int i=e;i<f;i++)
#define reset(x,e) memset(x,e,sizeof(x))
typedef long long int ll;
double a,b,c;
double fr(double ad){
    double x,y,z,r;
    x=ad;
    y=b*x/a;
    z=c*x/a;
    double s1=(a+b+c)/2;
    double s2=(x+y+z)/2;
 
    double ade=sqrt(s2*(s2-x)*(s2-y)*(s2-z));
    double abc=sqrt(s1*(s1-a)*(s1-b)*(s1-c));
    double bdec=abc-ade;
 
 
 
    return ade/bdec;
 
 
 
 
 
}
double value(double ratioo){
 
    double r=-1;
    double low=0;
    double high=a,mid=(high+low)*0.5;
    int i=0;
    while(high>low+0.00000001){
        mid = (low+high)/2.0;
        if(fr(mid)>ratioo){
            high=mid;
        }
        else low=mid;
        i++;
 
    }
    return mid;
 
 
 
 
 
}
 
int main(){
//    freopen("input.txt","r",stdin);
    ll cs,cn=1;
    scanf(cs);
    while(cs--){
        double ratioo;
        cin>>a>>b>>c>>ratioo;
        pcase(cn);
        printf("%.8lf\n",value(ratioo));
 
 
 
 
 
    }
 
 
 
}
 
