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
    string s;
    cin >> s;
    vector<int> p = prefixFunction(s);
    int cnt = 0;
    for(int i = 0; i < p.size() - 1; i++){
        if(p[i] == 0) continue;
        int sz = i + 1;
        int k = sz - p[i];
        if(sz % k != 0) continue;
        if((sz / k) % 2 == 0){
            cnt++;
        }
    }
    cout << cnt;


    return 0;
}