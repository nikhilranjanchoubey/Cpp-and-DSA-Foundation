#include <iostream>
#include <vector>
using namespace std;

class Queue
{
    int front;
    int back;
    int currsize;
    int totalsize;
    vector<int> v;

public:
    Queue(int n)
    {
        v.resize(n);
        this->back = n - 1;
        this->front = 0;
        this->currsize = 0;
        this->totalsize = n;
    }

    void enqueue(int data)
    {
        if (isFull())
            return;
        this->back = (this->back + 1) % this->totalsize;
        this->v[this->back] = data;
        this->currsize++;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        this->front = (this->front + 1) % this->totalsize;
        this->currsize--;
    }
    int getFront()
    {
        if (this->front == -1)
            return -1;
        return this->v[this->front];
    }
    bool isEmpty()
    {
        return this->currsize == 0;
    }
    bool isFull()
    {
        return this->currsize == this->totalsize;
    }
};

int main()
{
    Queue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(400);
    q.enqueue(500);

    while (not q.isEmpty())
    {
        cout << q.getFront() << " ";
        q.dequeue();
    }

    return 0;
}