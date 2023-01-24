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
    int n;
    cin>>n;
    while (n--){
        string s;
        int t;
        cin>>s>>t;
        vector <int> p = prefixFunction(s);
        cout << s.size() + (s.size() - p.back()) * (t - 1) <<endl;
    }



    return 0;
}