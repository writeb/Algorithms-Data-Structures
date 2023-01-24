#include <iostream>
#include <vector>
using namespace std;

vector <int> prefixFunction(string s){
    vector <int> p(s.size());
    p[0] = 0;
    for (int i=1; i<s.size(); i++){
        int j = p[i-1];
        while (j > 0 && s[i] != s[j]){
            j = p[j-1];
        }
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

int main(){
    string s, t;
    cin>>s>>t;
    int cnt;
    if(s.size() != t.size()){
        cout << -1;
    }
    string st = t + "#" + s;
    vector <int> p = prefixFunction(st);
    cnt = p.back();
    if(cnt == s.size()) cout << 0;

    s = s.substr(s.size() - cnt) + s.substr(0, s.size() - cnt);

    if(s == t) cout << cnt;
    else cout << -1;



    return 0;
}