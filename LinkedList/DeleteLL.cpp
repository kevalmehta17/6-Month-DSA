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


// Remove At head
Node* removeHead(Node* head){
    if(head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    delete(temp);
    return head;
}
// Remove at tail
// 12->3->5->7->NULL
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

// Delete the k element from LL
// 12->3->5->7
Node* removeKele(Node* head, int k){
    if(head == NULL) return head;

    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            delete(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

//Remove Element by value  12->3->5->7
Node* removeEle(Node* head, int ele){
    if(head == NULL) return NULL;

    if(head->data == ele){
        Node* temp = head;
        head = head->next;
        delete(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == ele){
            prev->next = prev->next->next;
            delete(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main(){ 
    vector<int> arr = {12,3,5,7}; 
    Node* head = convert2LL(arr);
    // head = removeHead(head);
    // print(head);
    head = removeTail(head);
    print(head);
    // head = removeKele(head,3);
    // // print(head);
    // head = removeEle(head,5);
    // print(head);
}

// Leetcode :- 203 

// class Solution {
//     public:
//         ListNode* removeElements(ListNode* head, int val) {
//             while(head != NULL && head->val == val ){
//                 ListNode* temp = head;
//                 head = head->next;
//                 delete temp;
//             }
//             ListNode* prev = NULL;
//             ListNode* temp = head;
            
//             while(temp != NULL){
//                 if(temp->val == val){
//                     ListNode* toDelete = temp;
//                     temp = temp->next;
//                     if(prev != NULL){
//                     prev->next = temp;
//                     }
//                     delete toDelete;
//                 }
//                 else{
//                     prev = temp;
//                     temp = temp->next;
//                 }
//             }
//             return head;
//         }
//     };