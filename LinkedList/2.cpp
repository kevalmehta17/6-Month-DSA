#include<bits/stdc++.h>
using namespace  std;

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


Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;

}
//find the length of the linked list

int lengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// check/Search in LinkedList

int checkIfPresent(Node* head,int value){
    Node* temp = head;
    while(temp){
        if(temp->data == value){
            return 1;

        }
        temp = temp->next;
    }
    return 0;
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    // Lets convert  Array to LinkedList
    Node* head = convertArr2LL(arr);
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    int len = lengthOfLL(head);
    cout<<len<<endl;

    cout<<"Check for the Element:- "<<checkIfPresent(head,31);


}
// Example
// head -> [1 | next] --> [2 | next] --> [3 | next=nullptr]
// mover -> [3 | next=nullptr]
