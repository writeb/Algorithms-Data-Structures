#include <iostream>
#include <vector>
using namespace std;

vector <int> prefixFunction(string a){
    int n = (int)a.length();
    vector <int> p(n);
    for (int i=1; i<n; i++){
        int j = p[i-1];
        while (j > 0 && a[i] != a[j]){
            j = p[j-1];
        }
        if (a[i] == a[j]) j++;
        p[i] = j;
    }
    return p;
}

int main(){
    string a, b;
    cin>>a>>b;
    if(a.find(b) != string :: npos){
        cout << 1;
        return 0;
    }
    string oldS = a;
    string newS = a;
    int total = 1;
    while(newS.size() < b.size()){
        newS += oldS;
        total++;
    }
    if(newS.find(b) != string :: npos){
        cout << total << "\n";
        return 0;
    }
    newS += oldS;
    total++;
    if(newS.find(b) != string :: npos){
        cout << total << "\n";  
        return 0;
    }
    cout << -1 << "\n";



    return 0;
}