#include <iostream>
using namespace std;

struct Node{
    int val;
    int size;
    Node* next;
    Node (int val, int size){
        this->val = val;
        this->size = size;
        next = nullptr;
    }
};

class LinkedList{
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void push(int val, int size){
        Node* newNode = new Node(val, size);
        if (head == nullptr){
            head = tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void print(int a){
        int m = 1e9;
        int cnt = 0;
        //Node* cur = head;
        while (head != nullptr){
            int q = abs(head -> size - a);
            if (q < m){
                m = q;
                cnt = head -> val;
            }
            head = head -> next;
        }
        cout<<cnt;
    }
};

int main(){
    LinkedList L;
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        int m;
        cin>>m;
        L.push(i, m);
    }
    int x;
    cin>>x;
    L.print(x);

    return 0;
}