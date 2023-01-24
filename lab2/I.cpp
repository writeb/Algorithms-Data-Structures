#include <iostream>
using namespace std;

struct node{
    string data;
    node* next;
    node* prev;
    node(string data){
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class LinkedList{
    node* head;
    node* tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void add_front(string data){
        node* newNode = new node(data);
        if (head == nullptr){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void add_back(string data){
        node* newNode = new node(data);
        if (head == nullptr){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void erase_front(){
        if (head == nullptr){
            cout<<"error"<<endl;
            return;
        } 
        cout<<front()<<endl;
        if (!head -> next){
            head = tail = nullptr;
        } else {
            head = head -> next;
            head -> prev = nullptr;
        }
    }
    void erase_back(){
        if (head == nullptr){
            cout<<"error"<<endl;
            return;
        }
        cout<<back()<<endl;
        if(tail -> prev){
            tail = tail -> prev;
            tail -> prev -> next = nullptr;
        }else{
            head = tail = nullptr;
        }
    }
    string front(){
        if (head != nullptr) return head->data;
        else return "error";
    }
    string back(){
        if (head != nullptr) return tail->data;
        else return "error";
    }
    void clear(){
        head = nullptr;
        tail = nullptr;
    }
};

int main(){
    LinkedList L;
    string s,x;
    while(true){
        cin>>s;
        if(s=="add_front"){
            cin>>x;
            L.add_front(x);
            cout<<"ok"<<endl;
        }
        else if(s=="add_back"){
            cin>>x;
            L.add_back(x);
            cout<<"ok"<<endl;
        }
        else if(s=="erase_front"){
            L.erase_front();
        }
        else if(s=="erase_back"){
            L.erase_back();
        }
        else if(s=="front"){
            cout<<L.front()<<endl;
        }
        else if(s=="back"){
            cout<<L.back()<<endl;
        }
        else if(s=="clear"){
            L.clear();
            cout<<"ok"<<endl;
        }
        else if(s=="exit"){
            cout<<"goodbye";
            break;
        }
    }
    return 0;
}