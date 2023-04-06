#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;

class Stack {
    private:
        int* stackArray; // pointer to dynamically allocated array
        int top; // index of the top element
        int max_size; // maximum size of the stack

    public:
        // Constructor
        Stack(int size) {
            top = -1;
            max_size = size;
            stackArray = new int[size];
        }

        // Destructor
        ~Stack() {
            delete[] stackArray;
        }

        // Push operation
        void push(int data) {
            if (isFull()) {
                cout << "Stack overflow!" << endl;
            }
            else {
                top++;
                stackArray[top] = data;
            }
        }

        // Pop operation
        int pop() {
            if (isEmpty()) {
                cout << "Stack underflow!" << endl;
                return -1;
            }
            else {
                int data = stackArray[top];
                top--;
                return data;
            }
        }

        // Check if stack is empty
        bool isEmpty() {
            return (top == -1);
        }

        // Check if stack is full
        bool isFull() {
            return (top == max_size - 1);
        }

        // Return the top element of the stack
        int stackTop() {
            if (isEmpty()) {
                cout << "Stack is empty!" << endl;
                return -1;
            }
            else {
                return stackArray[top];
            }
        }

        // Display the stack elements
        void display() {
            if (isEmpty()) {
                cout << "This stack is empty " << endl;
            }
            else {
                cout << "Stack elements are: ";
                for (int i = top; i >= 0; i--) {
                    cout << stackArray[i] << " ";
                }
                cout << endl;
            }
        }
};
int main() {
    Stack newStack(5); // Create a stack of size 5

    newStack.push(1);
    newStack.push(2);
    newStack.push(3);
    newStack.push(4);
    newStack.push(5);
    newStack.display(); // Output: Stack elements are: 5 4 3 2 1

    newStack.push(5);
    newStack.display();

    int Pop = newStack.pop();
    cout << "Pop : " << Pop << endl; // Output: Popped value is: 5

    newStack.display(); // Output: Stack elements are: 4 3 2 1

    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.display();  //Output: Stack elements:

    newStack.pop();
    newStack.display(); //Output: Stack is Empty

    bool check_Empty=newStack.isEmpty();
    cout << "If empty return 1 if not empty return 0 : " << check_Empty << endl; // Output: 0

    bool check_Full=newStack.isFull();
    cout << "Check if the element is full : " << check_Full << endl; // Output: 0

    int Top = newStack.stackTop();
    cout << "Top value is: " << Top << endl; // Output: Top value is: 20

    return 0;
}
