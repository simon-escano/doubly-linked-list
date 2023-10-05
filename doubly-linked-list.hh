#include <iostream>
#include "list.hh"
#include "node.hh"
using namespace std;

class doublyLinkedList {
    nodePtr head, tail;
    int size;

    public:
    void print() {
        nodePtr curr = head;
        if (!size) {
            cout << "[ Empty ]" << endl;
            return;
        }
        cout << "[ ";
        while(curr) {
            cout << curr->data;
            if (curr == tail) {
                cout << " ]" << endl;
                break;
            }
            cout << " -> ";
            curr = curr->next;
        }
    }

    int get(int pos) {
        nodePtr curr = head;
        for (int i = 1; i < pos; i++) {
            curr = curr->next;
        }
        return curr->data;
    }

    void addHead(int num) {
        nodePtr newNode = new Node();
        newNode->data = num;
        newNode->prev = nullptr;
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void addTail(int num) {
        nodePtr newNode = new Node();
        newNode->data = num;
        newNode->next = nullptr;
        if (!tail) {
            tail = head = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void removeHead() {
        if (head == tail) return;
        head = head->next;
        free(head->prev);
        head->prev = NULL;
        size--;
    }

    void removeTail() {
        if (head == tail) return;
        tail = tail->prev;
        free(tail->next);
        tail->next = NULL;
        size--;
    }

    int removeAt(int pos) {
        int val;
        if (size == 0) {
            cout << "[ List is already empty ]" << endl;
            return -1;
        }
        if (pos == 1) {
            val = head->data;
            removeHead();
            return val;
        }
        if (pos == size) {
            val = tail->data;
            removeTail();
            return val;
        }
        nodePtr curr = head;
        for (int i = 1; i < pos; i++) {
            curr = curr->next;
        }
        (curr->prev)->next = curr->next;
        (curr->next)->prev = curr->prev;
        val = curr->data;
        free(curr);
        curr = NULL;
        size--;

        return val;
    }

    int removeAll(int num) {
        nodePtr curr = head;
        int ctr = 0;
        while(curr) {
            if (curr->data == num) {
                if (curr == head) {
                    removeHead();
                } else if (curr == tail) {
                    removeTail();
                } else {
                    (curr->prev)->next = curr->next;
                    (curr->next)->prev = curr->prev;
                    size--;
                }
                ctr++;
                curr = head;
            } else {
                curr = curr->next;
            }
        }
        return ctr;
    }
};