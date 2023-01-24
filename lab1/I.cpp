#include <iostream>
#include <deque> 

using namespace std;

int main() {

    int n;
    cin >> n;
    
    string s;
    cin >> s;

    deque<int> saka;
    deque<int> katsu;

    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') saka.push_back(i); //01
        else if (s[i] == 'K') katsu.push_back(i); //234
    }

    while (saka.size() > 0 && katsu.size() > 0){
        if (saka.front() < katsu.front()) {
            int newIndex = 1 + max(saka.back(), katsu.back());
            saka.pop_front();
            saka.push_back(newIndex);
            katsu.pop_front();
        }
        else {
            int newIndex = 1 + max(saka.back(), katsu.back());
            katsu.pop_front();
            katsu.push_back(newIndex);
            saka.pop_front(); 
        }
    }

    if (saka.empty()) {
        cout << "KATSURAGI";
    } 
    else {
        cout << "SAKAYANAGI";
    }
    return 0;
}