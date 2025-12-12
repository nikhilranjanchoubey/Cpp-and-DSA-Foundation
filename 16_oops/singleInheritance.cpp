#include <iostream>
using namespace std;

// Base class (Parent)
class Parent
{
public:
    Parent()
    {
        cout << "Parent Class" << endl;
    }
};

// Derived class (Child) – single inheritance
// Child inherits publicly from Parent
class Child : public Parent
{
public:
    Child()
    {
        cout << "Child Class" << endl;
    }
};

int main()
{
    // Creating Child object
    // First Parent constructor is called, then Child constructor
    Child c;

    return 0;
}
