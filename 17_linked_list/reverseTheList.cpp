/* Given the head of a singly linked list, reverse the list and return the reversed list. */

#include <iostream>
using namespace std;

// Node class represents each element of the linked list
class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

// LinkedList class to manage list operations
class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    // Insert a new node at the tail
    void insertAtTail(int value)
    {
        Node *new_node = new Node(value);
        if (head == NULL)
        {
            head = new_node;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
    }

    // Display the list
    void display(Node *node)
    {
        while (node != NULL)
        {
            cout << node->val << "->";
            node = node->next;
        }
        cout << "NULL" << endl;
    }
};

// Function to reverse the linked list and return new head
Node *reverseLL(Node *head)
{
    Node *prevptr = NULL;
    Node *currptr = head;

    while (currptr != NULL)
    {
        Node *nextptr = currptr->next; // store next node
        currptr->next = prevptr;       // reverse the link
        prevptr = currptr;             // move prev forward
        currptr = nextptr;             // move curr forward
    }

    return prevptr; // new head of reversed list
}

// Function to reverse linked list recursively
Node *reverseLLRecursion(Node *&head)
{

    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // recursive case
    Node *new_head = reverseLLRecursion(head->next);
    head->next->next = head;
    head->next = NULL; // head is now pointing to last node in reversed ll
    return new_head;
}

int main()
{
    LinkedList ll;

    // Insert elements
    ll.insertAtTail(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.insertAtTail(40);

    cout << "Original list: ";
    ll.display(ll.head);

    // Reverse and get new head

    // Node *reversedHead = reverseLL(ll.head);

    Node *reversedHead = reverseLLRecursion(ll.head);

    cout << "Reversed list: ";
    ll.display(reversedHead);

    return 0;
}