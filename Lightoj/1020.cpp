 
/*
    Bismillahir Rahmanir Raheem
    Think Twice Code Once
*/
#include<bits/stdc++.h>
#define sc(x)        scanf("%lld",&x)
#define pcase(x)     printf("Case %d: ",x++)
#define pn           printf("\n")
#define fri(f)       for(int i=0;i<f;i++)
#define frj(f)       for(int j=0;j<f;j++)
#define reset(x,e)   memset(x,e,sizeof(x))
#define all(x)       x.begin(),x.end()
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


/*
	alice : 1 1 1
			A A B (A winner)

			1 1
			A B   (A winner)

			1 	  (B winner)
	bob   : 1 1 1
			B B A
			B A A (A winner)

			1 1
			B B   (B winner)

			1
			B     (B winner)
*/


void solve(){
	int n;
	string name;
	cin>>n>>name;
	n%=3;
	if(name=="Alice"){
		if(n==2 or n==0) cout<<"Alice";
		else cout<<"Bob";
	}
	else{
		if(n==2 or n==1) cout<<"Bob";
		else cout<<"Alice";
	}
}




int main(){
    // input;
    // output;

    int cs=1;
    int cn=1;
    cin>>cs;
    while(cs--){
        pcase(cn);
        solve();
        pn;
        


    }
}
