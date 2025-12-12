#include <iostream>
using namespace std;

// Base class
class Parent
{
public:
    Parent()
    {
        cout << "Parent Class" << endl;
    }
};

// Child class inheriting from Parent
class Child : public Parent
{
public:
    Child()
    {
        cout << "Child Class" << endl;
    }
};

// GrandChild class inheriting from Child
// This forms multilevel inheritance: Parent → Child → GrandChild
class GrandChild : public Child
{
public:
    GrandChild()
    {
        cout << "GrandChild Class" << endl;
    }
};

int main()
{
    // Creating object of GrandChild
    // Constructor call order:
    // Parent → Child → GrandChild
    GrandChild gc;

    return 0;
}
