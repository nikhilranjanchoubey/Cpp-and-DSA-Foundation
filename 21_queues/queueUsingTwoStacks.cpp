// queue_using_stacks_pop_efficient
/* We are given a stack data structure with push and pop operations, the task is to
implement a queue using instances of stack data structure and operations on them. */

#include <iostream>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

class Queue
{
    stack<int> st;

public:
    Queue() {}
    void push(int x)
    { // queue.enqueue
        stack<int> temp;
        while (not this->st.empty())
        {
            temp.push(this->st.top());
            this->st.pop();
        }
        this->st.push(x);
        while (not temp.empty())
        {
            this->st.push(temp.top());
            temp.pop();
        }
    }
    void pop()
    { // queue.dequeue
        if (this->st.empty())
            return;
        this->st.pop();
    }
    bool empty()
    {
        return this->st.empty();
    }
    int front()
    {
        if (this->st.empty())
            return INT_MIN;
        return this->st.top();
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
