#include <iostream>
#include <vector>

#define ll long long
using namespace std;

ll p_pows[55];
ll p = 2;

void precalc(){
    p_pows[0] = 1;
    for (int i = 1; i <= 55; i ++){
        p_pows[i] = p_pows[i - 1] * p;
    }
}



int main() {
    precalc();
    int n;
    cin >> n;
    vector<ll> hash(n);
    for (int i = 0; i < n; i++){
        cin >> hash[i];
    }
    for (int i = 0; i < n; i ++){
        if (i) cout << char((hash[i] - hash[i - 1]) / p_pows[i] + 97);
        else cout << char(hash[i] / p_pows[i] + 97);
    }
}
