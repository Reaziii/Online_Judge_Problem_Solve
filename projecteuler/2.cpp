#include<bits/stdc++.h>
using namespace std;

int main(){
    long x=1;
    long y =2;

    long i = 1;
    long  result = 0;
    while(x<4000000){
        if(x%2==0) {
            result += x;

        }

        y = x + y;
        x = y - x;


    }
    cout<<result<<endl;


}

