#include <iostream>
#include <algorithm>
using namespace std;

void print(string s){
    for (int i = 0; i < s.size(); i ++){
        cout << s[i];
    }
}

int partition (string s, int low, int high){
    int pivot = s[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++){
        if (s[j] < pivot){
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return (i + 1);
}


void quickSort(string s, int low, int high){
    if (low < high){
        int pi = partition(s, low, high);
        quickSort(s, low, pi - 1);
        quickSort(s, pi + 1, high);
    }
}

int main(){
    long long n;
    cin>>n;
    string s;
    cin>>s;
    string s1="", s2="";
    for(int i=0; i<s.size(); i++){
        if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
            s1.push_back(s[i]);
        }
        else{
            s2.push_back(s[i]);
        }
    }
    // quickSort(s1 ,0 , s1.size()-1);
    // quickSort(s2 ,0 , s2.size()-1);
    sort(begin(s1), end(s1));
    sort(begin(s2), end(s2));
    print(s1);
    print(s2);

    return 0;
}