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

// This will conver the Array to LinkedList
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


Node* removeAtK(Node* head, int k){
    if(head == NULL) return NULL;

    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete(temp);
    }

    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = temp->next;
            delete(temp);
            break;

        }
        prev = temp;
        temp = temp->next;

    }
    return head;
    
}

Node* removeByValue(Node* head, int val){
    if(head == NULL) return NULL;

    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(temp->data == val){
            prev->next = temp->next;
            delete(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// 12->3->5->7->8

Node* insertAtk(Node* head, int k, int val){
    if(head == NULL){
        if(k == 1){
            return new Node(val);
        }
    }
    if(k == 1){
        return new Node(val,head);
    }
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* newNode = new Node(val,temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
}

Node* insertBeforeVal(Node* head, int ele,int val){
    if(head == NULL) return NULL;

    if(head->data == ele){
       return new Node(val,head);
    }
    Node* temp = head;
    while(temp->next && temp->next->data == ele){
        Node* newNode = new Node(val,temp->next);
        temp->next = newNode;
        break;
   }
   temp = temp->next;

}

int main(){
    vector<int> arr = {1,2,3,4,5};

    Node* head = convertTOLL(arr); // Convert the array to linked list
    // print(head);

    // // After removing the head
    // head = removesHead(head);
    // print(head);

    // head = removeTail(head);
    // print(head);
    head = removeAtK(head,3);
    print(head);
 
    // int sizeofLL = LengthOFLL(head);
    // cout<<"The length of LL is:- "<<sizeofLL;
}