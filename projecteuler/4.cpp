#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool sol(long ans){

    ll result = 0;

    ll memory = ans;

    while( ans!= 0 ){

        ll x = ans%10;

        result = result*10+x;

        ans/=10;

    }

    if(memory==result) return true;

    return false;

}


int main(){
    long x = 1000;

    long y = 1000;

    long result = x * y;

    while(1){

        bool f = false;

        result--;

        //I m checking if result is palidrom or not
        //If it is not palindrom then I don't need this number

        if( !sol(result) )continue;

        //If the number is palindrom then I m checking if the number = x * y where x and y both are 3 digit number

        for( int i = 999 ; i >= 100 ; i-- ){

            x = result / i;

            if( x*i == result && x <= 999 && x >= 100){
                f = true;
                break;
            }
        }
        if( f ) break;
    }
    cout<<result<<endl;

}




