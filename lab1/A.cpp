#include <iostream>
#include <deque>
using namespace std;
void royal(int n){
    deque<int> d;
    for(int i=n;i>=1;i--){
        d.push_front(i);
        for (int j = 0;j<i; j++)
        {
            d.push_front(d.back());
            d.pop_back();
        }
    }
        deque <int> :: iterator it;
        for (it=d.begin(); it !=d.end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        royal(n);
    }
}