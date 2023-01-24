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
    cin>>s>>t;
    int cnt1 = 0;
    string st = t + "#" + s;
    vector <int> p = prefixFunction(st);
    for (int i=0; i<st.size(); i++){
        if (p[i] == t.size()) cnt1++;
    }
    cout<<cnt1<<endl;
    for (int i=0; i<st.size(); i++){
        if (p[i] == t.size()){
            cout<< i - 2 * t.size() + 1<<" ";
        }
    }


    return 0;
}