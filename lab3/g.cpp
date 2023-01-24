#include <iostream>
#include <cmath>

using namespace std;

int find(int k, int n, int a[]){
    int hours = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % k == 0 && k <= a[i]){
            hours += a[i]/k;
        } 
        else{
            hours += (a[i]/k)+1;
        }
    }
    return hours;
}

int bs(int a[], int l, int r, int n, int h){
    int res = r;
    while(l <= r){
        int m = l + (r - l)/2;
        if(find(m, n, a) > h){
            l = m + 1;
        }
        else{
            r = m - 1;
            res = m;
        }
    }
    return res;
}

int main(){
    int n; cin >> n;
    int h; cin >> h;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << bs(a, 1, pow(10, 9), n,h);
    return 0; 
}