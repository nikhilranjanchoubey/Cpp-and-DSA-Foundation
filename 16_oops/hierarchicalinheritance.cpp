#include <iostream>
using namespace std;

class Parent1
{
public:
    Parent1()
    {
        cout << "Parent Class" << endl;
    }
};

// Two child classes inheriting from the same parent → Hierarchical inheritance
class Child1 : public Parent1
{
public:
    Child1()
    {
        cout << "Child1 Class" << endl;
    }
};

class Child2 : public Parent1
{
public:
    Child2()
    {
        cout << "Child2 Class" << endl;
    }
};

int main()
{
    Child1 c1;
    Child2 c2;

    return 0;
}
