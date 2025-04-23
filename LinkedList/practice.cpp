#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;   
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
    
};

Node* removHead(Node* head){
    if(head ==nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}