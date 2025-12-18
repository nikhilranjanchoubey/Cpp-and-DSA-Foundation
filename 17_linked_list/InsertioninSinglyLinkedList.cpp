/* 
   Program: Insertion in Singly Linked List
   Operations:
   1. Insert at Head
   2. Insert at Tail
   3. Insert at Given Position
*/

#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int val;        // Data part of node
    Node *next;     // Pointer to next node

    // Constructor
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

// Function to insert a node at the head of the linked list
void insertAtHead(Node *&head, int val)
{
    Node *new_node = new Node(val); // Create new node
    new_node->next = head;          // Link new node to current head
    head = new_node;                // Update head
}

// Function to insert a node at the tail of the linked list
void insertAtTail(Node *&head, int val)
{
    Node *new_node = new Node(val); // Create new node

    // If list is empty
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

// Function to insert a node at a specific position (0-based index)
void insertAtPosition(Node *&head, int val, int pos)
{
    // Invalid position
    if (pos < 0)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    // Insert at head if position is 0
    if (pos == 0)
    {
        insertAtHead(head, val);
        return;
    }

    Node *temp = head;
    int current_pos = 0;

    // Traverse till position-1 safely
    while (temp != NULL && current_pos < pos - 1)
    {
        temp = temp->next;
        current_pos++;
    }

    // If position is out of range
    if (temp == NULL)
    {
        cout << "Position out of range!" << endl;
        return;
    }

    // Insert new node
    Node *new_node = new Node(val);
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to display the linked list
void display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Main function
int main()
{
    Node *head = NULL; // Initially, linked list is empty

    insertAtHead(head, 2);
    display(head);   // 2 -> NULL

    insertAtHead(head, 1);
    display(head);   // 1 -> 2 -> NULL

    insertAtTail(head, 3);
    display(head);   // 1 -> 2 -> 3 -> NULL

    insertAtTail(head, 4);
    display(head);   // 1 -> 2 -> 3 -> 4 -> NULL

    insertAtPosition(head, 4, 1);
    display(head);   // 1 -> 4 -> 2 -> 3 -> 4 -> NULL

    return 0;
}
