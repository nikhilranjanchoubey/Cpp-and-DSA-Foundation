/* Given the head of a singly linked list and print the reversed list. */

#include <iostream>
using namespace std;

// Node class represents each element of the linked list
class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

// LinkedList class to manage list operations
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert a new node at the tail
    void insertAtTail(int value) {
        Node* new_node = new Node(value);
        if (head == NULL) {
            head = new_node;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
    }

    // Display the list normally
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Recursive function to print the list in reverse
void reversePrint(Node* head) {
    if (head == NULL) // Base Case
        return;

    reversePrint(head->next); // recursive case
    cout << head->val << "->";
}

int main() {
    LinkedList ll;

    // Insert elements
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);

    cout << "Original list: ";
    ll.display();

    cout << "Reversed print: ";
    reversePrint(ll.head);
    cout << "NULL" << endl;

    return 0;
}