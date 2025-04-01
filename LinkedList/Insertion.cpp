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

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// 1->2->3->4->5
Node* convert2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
} 

Node* insertHead(Node* head, int val){
    if(head == NULL) return new Node(val);
    Node* temp = new Node(val,head);
    return temp;
}

Node* insertTail(Node* head, int val){
    if(head == NULL){
        return new Node(val,head);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->next == NULL){
        Node* newNode = new Node(val);
        temp->next = newNode;
    }
    return head;
}
// 12->3->4->5->7
Node* insertKele(Node* head, int k,int val){
    if(head == NULL){
        // for the empty    
        if(k == 1){
            return new Node(val,head);
        }else{
            return NULL;
        }
    }
    // Adding at the first
    if(k == 1){
        return new Node(val,head);
        // Node* temp = new Node(val,head);
        // temp->next = head;
        // return temp;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == (k-1)){
            Node* newNode = new Node(val,temp->next);
            // newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    // if(temp == NULL){
    //     return 0;
    // }
    return head;
}

Node* insertBeforeValue(Node* head, int ele, int val){
    if(head == NULL) return NULL;
   
    // If the element is found at the head
    if (head->data == ele) {
        return new Node(val, head);     
    }
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        if(temp->data == ele){
            Node* newNode = new Node(val,temp);
            if (prev) prev->next = newNode;
            return head;
            // newNode->next = temp;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {12,3,5,8,9};

    Node* head = convert2LL(arr); 

    // head = insertHead(head,100);
    // print(head);
    // head = insertTail(head,20);
    // print(head);
 
    // head = insertKele(head,2,100);
    // print(head);

    head = insertBeforeValue(head,5,200);
    print(head);

}