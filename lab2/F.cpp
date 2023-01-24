#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
    node(int data){
        this -> data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList{
    int sz;
    public:
    node* head;
    node* tail;
    LinkedList(){
        sz = 0;
        head = nullptr;
        tail = nullptr;
    }
    void push_back(int data){
        node* newNode = new node(data);
        if(!head){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        ++sz;
    }
    void insert(int a,int b,int n){
        node* cur = head;
        int ind = 0;
        node* newNode = new node(a);
        while(cur){
            if(b==0){
                newNode -> next = head;
                head -> prev = newNode;
                head = newNode;
                break;
            }
            
            if(ind==b){
                cur -> prev -> next = newNode;
                newNode -> prev = cur -> prev;
                newNode -> next = cur;
                cur -> prev = newNode;
                break;
            }
            cur = cur -> next;
            ind++;
        }
        sz++;
    }
    void print(){
        node* cur = head;
        while(cur){
            cout<< cur -> data <<" ";
            cur = cur -> next;
        }
    }
};

int main(){
    LinkedList L;
    int n;
    int x;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        L.push_back(x);
    }
    int a,b;
    cin>>a>>b;
    L.insert(a,b,n);
    L.print();
}