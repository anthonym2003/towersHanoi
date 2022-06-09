#include "tower.h"

Node::Node(int newVal) {
    val = newVal;
    next = NULL;
}

Stack::Stack() {
    head = NULL;
    _size = 0;
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

bool Stack::isEmpty() {
    return head == NULL;
}

bool Stack::pop() {
    if (isEmpty()) {
        return false;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    _size--;
    return true;
}

int Stack::top() {
    if (isEmpty()) {
        return -1;
    }
    return head->val;
}

int Stack::size() {
    return _size;
}

void Stack::push(int num) {
    Node* newHead = new Node(num);
    newHead->next = head;
    head = newHead;
    _size++;
}

void Stack::printStack() {
    cout << endl;
    Node* temp = head;
    for (int i = 0; i < _size; i++) {
        int val = temp->val;
        for (int j = 0; j < val; j++) {
            cout << "#";
        }
        cout << endl;
        temp = temp->next;
    }

}

void printBorder() {
    for (int i = 0; i < 40; i++) {
        cout << "-";
    }
}

void printBoard(Stack &stack1, Stack &stack2, Stack &stack3) {
    cout << endl << endl;
    printBorder();
    stack1.printStack();
    printBorder();
    cout << endl << endl;
    stack2.printStack();
    cout << endl << endl;
    printBorder();
    cout << endl << endl;
    stack3.printStack();
    cout << endl << endl;
    printBorder();
    cout << endl << endl;
}