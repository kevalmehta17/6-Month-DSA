#include<iostream>
using namespace std;

// Time and space complexity for arr operation is:-
// Time complexity of all operations is O(1) and space complexity is O(n) where n is the size of the array.

class Stack{
    int stack[10];
    int top;

    public:
    // This constructor initializes the top of the stack to -1, indicating that the stack is empty.
    Stack(){
        top = -1;
    }
    void push(int value){
        if(top >= 9){
            cout << "Stack Overflow" <<endl;
            return;
        }
        top++;
        stack[top] = value;
    }

    void pop(){
        if(top < 0){
            cout <<"Stack Underflow" <<endl;
            return;
        }
        cout << "Popped element: " << stack[top] << endl;
        top--;
    }
    void peek(){
        if(top <0 ){
            cout << "Stack is empty"<<endl;
            return;
        }
        cout << "Top element: " << stack[top] << endl;
    }
    void isEmpty(){
        if(top <0) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack is not empty" << endl;
        }
    }
    void size(){
    cout << "Size of stack:- "<< top + 1 << endl;
    }
    void display(){
        if(top<0){
            cout <<"Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for(int i = top; i>=0; i--){
            cout <<stack[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack s;
    s.size();
    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); // Output: Stack elements: 30 20 10
    s.peek(); // Output: Top element: 30
    s.size(); // Output: Size of stack: 3
    s.isEmpty(); // Output: Stack is not empty
    s.pop(); // Output: Popped element: 30
    s.display(); // Output: Stack elements: 20 10
    return 0;
}