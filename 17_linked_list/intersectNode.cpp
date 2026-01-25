/* Given the heads of two singly linked-lists headA and headB,
return the node at which the two lists intersect.
If the two linked lists have no intersection at all, return null. */

#include <iostream>
using namespace std;

// Node class representing each element of the linked list
class Node {
public:
    int val;       // Value stored in the node
    Node* next;    // Pointer to the next node

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

    // Insert a new node at the end of the list
    void insertAtTail(int value) {
        Node* new_node = new Node(value);
        if (head == NULL) {
            head = new_node;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Utility function to calculate length of a linked list
int getLength(Node* head) {
    Node* temp = head;
    int length = 0;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Move head pointer forward by k steps
Node* moveHeadByK(Node* head, int k) {
    Node* ptr = head;
    while (k-- && ptr != NULL) {
        ptr = ptr->next;
    }
    return ptr;
}

// Function to find intersection point of two linked lists
Node* getIntersection(Node* head1, Node* head2) {
    if (!head1 || !head2) return NULL;

    // Step 1: Calculate lengths of both linked lists
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    Node* ptr1;
    Node* ptr2;

    // Step 2: Align both pointers by moving the longer list ahead
    if (l1 > l2) {
        int k = l1 - l2;
        ptr1 = moveHeadByK(head1, k);
        ptr2 = head2;
    } else {
        int k = l2 - l1;
        ptr1 = head1;
        ptr2 = moveHeadByK(head2, k);
    }

    // Step 3: Traverse both lists together until intersection is found
    while (ptr1 && ptr2) {
        if (ptr1 == ptr2) {  // Intersection found
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL; // No intersection
}

int main() {
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);

    LinkedList ll2;
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);

    
    // Attach common part to both lists
    ll2.head->next->next = ll1.head->next->next->next;

    // Display lists
    ll1.display();
    ll2.display();

    // Find intersection
    Node* intersection = getIntersection(ll1.head, ll2.head);
    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}