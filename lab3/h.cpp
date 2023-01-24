#include <iostream>

using namespace std;

int bs(int p[], int x, int l, int r){
    int res = r + 1;
    while(l <= r){
        int m = l + (r-l)/2;
        if(x <= p[m]){
            r = m - 1;
            res = m;
        }
        else{
            l = m+1;
        }
    }
    return res + 1;
}

int main(){
    int n; 
    cin >> n;
    int m; 
    cin >> m;
    int a[n], p[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        p[i] = a[i];
        if(i > 0){
            p[i] += p[i-1];
        }
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        int ans = bs(p, x, 0, n - 1);
        cout << ans <<endl;
    }
    return 0; 
}