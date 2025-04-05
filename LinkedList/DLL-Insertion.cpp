#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


Node* convert2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}


// Insertion at head of DLL
// 12 <-> 3 <-> 5 <-> 7 <-> 4
Node* insertHeadDLL(Node* head, int val){
    if(!head ) return new Node(val);
    Node* newNode = new Node(val, head, nullptr);
    head->back = newNode;
    return newNode; 
}
// Insertion at tail of DLL
// 12 <-> 3 <-> 5 <-> 7 <-> 4
Node* insertTailDLL(Node* head,int val){
    if(!head) return new Node(val);
    if(!head->next) return insertHeadDLL(head, val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val,nullptr,temp);
    temp->next = newNode;
    return head;
}

// InsertBeforeTail
Node* insertBeforeTailDLL(Node* head, int val){
    if(!head) return new Node(val);
    if(!head->next) return insertHeadDLL(head, val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    temp->back = newNode;
    if(prev) prev->next = newNode;
    return head;
}

// Insertion at kth position of DLL
// 12 <-> 3 <-> 5 <-> 7 <-> 4
Node* insertKDLL(Node* head, int k, int val){
    if(!head && k == 1) return new Node(val, head, nullptr);
    if(k == 1){
        return new Node(val,head,nullptr);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == (k-1)){
            Node* newNode = new Node(val,temp->next, temp);
            temp->next = newNode;
            if(newNode->next){
                newNode->next->back = newNode;
            }
        }
        temp = temp->next;
    }
    return head;
}


// Insertion by value in DLL
// 12 <-> 3 <-> 5 <-> 7 <-> 4
Node* insertByValue(Node* head, int node, int val){
    if(!head) return nullptr;
    if(head->data == node){
        return new Node(val,head,nullptr);
    }
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == node) break;
        temp = temp->next;
    }
    if(!temp) return head; // If node not found, return original head
    Node* prev = temp->back;
    Node* front = temp->next;
    Node* newNode = new Node(val,temp,prev);
    temp->back = newNode;
    if(prev) prev->next = newNode;
    return head;
}

Node* insertVal(Node* head, int node, int val){
    if(!head) return nullptr;
    if(head->data == node){
        return new Node(val, head, nullptr);
    }
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == node){ 
            Node* prev = temp->back;
            Node* newNode = new Node(val,temp,prev);
            prev->next = newNode;
            temp->back = newNode;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {12, 3, 5, 7, 4};
    Node* head = convert2DLL(arr);
    // head = insertHeadDLL(head, 10);
    // // print(head);
    // head = insertTailDLL(head, 20);
    // print(head);
    // head = insertKDLL(head, 3, 100);
    // print(head);
    head = insertVal(head, 12, 50);
    print(head);

}