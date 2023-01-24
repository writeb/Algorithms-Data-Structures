#include <iostream>
using namespace std;

bool is_prime(int num){
    if (num<2) return false;
    for (int i=2; i<num; i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

int nth_prime(int n){
    int cnt = 0, prime_cnt = 0;
    while (n){
        if (is_prime(cnt)){
            prime_cnt++;
        }
        if (prime_cnt == n){
            break;
        }
        cnt++;
    } 
    return cnt;
}

int main(){
    int n;
    cin>>n;
    cout<<nth_prime(n);


    return 0;
}