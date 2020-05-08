#include<bits/stdc++.h>
using namespace std;


int main(){
    long x = 600851475143;
    long i = 2;
    while(x!=1){
        if(x%i!=0){
            i++;
        }
        else{
            x/=i;
        }
    }
    cout<<i<<endl;

}
