#include <iostream>
using namespace std;

struct stack{
    private:
        int arr[200005];
        int topIndex;
        int sz;
    public:
    stack(){
        topIndex = 0;
        sz = 0;
    }
    void push(int val){
        topIndex++;
        arr[topIndex] = val;
        sz++;
    }
    void pop(){
        if (topIndex <= -1) return;
        topIndex--;
        sz--;
    }
    void back(){
        if (sz==0){
            cout<<"error"<<endl;
            return;
        }
        cout<< arr[topIndex]<<endl;
    }
    void max(){
        if (sz == 0){
            cout<<"error"<<endl;
            return;
        }
        if (sz==1){
            cout<<arr[topIndex]<<endl;
        }
        else {
            int m = -1e9;
            for (int i=1; i<=sz; i++){
                if (arr[i] > m){
                    m = arr[i];
                }
            }
            cout<<m<<endl;
        }
    }
};

int main(){
    stack s;
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        string str;
        cin>>str;
        if (str=="add"){
            int x;
            cin>>x;
            s.push(x);
        }
        else if (str == "delete"){
            s.pop();
        }
        else if (str=="getcur"){
            s.back();
        }
        else if (str=="getmax"){
            s.max();
        }
    }
    
    
    return 0;
}
