#include <iostream>
#include <vector>
using namespace std;

bool cmp(char k, char m){
    if(int(m) < 97) return (k != char(int(m) + 32));
    if(int(k) < 97) return (m != char(int(k) + 32));
    return k != m;
}

vector<int> prefixFunction(string s){
    vector<int> pi(s.size());
    pi[0] = 0;
    for(int i = 1; i < s.size(); i++)
    {
        int j = pi[i - 1];
        while(j > 0 && cmp(s[j], s[i])){
            j = pi[j - 1];
        }
        if(!cmp(s[j], s[i])) pi[i] = j + 1;
        else pi[i] = 0;
    }
    return pi;
}

int kmp(string s, string t){
    s = t + "#" + s;
    vector<int> pi = prefixFunction(s);
    return pi[s.size() - 1];
}

int main(){
    string s; 
    cin >> s;
    int n; 
    cin >> n;
    string towns[n];
    int reses[n];
    int max = -1;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        cin >> towns[i];
    }
    for(int i = 0; i < n; i++){
        reses[i] = kmp(s,towns[i]);
        if(reses[i] == max) cnt++;
        if(reses[i] > max){
            max = reses[i];
            cnt = 0;
        }
    }
    if(max > 0){
        cout << cnt + 1<< endl;
        for(int i = 0; i < n; i++){
            if(reses[i] == max) cout << towns[i] << endl;
        }
    }
    else cout << 0;

    return 0;
}