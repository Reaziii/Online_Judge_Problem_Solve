#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;

    long long int m,k,y,i;
    for(i=1;i<=n;i++){
        cin>>m;
        k=sqrt(m);
        if(k*k==m && m%2!=0){
            cout<<"Case "<<i <<": "<<1 <<" "<<k<<endl;
            continue;
        }
        else if(k*k==m && m%2==0){
            cout<<"Case "<<i <<": "<<k <<" "<<1<<endl;
            continue;
        }
        else if(k*k==m-1 && m%2==0){
            cout<<"Case "<<i <<": "<<1 <<" "<<k+1<<endl;
            continue;
        }
        else if(k*k==m-1 && m%2!=0){
            cout<<"Case "<<i <<": "<<k+1 <<" "<<1<<endl;
            continue;
        }
        else{
            k=k+1;
            if((k*k)>m && k%2!=0){
                y=(k-1)*(k-1)+k;
                if(m>=y && m<k*k){
                    cout<<"Case "<<i <<": "<<abs(m-(k*k))+1<<" "<<k<<endl;
                    continue;

                }

                else{
                    k--;
                    cout<<"Case "<<i <<": "<<k+1<<" "<<m-(k*k)<<endl;
                    continue;
                }
                k--;
            }

            else{
                k--;
                if((k*k)<m && k%2!=0){
                    y=(k+1)*(k+1)-k;
                    if(m<=y){
                        cout<<"Case "<<i <<": "<<abs(m-(k*k))<<" "<<k+1<<endl;
                        continue;
                    }
                    else if(((k+1)*(k+1))>m && k%2!=0){
                        y=(k+1)*(k+1)-k;
                        k++;
                        cout<<"Case "<<i <<": "<<k<<" "<<((k*k)-m)+1<<endl;
                        continue;
                    }
                }

                //cout<<endl<<k;


            }




        }
    }



    return 0;

}
