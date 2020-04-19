#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int cases,ans;
    scanf("%d",&cases);
    int n,m;
    for(int i=1;i<=cases;i++){
        scanf("%d %d",&n,&m);
        n=(n*4)+10+9+(abs(m-n)*4);
        printf("Case %d: %d\n",i,n);
    }
 
 
 
    return 0;
}
