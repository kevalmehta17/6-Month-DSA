#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class Queue{
    private:
        Node* front;  // Pointer to the front of the queue
        Node* rear; // Pointer to the rear of the queue
        int count; // Count of elements in the queue
    public:
    // Constructor
    Queue(){
        front = nullptr;
        rear = nullptr;
        count = 0;
    }
    // front->10->20->30->nullptr
    void enqueue(int value){
        Node* newNode = new Node(); // Create a new node with the given value
        newNode->data = value;
        newNode->next = nullptr; // Initialize the next pointer to null
        if(rear == nullptr){
            front = rear = newNode; // If the queue is empty, set both front and rear to the new node
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        count++; // Increment the count of elements in the queue
    }
    void dequeue(){
        if(front == nullptr){
            cout << "Queue Underflow" <<endl;
            return;
        }
        Node* temp = front;
        cout << "Popped Element:- "<<front->data<<endl;
        front = front->next; // Move the front pointer to the next node
        delete temp;
        count--;
        if(front == nullptr){
            rear = nullptr; // If the queue becomes empty, set rear to nullptr
        }

    }
    void peek(){
        if(front == nullptr){
            cout << "Queue is empty" <<endl;
            return;
        }
        cout << "Front element: " << front->data << endl;
    }
    void isEmpty(){
        if(front == nullptr){
            cout << "Queue is empty" <<endl;
        } else {
            cout << "Queue is not empty" <<endl;
        }
    }
    void size(){
        cout << "Size of Queue is: " << count << endl;
    }
    void display(){
        if(front == nullptr){
            cout << "Queue is empty" <<endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while(temp){
            cout<< temp->data << " "; // Print the data of each node
            temp = temp->next; // Move to the next node

        }
        cout<< endl;
    }


};

int main(){
    Queue q;
    q.size(); // Output: Queue is empty
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // Output: Queue elements: 10 20 30
    q.peek(); // Output: Front element: 10
    q.size(); // Output: Size of Queue: 3
    q.isEmpty(); // Output: Queue is not empty
    q.dequeue(); // Output: Dequeued element: 10
    q.display(); // Output: Queue elements: 20 30
    return 0;
}