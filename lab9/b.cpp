#include <iostream>
#include <vector>
using namespace std;

vector <int> prefixFunction(string s){
    int n = (int)s.length();
    vector <int> p(n);
    for (int i=1; i<n; i++){
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
    int n;
    cin>>s>>n>>t;
    string st = s + "#" + t;
    vector <int> p = prefixFunction(st);
    for (int i=0; i<st.size(); i++){
        if (p[i] == s.size()) n--;
    }
    if (n<=0) cout<<"YES\n";
    else cout<<"NO\n";


    return 0;
}