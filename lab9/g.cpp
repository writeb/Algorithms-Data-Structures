#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixFunction(string s){
    vector<int> p(s.size());
    for(int i = 1; i < s.size(); i++){
        int j = p[i - 1];
        while(j > 0 && s[j] != s[i]){
            j = p[j - 1];
        }
        p[i] = j + (s[j] == s[i]);
    }
    return p;
}

int main(){
    string s;
    cin >> s;
    vector<int> p = prefixFunction(s);
    cout << s.size() - p.back();
    return 0;
}