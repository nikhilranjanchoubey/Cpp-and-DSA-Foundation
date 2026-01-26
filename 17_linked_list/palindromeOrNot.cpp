/* Given head, the head of a linked list,
determine if the linked list is a palindrome or not. */

/* Solution Steps:
1. Find middle Element.
2. Break Linked List into 2 parts.
3. Reverse second half of linked list.
4. Compare the 2parts of linked list. */

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

bool isPalindrome(Node* head){

    //1. Find middle element
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    //now slow is pointing to middle element
    //2. Break the linked list in the middle
    Node* curr = slow->next;
    Node* prev = slow;
    slow->next=NULL;

    //3. Reverse the secong half of linked list
    while(curr){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    //4. Check if the two linked list are equal or not
    Node* head1 = head;
    Node* head2 = prev;

    while(head2){
        if(head1->val!=head2->val){
            return false;
        }
        head1= head1->next;
        head2=head2->next;
    }
    return true;

}

int main()
{
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(3);
    ll.insertAtTail(2);
    ll.insertAtTail(1);

    cout<<"\nGiven Linked List: "<<endl;
    ll.display();

    cout<<"\nPalindrom or Not: "<<isPalindrome(ll.head)<<endl;

    return 0;
}