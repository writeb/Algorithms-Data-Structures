// Binary search
#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int> &v, int x){
    int l = 0;
    int r = (int)v.size()-1;
    while (r >= l){
        int m = (l + r)/2;
        if (v[m] == x) return true;
        if (v[m] < x) l = m+1;
        if (v[m] > x) r = m-1;
    }
    return false;
}

/*
bool find(vector<int> &v, int x){
    int i = find_lower(v, x);
    return i >= 0 && v[i] == x  
}
*/

int main(){
    int n, k;
    cin>>n>>k;
    vector <int> v(n);
    for (int i=0; i<n; i++) cin>>v[i];
    while (k--){
        int x;
        cin>>x;
        if (find(v, x)) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}