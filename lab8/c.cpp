#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll p = 31;
ll MOD = 1e9 + 7;

ll p1 = 37;
ll MOD1 = 1e9 + 9;

bool lezhit[200005];
long long occur[200005];
ll p_pows[200005];
ll p_pows1[200005];
ll hs[200005];
ll hs1[200005];
long long hhs[200005];
long long hhs1[200005];

int main() {
    string s;
    cin >> s;

    int n = s.size();
//    vector<long long> p_pows(s.size());
    p_pows[0] = 1;

    for (int i = 1; i < n; i++) {
        p_pows[i] = (p_pows[i - 1] * p) % MOD;
    }

//    vector<long long> p_pows1(s.size());
    p_pows1[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pows1[i] = (p_pows1[i - 1] * p1) % MOD1;
    }

//    vector<ll> hs(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        hs[i + 1] = (hs[i] + (s[i] - 'a' + 1) * p_pows[i]) % MOD;
    }

//    vector<ll> hs1(n + 1, 0);
    for (int i = 0; i < n; i ++){
        hs1[i + 1] = (hs1[i] + (s[i] - 'a' + 1) * p_pows1[i]) % MOD1;
    }

    int q;
    cin >> q;
    int L = s.size() + 1, R = 0;

    while(q--){
        string str;
        cin >> str;
        ll ht = 0;

        for (int i = 0; i < str.size(); i ++){
            ht = (ht + (str[i] - 'a' + 1) * p_pows[i]) % MOD;
        }

        ll ht1 = 0;
        for (int i = 0; i < str.size(); i ++){
            ht1 = (ht1 + (str[i] - 'a' + 1) * p_pows1[i]) % MOD1;
        }
        for (int i = 0; i + str.size() - 1 < n; i++) {
            ll cur = (hs[i + str.size()] + MOD - hs[i]) % MOD;
            ll cur1 = (hs1[i + str.size()] + MOD1 - hs1[i]) % MOD1;
            if (ht * p_pows[i] % MOD == cur && ht1 * p_pows1[i] % MOD1 == cur1){
                bool ok = true;
                int k = 0;
                int j = i;
                while(k < str.size()){
                    if (str[k] != s[j]){
                        ok = false;
                        break;
                    }
                    k++;j++;
                }
                if(ok) {
                    L = i;
                    R = i + str.size() - 1;
                    for (int ii = L; ii <= R; ii++) {
                        lezhit[ii] = true;
                    }
                }
            }
        }

    }
    for (int i = 0; i < s.size(); i ++){
        if (!lezhit[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}