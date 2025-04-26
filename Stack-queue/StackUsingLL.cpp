#include<iostream>
using namespace std;

// Lets implements the stack using linked list
// Time and space complexity for linked list operation is:-
// Time complexity of all operations is O(1) and space complexity is O(n) where n is the size of the linked list.

struct Node{
    int data;
    Node* next;
};

class Stack{
    private:
        Node* top; // Pointer to the top of the stack
    
    public:
        Stack(){
            top = nullptr; // Initialize the top pointer to null, indicating an empty stack
        }
        // 30->20->10->nullptr
        void push(int value){
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = top;
            top = newNode; // Update the top pointer to the new node
            cout<<"Element pushed: " << value << endl;
        }
        void pop(){
            if(top == nullptr){
                cout << "Stack Underflow" <<endl;
                return;
            }
            Node* temp = top; // Store the current top node
            cout << "Popped element: " << top->data << endl;
            top = top->next; // Update the top pointer to the next node
            delete temp; // Free the memory of the popped node
        }
        void peek(){
            if(top == nullptr){
                cout << "Stack is empty" <<endl;
                return;
            }
            cout << "Top element: " << top->data << endl;
        }
        void isEmpty(){
            if(top == nullptr){
                cout << "Stack is empty" <<endl;
            } else {
                cout << "Stack is not empty" <<endl;
            }
        }
        void size(){
            if(top == nullptr){
                cout << "Stack is empty" <<endl;
                return;
            }
            Node* temp = top;
            int count = 0;
            while(temp != nullptr){
                count++;
                temp = temp->next; // Traverse the linked list to count the number of nodes
            }
            cout << "Size of stack: " << count << endl;
        }
        void display(){
            if(top == nullptr){
                cout << "Stack is EMpty" <<endl;
                return;
            }
            cout << "Stack elements: ";
            Node* temp = top;
            while(temp != nullptr){
                cout << temp->data << " "; // Print the data of each node
                temp = temp->next; // Move to the next node
            }
            cout << endl;
        }
        
};

int main(){
    Stack s;
    s.size(); // Output: Stack is empty
    s.push(10); // Output: Element pushed: 10
    s.push(20); // Output: Element pushed: 20
    s.push(30); // Output: Element pushed: 30
    s.display(); // Output: Stack elements: 30 20 10
    s.peek(); // Output: Top element: 30
    s.size(); // Output: Size of stack: 3
    s.isEmpty(); // Output: Stack is not empty
    s.pop(); // Output: Popped element: 30
    s.display(); // Output: Stack elements: 20 10

    return 0;
}