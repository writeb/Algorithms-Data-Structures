#include <iostream>
using namespace std;

int sz = 0;
struct node{
    string data;
    node* next;
    node(string data){
        this->data = data;
        next = nullptr;
    }
};

class LinkedList{
    node* head;
public:
    LinkedList(){
        head = nullptr;
    }
    void push_front(string data){
        node* newNode = new node(data);
        if (head == nullptr){
            head = newNode;
            sz++;
        } else {
            if (newNode->data == head->data){
                return;
            } else {
                newNode->next = head;
                head = newNode;
                sz++;
            }
        }
    }
    void print(){
        cout<<"All in all: "<<sz<<endl;
        cout<<"Students: "<<endl;
        node* tail = head;
        while(tail!=nullptr){
            cout<<tail->data<<endl;
            tail=tail->next;
        }
    }
};

int main(){
    LinkedList L;
    int n;
    cin>>n;
    string str;
    for (int i=0; i<n; i++){
        cin>>str;
        L.push_front(str);
    }
    L.print();
    
    return 0;
}