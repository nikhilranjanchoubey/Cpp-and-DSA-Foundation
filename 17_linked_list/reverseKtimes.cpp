/* Given the head of a linked list,
reverse the nodes of the list k at a time,
and return the modified list. */

#include <iostream>
using namespace std;

// Node represents each element of the linked list
class Node {
public:
    int val;
    Node *next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

// LinkedList handles list operations
class LinkedList {
public:
    Node *head;

    LinkedList() {
        head = NULL;
    }

    void insertAtTail(int value) {
        Node *new_node = new Node(value);
        if (head == NULL) {
            head = new_node;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Reverse nodes in groups of k
Node* reversekLL(Node* &head, int k) {
    Node* prevptr = NULL;
    Node* currptr = head;
    int counter = 0;

    while (currptr != NULL && counter < k) {
        Node* nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        counter++;
    }

    if (currptr != NULL) {
        Node* new_head = reversekLL(currptr, k);
        head->next = new_head;
    }

    return prevptr;
}

int main() {
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);

    cout << "Original list: ";
    ll.display();

    ll.head = reversekLL(ll.head, 2); 

    cout << "Modified list: ";
    ll.display();

    return 0;
}