#include <iostream>
using namespace std;

struct node{
    string data;
    node* next;
    node* prev;
    node(string data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};
int cnt = 0;

class LinkedList{
    int sz;
    node* head;
    node* tail;
public:
    LinkedList(){
        sz = 0;
        head = nullptr;
        tail = nullptr;
    }
    void push_back(string data){
        node* newNode = new node (data);
        if (head == nullptr){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        sz++;
    }
    int size() {
        return sz;
    }
    void cyclicshift(int x){
        int cnt = 0;
        node* cur = head;
        while(cur){
            if(cnt == x%size()){head = cur;return;}
            else{
                node* newNode = new node(cur->data);
                tail -> next = newNode;
                cur -> prev = tail;
                tail = newNode;
            }
            cur = cur -> next;
            cnt++;
        }
    }
    void print(){
        node* cur = head;
        while(cur!=nullptr){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
    }
};

int main(){
    LinkedList L;
    int n, x;
    cin>>n>>x;
    string str;
    for (int i=0; i<n; i++){
        cin>>str;
        L.push_back(str);
    }
    L.cyclicshift(x);
    L.print();

    return 0;
}