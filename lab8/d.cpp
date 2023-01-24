#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll p = 31;
ll MOD = 1e9 + 7;

ll p1 = 37;
ll MOD1 = 1e9 + 9;

long long occur[200005];
long long p_pows[200005];
long long p_pows1[200005];
long long hs[200005];
long long hs1[200005];
long long hhs[200005];
long long hhs1[200005];

int main() {
    p_pows[0] = 1;
    for (int i = 1; i < 100005; i++) {
        p_pows[i] = (p_pows[i - 1] * p) % MOD;
    }

    while(true){
        int q;
        cin >> q;
        if (q == 0) break;
        pair<string,int> str[q];
        for (int i = 0; i < q; i ++){
            cin >> str[i].first;
            str[i].second = 0;
        }
        string s;
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            hs[i + 1] = (hs[i] + (s[i] - 'a' + 1) * p_pows[i]) % MOD;
        }
        int mx = -1;
        for (int i = 0; i < q; i ++){
            ll ht = 0;
            for (int j = 0; j < str[i].first.size(); j ++){
                ht = (ht + (str[i].first[j] - 'a' + 1) * p_pows[j]) % MOD;

            }
//            cout <<  ht << endl;

            for (int ii = 0; ii + str[i].first.size() - 1 < n; ii ++){
                ll cur = (hs[ii + str[i].first.size()] + MOD - hs[ii]) % MOD;
                if (ht * p_pows[ii] % MOD == cur){
                    str[i].second++;
                    mx = max(mx, str[i].second);
                }
            }
        }
        cout << mx << endl;
        for (int i = 0; i < q; i ++){
            if (str[i].second == mx){
                cout << str[i].first << endl;
            }
        }
    }
}