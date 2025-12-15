/* Insertion at head & tail in a singly linked list */

#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int val;    // Data part of node
    Node *next; // Pointer to next node

    // Constructor to initialize node
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

// Function to insert a node at the head
void insertAtHead(Node *&head, int val)
{
    Node *new_node = new Node(val); // Create new node
    new_node->next = head;          // Point new node to current head
    head = new_node;                // Update head
}

// Function to insert a node at the tail
void insertAtTail(Node *&head, int val)
{
    Node *new_node = new Node(val); // Create new node

    // If linked list is empty
    if (head == NULL)
    {
        head = new_node;
        return;
    }

    // Traverse to the last node
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Link last node to new node
    temp->next = new_node;
}

// Function to display linked list
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL; // Initially list is empty

    insertAtHead(head, 2);
    display(head); // 2->NULL

    insertAtHead(head, 1);
    display(head); // 1->2->NULL

    insertAtTail(head, 3);
    display(head); // 1->2->3->NULL

    insertAtTail(head, 4);
    display(head); // 1->2->3->4->NULL

    return 0;
}
