#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll p = 31;
ll MOD = 1e9 + 9;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> p_pows(s.size());
    p_pows[0] = 1;
    for (int i = 1; i < (int)p_pows.size(); i++) {
        p_pows[i] = (p_pows[i - 1] * p) % MOD;
    }
    vector<ll> hs(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        hs[i + 1] = (hs[i] + (s[i] - 'a' + 1) * p_pows[i]) % MOD;
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        string str = "";
        for (int i = l; i < r; i ++){
            str += s[i];
        }
//        cout << str << endl;
        ll ht = 0;
        for (int i = 0; i < str.size(); i ++){
            ht = (ht + (str[i] - 'a' + 1) * p_pows[i]) % MOD;
        }
//        cout << ht << endl;
        int res = 0;
        for (int i = 0; i + str.size() - 1 < n; i++) {
            ll cur = (hs[i + str.size()] + MOD - hs[i]) % MOD;
            if (ht * p_pows[i] % MOD == cur) res++;
//            cout << cur << endl;
        }
        cout << res << endl;
    }

}