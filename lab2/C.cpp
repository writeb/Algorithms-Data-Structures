#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = nullptr;
    }
};  

class LinkedList{
    node* head;
    node* tail;
public:
    LinkedList(){
        head = nullptr;
        tail = head;
    }
    void push_back(int data){
        if (head == nullptr){
            head = new node(data);
            tail = head;
        } else {
            tail->next = new node(data);
            tail = tail->next;
        }
    }
    void print1(){
        node* tail = head;
        node* prev = nullptr;
        int index = 0;
        while (tail != nullptr){
            if (index%2 == 1){
                prev->next = tail->next;
                delete tail;
                tail = prev;
                tail = tail->next;
                index++;
                continue;
            }
            prev = tail;
            tail = tail->next;
            index++;
        }
        print();
    }
    void print(){
        node* tail = head;
        while(tail!=nullptr){
            cout<<tail->data<<" ";
            tail = tail->next;
        }
    }
};

int main(){
    LinkedList L;
    int n;
    cin>>n;
    int x;
    for (int i=0; i<n; i++){
        cin>>x;
        L.push_back(x);
    }
    L.print1();

    return 0;
}