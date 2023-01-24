#include <iostream>
#include <unordered_map>
#define ull unsigned long long
#define ll long long
using namespace std;

ll MOD = 1e15 + 7;
ll X = 31;

ll hash_code(string &s) {
    int size = s.size();
    unordered_map<ull, bool> m;
    for (int i = 0; i < size; i++) {
        ll hash = 0;
        ll curX = 1;
        for(int j = i ; j < size; j++){
            ull curHash = ((s[j] - 96) * curX) % MOD;
            hash = (hash + curHash) % MOD;
            curX = (curX * X) % MOD;
            if(!m[hash]) {
                m[hash] = true;
            }
        }
    }
    return m.size();
}

int main(){
    string str;
    cin>>str;
    cout<<hash_code(str);



    return 0;
}