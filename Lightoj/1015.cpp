#include <bits/stdc++.h>
#include<string>
#include <iostream>
using namespace std;

int main()
{
    int n,k,s,sum;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum=0;
        scanf("%d",&k);
        while(k--){
            scanf("%d",&s);
            //if(s<0) s=0;
            if(s>0)sum+=s;
        }
        if(sum>0)printf("Case %d: %d\n",i,sum);

    }
    return 0;
}
