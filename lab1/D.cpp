#include <iostream>
#include <stack>
using namespace std;

bool balanced(string str){
    stack <char> st;
    if (str.length() == 0){
        return true;
    }
    for (int i=0; i<str.length(); i++){
        if (st.empty()){
            st.push(str[i]);
        }
        else if (st.top() == str[i]){
            st.pop();
        }
        else{
            st.push(str[i]);
        }
    }
    if (st.empty()){ 
        return true;
    }
    else{
        return false;
    }
}

int main(){ 
    string str;
    cin>>str;
    if (balanced(str)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}