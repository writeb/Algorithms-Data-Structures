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

int main(){
    int n;
    cin>>n;
    if (is_prime(n)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}