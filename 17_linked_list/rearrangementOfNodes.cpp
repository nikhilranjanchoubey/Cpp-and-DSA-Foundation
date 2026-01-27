/* Pattern: Rearrangement of nodes in a list.
Given the head of a linked list, rotate the list to the right by k places. */

/* Solution Steps:
1. Find n (length of linked list).
2. Find Tail Node.
Tail->head = head
3. Traverse n-k nodes
n-kth->next=NULL
(n-k+1)th->new head */

#include <iostream>
using namespace std;

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

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

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
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node *rotateByK(Node *&head, int k)
{

    // 1. Find length of linked list
    int n = 0;
    // 2. Find tail node
    Node *tail = head;

    while (tail->next)
    {
        n++;               // Finding length
        tail = tail->next; // Finding last node
    }
    n++; // for including last node

    k = k % n;
    if (k == 0)
    {
        return head;
    }

    tail->next = head;
    // 3. Traverse n-k nodes
    Node *temp = head;
    for (int i = 1; i < n - k; i++)
    {
        temp = temp->next;
    }
    // temp is now pointing to (n-k)th node

    Node *newhead = temp->next;
    temp->next = NULL;
    return newhead;
}

int main()
{
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);

    cout << "\nOriginal Linked List: " << endl;
    ll.display();

    ll.head = rotateByK(ll.head, 3);
    cout << "\nLinked List after rotation: " << endl;
    ll.display();

    return 0;
}