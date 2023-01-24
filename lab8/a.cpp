#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define ll long long

string convert(int n){
    string s = "";
    while(n > 0){
        s = char(48 + n % 10) + s;
        n = n / 10;
    }
    return s;
}

ll pow2(int power, int coef){
    ll ans = coef;
    for(int i = 0; i < power; i++){
        ans = (ans * 11) % (1000000007);
    }
    return ans;
}

int h(string s){
    ll ans = 0;

    for(int i = 0; i < s.size(); i++){
        ans = (ans + pow2(i, s[i] - 47)) % (1000000007);
    }
    return ans % 1000000007;
}

int main(){
    int n;
    cin >> n;
    cin >> ws;
    map<string, string> m;
    vector <string> vec;
    for(int i = 0; i < 2 * n; i++){
        string s;
        getline(cin, s);
        vec.push_back(s);
        m[convert(h(s))] = s;
    }


    map <string, string> new_map;
    for(int i = 0; i < vec.size(); i++){
        if(m.find(vec[i]) != m.end()){
            new_map[m[vec[i]]] = vec[i];
        }
    }

    map <string, string> :: iterator it;
    int c = 0;
    for(int i = 0; i < vec.size(); i++){
        if(new_map.find(vec[i]) != new_map.end()){
            cout << "Hash of string " << "\"" <<  vec[i] << "\"" <<  " is " << new_map[vec[i]] << endl;
            c++;
        }
        if(c == n){
            break;
        }
    }

    return 0;
}