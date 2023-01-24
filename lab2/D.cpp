#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    int cnt;
    node(int data){
        this->data = data;
        next = nullptr;
        cnt = 1;
        
    }
};
int maxMode = 1;

class LinkedList{
    node* head;
    node* tail;
public:
    LinkedList(){
        head = tail = nullptr;
    }
    void push_back(int data){
        node* newNode = new node(data);
        if (head == nullptr){
            head = newNode;
        } else {
            node* tail = head;
            while(tail != nullptr){
                if (tail->data == data){
                    tail->cnt++;
                    if (tail->cnt >= maxMode){
                        maxMode = tail->cnt;
                    }
                    return;
                }
                else if (tail->next == nullptr){
                    tail->next = newNode;
                    return;
                }
                tail = tail->next;
            }
        }
    }
    void mod(){
        node * first = head;
        node * second = nullptr;
        while(first->next!=nullptr){
            second=first->next;
            while(second!=nullptr){
                if(second->data>first->data){
                    swap(second->data,first->data);
                    swap(second->cnt,first->cnt);
                }
                second = second->next;
            }
            first=first->next;
        }
        node * tail = head;
        while(tail!=nullptr){
            if(tail->cnt==maxMode){
                cout<<tail->data<<" ";
            }
            tail=tail->next;
        }
    }
    void print(){
        node* tail = head;
        while(tail!=nullptr){
            cout<<tail->data<<" "<<tail->cnt<<endl;
            tail=tail->next;
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
    L.mod();

    return 0;
}