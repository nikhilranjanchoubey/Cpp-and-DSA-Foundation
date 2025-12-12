#include <iostream>
using namespace std;

// First base class
class Parent1
{
public:
    Parent1()
    {
        cout << "Parent1 Class" << endl;
    }
};

// Second base class
class Parent2
{
public:
    Parent2()
    {
        cout << "Parent2 Class" << endl;
    }
};

// Child inherits from BOTH Parent1 and Parent2 → Multiple Inheritance
class Child : public Parent1, public Parent2
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
    // Constructor call order:
    // Parent1 → Parent2 → Child
    Child c;

    return 0;
}
