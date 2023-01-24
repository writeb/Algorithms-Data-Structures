// Простой deque
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

deque <int> dq;
char str[100];
int n;

int main(){
    while (scanf("%s", str)){
        if (strcmp(str,"push_front") == 0){
            cin>>n;
            dq.push_front(n);
            cout<<"ok\n";
        }
        else if (strcmp(str,"push_back") == 0){
            cin>>n;
            dq.push_back(n);
            cout<<"ok\n";
        }
        else if (strcmp(str,"pop_front") == 0){
            cout<<dq.front()<<"\n";
            dq.pop_front();
        }
        else if (strcmp(str,"pop_back") == 0){
            cout<<dq.back()<<"\n";
            dq.pop_back();
        }
        else if (strcmp(str,"front") == 0){
            cout<<dq.front()<<"\n";
        }
        else if (strcmp(str,"back") == 0){
            cout<<dq.back()<<"\n";
        }
        else if (strcmp(str,"size") == 0){
            cout<<dq.size()<<"\n";
        }
        else if (strcmp(str,"clear") == 0){
            dq.clear();
            cout<<"ok\n";
        }
        else{
            cout<<"bye\n";
            break;
        }
    }


    return 0;
}