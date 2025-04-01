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


// 12->3->5->7->4
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
    // 12->3->5->7->4
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

int main(){
    vector<int> arr = {12};

    Node* head = convertArr2DLL(arr);
    // print(head);

    head = removeHeadDLL(head);
    print(head);
}