#include <iostream>
#ifndef TOWER_H
#define TOWER_H
using namespace std;
// Header File 
// Node implementation for Stack Data Structure
struct Node {
    int val;
    Node* next;
    Node(int newVal);
};

// Stack Data Structure Implementation
class Stack {
    public:
        Stack();
        ~Stack();
        bool isEmpty();
        bool pop();
        int top();
        int size();
        void push(int num);
        void printStack();
    private:
        Node* head;
        int _size;
};
// Printing game to the console
void printBoard(Stack &stack1, Stack &stack2, Stack &stack3);
void printBorder();
#endif