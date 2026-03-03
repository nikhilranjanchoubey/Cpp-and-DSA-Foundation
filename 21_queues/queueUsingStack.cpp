/* We are given a stack data structure with push and pop operations, the task is to
implement a queue using instances of stack data structure and operations on them. */

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Queue
{
    stack<int> st;

public:
    Queue() {}
    void push(int x)
    { // queue.enqueue
        this->st.push(x);
    }
    void pop()
    { // queue.dequeue
        if (this->st.empty())
            return;
        stack<int> temp;
        while (this->st.size() > 1)
        {
            temp.push(st.top());
            st.pop();
        }
        // now stack size is 1, and we are at the bottom element
        this->st.pop();
        while (not temp.empty())
        {
            this->st.push(temp.top());
            temp.pop();
        }
    }
    bool empty()
    {
        return this->st.empty();
    }
    int front()
    {
        if (this->st.empty())
            return -1;
        stack<int> temp;
        while (this->st.size() > 1)
        {
            temp.push(st.top());
            st.pop();
        }
        // now stack size is 1, and we are at the bottom element
        int result = this->st.top();
        while (not temp.empty())
        {
            this->st.push(temp.top());
            temp.pop();
        }
        return result;
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();

    while (not q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}