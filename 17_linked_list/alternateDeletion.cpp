/* Given the head of a linked list,
   delete every alternate element from the list starting from the second element. */

#include <iostream>
using namespace std;

// Node class represents each element of the linked list
class Node
{
public:
    int val;       // value stored in the node
    Node *next;    // pointer to the next node

    // Constructor to initialize a new node
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

// LinkedList class to handle linked list operations
class LinkedList
{
public:
    Node *head;    // pointer to the first node of the list

    // Constructor initializes an empty list
    LinkedList()
    {
        head = NULL;
    }

    // Function to insert a new node at the end (tail) of the list
    void insertAtTail(int value)
    {
        Node *new_node = new Node(value); // create a new node
        if (head == NULL)                 // if list is empty
        {
            head = new_node;              // new node becomes the head
            return;
        }

        // Traverse to the last node
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node; // attach new node at the end
    }

    // Function to display the linked list
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->"; // print value of each node
            temp = temp->next;
        }
        cout << "NULL" << endl; // end of list
    }
};

// Function to delete alternate nodes starting from the second node
void deleteAlternateNode(Node *&head)
{
    Node *curr_node = head; // start from the head
    while (curr_node != NULL && curr_node->next != NULL)
    {
        // temp points to the node that needs to be deleted
        Node *temp = curr_node->next;

        // skip the node to be deleted by linking current node to next of next
        curr_node->next = curr_node->next->next;

        // free memory of the deleted node
        free(temp);

        // move to the next node (skipping one each time)
        curr_node = curr_node->next;
    }
}

int main()
{
    LinkedList ll;

    // Insert nodes into the linked list
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);

    // Display original list
    ll.display();

    // Delete alternate nodes
    deleteAlternateNode(ll.head);

    // Display modified list
    ll.display();

    return 0;
}