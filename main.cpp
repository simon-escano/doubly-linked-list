#include <iostream>
#include "doubly-linked-list.hh"
using namespace std;

int main() {
    doublyLinkedList* list = new doublyLinkedList();

    int input;
    char op;

    cout << "==== Doubly Linked List Operations ====\nOptions:\n- 'p': Print the current list.\n- 'h': Add an element to the head of the list.\n- 't': Add an element to the tail of the list.\n- 'g': Get an element at a specific position in the list.\n- 'H': Remove the head element from the list.\n- 'T': Remove the tail element from the list.\n- 'r': Remove an element at a specific position in the list.\n- 'R': Remove all occurrences of a value from the list.\n- 'x': Exit the program.\n=======================================" << endl;

    do {
        cout << "Enter op: ";
        cin >> op;
        switch(op) {
            case 'x':
                break;
            case 'p':
                list->print();
                break;
            case 'h':
                cin >> input;
                list->addHead(input);
                break;
            case 't':
                cin >> input;
                list->addTail(input);
                break;
            case 'g':
                cin >> input;
                cout << "[ Element " << input << ": " << list->get(input) << " ]" << endl;
                break;
            case 'H':
                list->removeHead();
                break;
            case 'T':
                list->removeTail();
                break;
            case 'r':
                cin >> input;
                cout << "[ Removed " << list->removeAt(input) << " at position " << input << " ]" << endl;
                break;
            case 'R':
                cin >> input;
                cout << "[ Removed " << list->removeAll(input) << " occurences of " << input << " ]" << endl;
                break;
            default:
                cout << "[ Invalid operation ]" << endl;
        }
    } while (op != 'x');
};
