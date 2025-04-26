#include<iostream>
#include<queue>
using namespace std;


// lets implement this problem using 1 queue

class StackUsing1Queue
 {
    private:
        std::queue<int> q; // Queue to implement the stack
    public:
        void push(int x){
            q.push(x); //Push the new element to the queue
            // Rotate the queue to make the new element at the front
            int n = q.size();

            // Ex:- 10 20 30 
// to make 30 as front it act as 10 20 30 10 then pop so 20 30 10 and repeat until n-1
            for(int i = 0; i<n-1; i++){
                q.push(q.front()); // Move the front element to the back of the queue
                q.pop(); // Remove the front element from the queue
            }
        }
        void pop(){
            if(q.empty()){
                cout << "Stack underflow" <<endl;
            }
            else{
                cout << "Popped Element:-" << q.front() <<endl;
                q.pop(); // Remove the front element from the queue
            }
        }
        void peek(){
            if(q.empty()){
                cout << "Stack is empty" <<endl;
            }
            else{
                cout << "Top Element:- " <<q.front() << endl; // Return the front element of the queue
            }
        }
        void display(){
            if(q.empty()){
                cout << "Stack is empty" <<endl;
                return;
            }
            cout << "Stack Elements:- (from top to bottom):-";
            std::queue<int> temp = q; // Create a temporary queue to display elements
            while(!temp.empty()){
                cout << temp.front() << " ";
                temp.pop();
            }
        }

 };

// This is 2 Queue Implementation of stack
class Stack {
    private:
        queue<int> q1, q2; // Two queues to implement the stack

    public:

    // Here we have to push ele to q2 because we want to make sure that newly added element is at the front of q1.
    void push(int x){
        // Push to q2
        q2.push(x);
        // Put all the q1 elements behind the new element in q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        // Swap the names of q1 and q2
        // Proper ele order swapped to q1
        swap(q1, q2);
    }
    void pop(){
        if(q1.empty()){
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "Popped element: " << q1.front() << endl;
        q1.pop();
    }
    void peek(){
        if(q1.empty()){
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }
    void display(){
        if(q1.empty()){
            cout << "Stack is empty" <<endl;
            return;
        }
        cout << "Stack Elements:- (from top to bottom): ";
        queue<int> temp = q1; // Create a temporary queue to display elements
        while(!temp.empty()){
            cout << temp.front() << " ";
            temp.pop();
        }
    }
};

int main(){
    // Stack s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.display(); // Display stack elements
    // s.peek(); // Peek at the top element
    // s.pop(); // Pop the top element
    // s.display(); // Display stack elements after pop
    // return 0;
    StackUsing1Queue s1;
    s1.push(15);
    s1.push(20);
    s1.push(25);
    s1.display(); // Display stack elements
    s1.peek(); // Peek at the top element
    s1.pop(); // Pop the top element
    s1.display(); // Display stack elements after pop
    s1.peek(); // Peek at the top element after pop
    s1.pop(); // Pop the top element
}
