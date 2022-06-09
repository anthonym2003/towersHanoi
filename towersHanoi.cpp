#include "tower.h"
 
int main() {
    int height = -1, moves = 0, option = -1, disc; 
    cout << "How many disks do you wnat to play with ?" << endl;
    cout << "Has to be more than 3" << endl;
    while (height < 3) {
        cin >> height;
    }

    Stack stack1, stack2, stack3;
    Stack* stacks[3];
    stacks[0] = &stack1;
    stacks[1] = &stack2;
    stacks[2] = &stack3;

    for (int i = height; i > 0; i--) {
        stacks[0]->push(i);
    }

    cout << "Objective is to move all discs to the bottom stack!" << endl;;
    cout << "Can only move a smaller disc onto a larger disc" << endl;
    cout << "Optimal moves is 2^numDiscs - 1, let's see how you do!" << endl;
    printBoard(stack1, stack2, stack3);

    while (stack3.size() != height) {
        cout << "Which stack do you want to pick from? 1, 2, or 3?" << endl;
        while (true) {
            cin >> option;
            if (option >= 0 && option <= 3) {
                if (stacks[option - 1]->top() != -1) {
                    disc = stacks[option - 1]->top();
                    stacks[option - 1]->pop();
                    break;
                }
            }
        }
        cout << "Which stack do you want to move to? 1, 2, or 3?" << endl;
        while (true) {
            cin >> option;
            if (option >= 0 && option <= 3) {
                if (stacks[option - 1]->top() > disc || stacks[option - 1]->top() == -1) {
                    stacks[option - 1]->push(disc);
                    break;
                }
            }
        }
        printBoard(stack1, stack2, stack3);
        moves++;
    }
    cout << "YOU DID IT!" << endl;
    cout << "Only took " << moves << " moves!" << endl; 
}


