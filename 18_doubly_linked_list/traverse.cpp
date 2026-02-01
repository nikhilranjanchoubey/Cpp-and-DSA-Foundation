/* Given the head of a doubly linked list,
delete the nodes whose neighbors have the same value.
Traverse the list from right to left. */

/* Given the head of a doubly linked list, find if it's a palindrome or not. */

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;

    Node(int data)
    {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAtEnd(int val)
    {
        Node *new_node = new Node(val);

        if (tail == NULL)
        {
            head = tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
};

void deleteSameNeighbourNode(Node *&head, Node *&tail)
{

    Node *currNode = tail->prev; // second last node
    while (currNode != head)
    {
        Node *prevNode = currNode->prev;
        Node *nextNode = currNode->next;
        if (prevNode->val == nextNode->val)
        {
            // i need to delete the curr node
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            free(currNode);
        }

        currNode = prevNode;
    }
}

int main()
{
    DoublyLinkedList dll;

    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.display();

    deleteSameNeighbourNode(dll.head, dll.tail);
    dll.display();

    return 0;
}