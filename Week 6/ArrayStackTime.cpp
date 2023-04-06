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
    Stack newStack(10); // Create a stack of size 10

    auto start = chrono::high_resolution_clock::now();

    newStack.push(8);
    newStack.push(10);
    newStack.push(5);
    newStack.push(11);
    newStack.push(15);
    newStack.push(23);
    newStack.push(6);
    newStack.push(18);
    newStack.push(20);
    newStack.push(17);

    newStack.display();

    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();

    newStack.display(); 

    newStack.push(4);
    newStack.push(30);
    newStack.push(3);
    newStack.push(1);

    newStack.display();

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}
