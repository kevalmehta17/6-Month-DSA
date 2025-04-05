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

Node* reverseDLL(Node* head) {
   if(!head || !head->next) return head; // If list is empty or has only one node

   Node* last = nullptr;
   Node* curr = head;
   while(curr){
    
    last = curr->back;
    curr->back = curr->next;
    curr->next = last;
    //  Move forward in the list (since pointers are swapped, we use prev)
    curr = curr->back;
   }
   // If last is not null, it means the second last node became the last node.
    // We need to return the new head, which is last->prev.
    if(last) head = last->back; // Update head to the new first node
    return head;
}

int main(){
    vector<int> arr = {12, 3, 5, 7, 4};
    Node* head = convert2DLL(arr);
    head = reverseDLL(head);
    cout<<"Reversed DLL: ";
    print(head);
    return 0;
}