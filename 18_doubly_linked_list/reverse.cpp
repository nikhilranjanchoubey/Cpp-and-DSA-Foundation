/* Given the head of a doubly linked list, reverse it */

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;

    Node(int data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // void insertAtStart(int val) {
    //     Node *new_node = new Node(val);

    //     if (head == NULL) {
    //         head = tail = new_node;
    //         return;
    //     }

    //     new_node->next = head;
    //     head->prev = new_node;
    //     head = new_node;
    // }

    void insertAtEnd(int val) {
        Node *new_node = new Node(val);

        if (tail == NULL) {
            head = tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
};

// Function to reverse the doubly linked list
void reverseDll(Node* &head, Node* &tail) {

    Node* currPtr = head;

    while (currPtr != NULL) {
        // swap next and prev
        Node* nextPtr = currPtr->next;
        currPtr->next = currPtr->prev;
        currPtr->prev = nextPtr;

        // move to next node (which is previous before swap)
        currPtr = nextPtr;
    }

    // swap head and tail
    Node* temp = head;
    head = tail;
    tail = temp;
}

int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);

    cout << "Original list: ";
    dll.display();

    reverseDll(dll.head, dll.tail);

    cout << "Reversed list: ";
    dll.display();

    return 0;
}
