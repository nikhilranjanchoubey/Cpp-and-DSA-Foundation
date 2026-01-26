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

// Floyd’s Cycle Detection Algorithm
bool detectCycle(Node *head)
{
    if (!head)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Cycle detected at node with value: " << slow->val << endl;

            return true;
        }
    }

    return false;
}
// Extra
void removeCycle(Node *&head)
{
    // assuming that the linked llist has a cycle
    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
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
    ll.insertAtTail(7);
    ll.insertAtTail(8);

    // ll1.display();

    // Creating a cycle:
    ll.head->next->next->next->next->next->next->next->next =
        ll.head->next->next;

    cout << "\nChecking if cycle exists in the linked list..." << endl;
    cout << "Cycle Status: "
         << (detectCycle(ll.head) ? "Present" : "Not Present") << endl;

    removeCycle(ll.head);

    cout << "Removing cycle from the linked list..." << endl;
    cout << "Cycle Status After Removal: "
         << (detectCycle(ll.head) ? "Present" : "Not Present") << endl;

    cout << "Final Linked List (After Cycle Removal):" << endl;

    ll.display();

    ;

    return 0;
}
