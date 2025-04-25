// Queue using Array

#include<iostream>
using namespace std;

class Queue
{
    int queue[10];
    int front, rear;

    public:
    // This constructor initializes the front and rear of the queue to -1, indicating that the queue is empty.
    Queue(){
        front = -1;
        rear = -1;
        // front always points to the first element of the queue, and rear points to the last element.
    }

    void enqueue(int value){
        if(rear >=9){
            cout << "Queue Overflow" <<endl;
            return;
        }
        if(front == -1) front = 0; // If the queue is empty, set front to 0.
        queue[++rear]  = value; // Increment rear and add the new element.
    }

    void dequeue(){
        if(front == -1 || front > rear){
            cout << "Queue Underflow " <<endl;
            return;
        }
        cout << "Dequeued element: " << queue[front] << endl;
        front++; // Increment front to remove the element.
    }

    void peek(){
        if(front == -1 || front > rear){
            cout << "Queue is Empty" <<endl;
            return;
        }
        cout << "Front element:-" << queue[front] << endl;
    }
    void size(){
        if(front == -1 || front > rear){
            cout << "Queue is Empty" <<endl;
            return;
        }
        cout << "Size of Queue is :- " << rear - front + 1 << endl;
    }
    void isEmpty(){
        if(front == -1 || front > rear){
            cout << "Queue is Empty" <<endl;
        } else {
            cout << "Queue is not Empty" <<endl;
        }
    }
    void display(){
        if(front == -1 || front > rear){
            cout << "Queue is Empty" <<endl;
            return;
        }
        cout << "Queue's Elements:-";
        for(int i = front; i<=rear; i++){
            cout << queue[i] << " ";
        }
    }
};

int main(){
    Queue q;

    q.size(); // Output: Queue is Empty
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // Output: Queue's Elements: 10 20 30
    q.peek(); // Output: Front element: 10
    q.size(); // Output: Size of Queue: 3
    q.isEmpty(); // Output: Queue is not Empty
    q.dequeue(); // Output: Dequeued element: 10
    q.display(); // Output: Queue's Elements: 20 30
    q.peek(); // Output: Front element: 20
    q.size(); // Output: Size of Queue: 2
    q.isEmpty(); // Output: Queue is not Empty

}