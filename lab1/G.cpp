#include <iostream>
using namespace std;
void superprime(int n){
    bool prime1[10001];
    for(int i=0;i<=10000;i++){
        prime1[i]=true;
    }
    for(int p=2;p*p<=10000;p++){
        if(prime1[p]==true){
            for(int i=p*p;i<=10000;i+=p){
                prime1[i]=false;
            }
        }
    }
    int t =1,a[10000];
    for(int i=2;i<=10000;i++){
        if(prime1[i]==true){
            a[t]=i;
            t++;
        }
    }
    int b[100];
    t=1;
    for(int i=2;i<=10000;i++){
        if(prime1[i]==true){
            b[t]=a[i];
            t++;
        }
    }
    cout<<b[n];
}
int main(){
int N;
cin>>N;
superprime(N);
}