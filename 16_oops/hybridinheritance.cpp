#include <iostream>
using namespace std;

class Parent1
{
public:
    Parent1()
    {
        cout << "Parent1 child" << endl;
    }
};

class Parent2
{
public:
    Parent2()
    {
        cout << "Parent2 child" << endl;
    }
};

// Hierarchical inheritance: Child1 inherits Parent1
class Child1 : public Parent1
{
public:
    Child1()
    {
        cout << "Child1 child" << endl;
    }
};

// Hierarchical inheritance: Child2 inherits Parent2
class Child2 : public Parent2
{
public:
    Child2()
    {
        cout << "Child2 child" << endl;
    }
};

// Hybrid inheritance: GrandChild inherits from BOTH Child1 and Child2
class GrandChild : public Child1, public Child2
{
public:
    GrandChild()
    {
        cout << "GrandChild child" << endl;
    }
};

int main()
{
    GrandChild gc;   // Calls Parent1 → Child1 → Parent2 → Child2 → GrandChild

    return 0;
}
