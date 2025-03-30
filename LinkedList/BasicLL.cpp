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
// Function to find the length of the linked list
int LengthOFLL(Node* head){
    int cnt = 0; 
    Node* temp = head;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}


Node* convertTOLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

// 1->2->3->4->5->NULL
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Print the LinkedList

void print(Node* head){
    while(head != NULL){
       cout<< head->data<<" ";
       head = head->next;
    }
    cout<<endl;
}


// Remove the head
Node* removesHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

//Remove the tail
// 1->2->3->4->5->NULL
Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete(temp->next);
    temp->next = nullptr;
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    Node* head = convertTOLL(arr); // Convert the array to linked list
    print(head);

    // After removing the head
    head = removesHead(head);
    print(head);

    head = removeTail(head);
    print(head);
 
    // int sizeofLL = LengthOFLL(head);
    // cout<<"The length of LL is:- "<<sizeofLL;
}