#include <iostream>

#include <deque>
using namespace std;

deque<int> dq;

int main(){
    string str;
    int n;
    while (cin>>str){
        if (str == "+"){
            cin>>n;
            dq.push_front(n);
        }
        else if (str == "-"){
            cin>>n;
            dq.push_back(n);
        }
        else if (str == "*"){
           if(dq.empty()){
                cout << "error" << endl;
            }
            else if(dq.size() == 1){
                cout << dq.front()*2 << endl;
                dq.pop_front();
            }
            else{
                cout << dq.front()+dq.back() << endl;
                dq.pop_back();
                dq.pop_front();
            }
        }
        else{
            break;
        }
    }


    return 0;
}