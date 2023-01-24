#include <iostream>
#include <deque>
using namespace std;

int main(){
deque<int> s1,s2;
for(int i=0;i<=4;i++){
    int a;
    cin>>a;
    s1.push_front(a);
}
for(int i=0;i<=4;i++){
    int a;
    cin>>a;
    s2.push_front(a);
}

int c1=0 ,c2=0;
for(int i=0;i<1000000;i++){
    c1++;
    if( s1.back()>s2.back()){
        if(s1.back()==9 && s2.back()==0)
        {
        
        s2.push_front(s1.back());
        s2.push_front(s2.back());
        s1.pop_back();
        s2.pop_back(); 
        }
     else {  
        s1.push_front(s1.back());
        s1.push_front(s2.back());
        s1.pop_back();
        s2.pop_back();
     }
    }
    else if( s1.back()<s2.back()) {
        if (s1.back()==0 && s2.back()==9){
         
        s1.push_front(s1.back());
        s1.push_front(s2.back());
        s1.pop_back();
        s2.pop_back();   
        }
        else{

        
        s2.push_front(s1.back());
        s2.push_front(s2.back());
        s1.pop_back();
        s2.pop_back();}
    }
    if (s1.empty())
    {
        cout<<"Nursik"<<" "<<c1;
        return 0;
    }
    else if (s2.empty())
    {
        cout<<"Boris"<<" "<<c1;
        return 0;
    }
    if(c1==1000000){
        cout<<"blin nichya";
    }
}
}