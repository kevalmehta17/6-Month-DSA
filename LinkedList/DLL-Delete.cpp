#include<bits/stdc++.h>
using namespace std; 

struct Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1, Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


    // 12 <-> 3 <-> 5 <-> 7 <-> 4

Node* convertArr2DLL(vector<int> &arr){

    Node* head = new Node(arr[0]);
    Node* prev = head;
    
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Remove head in DLL
Node* removeHeadDLL(Node* head){
    // 12 <-> 3 <-> 5 <-> 7 <-> 4
    if(!head || head->next == NULL) return nullptr;
    
    Node* temp = head;
    head = head->next;
    if(head){
        head->back = nullptr;
        temp->next = nullptr;
    }
    delete temp;
    return head;
}  
// Remove tail in DLL
 // 12 <-> 3 <-> 5 <-> 7 <-> 4 
//  here value of k is 4
Node* removeTailDLL(Node* head){
    if(!head || head->next == NULL) return nullptr;
    
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->next == NULL){
        temp->back->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }
    return head;
}

// Remove kth in DLL
 // 12 <-> 3 <-> 5 <-> 7 <-> 4
 //K = 2
 Node* removeKDLL(Node* head, int k) {
    if (!head) return nullptr;

    int cnt = 0;
    Node* temp = head;
    
    // Traverse the list to find the k-th node
    while (temp != nullptr) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }

    // ❌ Handle case when k is out of bounds
    if (!temp) return head;  // If k is greater than the length of DLL, return unchanged head

    Node* prev = temp->back;
    Node* front = temp->next;

    // Case 1: Only One Node in the List
    if (!prev && !front) {
        delete temp;
        return nullptr;
    }
    // Case 2: Removing the First Node (head update required)
    else if (!prev) {
        head = head->next;
        if (head) head->back = nullptr; // Ensure head is valid before modifying back pointer
        delete temp;
        return head;
    }
    // Case 3: Removing the Last Node
    else if (!front) {
        prev->next = nullptr;
        delete temp;
        return head;
    }
    // Case 4: Removing a Middle Node
    else {
        prev->next = front;
        front->back = prev;
        delete temp;
        return head;
    }
}

// Remove By value in DLL
 // 12 <-> 3 <-> 5 <-> 7 <-> 4 <-> nullptr
// Remove a node by value in a Doubly Linked List
// 12 <-> 3 <-> 5 <-> 7 <-> 4 <-> nullptr
Node* removeByValDLL(Node* head, int val) {
    if (!head) return nullptr; // If DLL is empty, return nullptr

    Node* temp = head;

    // Traverse to find the node containing `val`
    while (temp) {
        if (temp->data == val) break;
        temp = temp->next;
    }

    // If value `val` is not found in the DLL, return original head
    if (!temp) return head;

    Node* prev = temp->back;
    Node* front = temp->next;

    // Case 1: Only One Node in the List
    if (!prev && !front) {
        delete temp;
        return nullptr; // DLL becomes empty
    }
    // Case 2: Removing the First Node (head update required)
    else if (!prev) {
        head = head->next; // Move head to next node
        if (head) head->back = nullptr; // Ensure head is valid before modifying back pointer
        delete temp;
        return head;
    }
    // Case 3: Removing the Last Node
    else if (!front) {
        prev->next = nullptr;
        delete temp;
        return head;
    }
    // Case 4: Removing a Middle Node
    else {
        prev->next = front;
        front->back = prev;
        delete temp;
        return head;
    }
}

// 

int main(){
    vector<int> arr = {12,3,5,7,4};

    Node* head = convertArr2DLL(arr);
    // print(head);
    // head = removeHeadDLL(head);
    // print(head);
    // head = removeTailDLL(head);
    // print(head);
    // head = removeKDLL(head,2);
    // print(head); 
    head = removeByValDLL(head,4);
    print(head);
}