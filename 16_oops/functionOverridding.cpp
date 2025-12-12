#include <iostream>
using namespace std;

class Parent {
public:
    // Virtual function → enables runtime polymorphism
    virtual void print() {
        cout << "parent class" << endl;
    }

    void show() {
        cout << "parent class" << endl;
    }
};

class Child : public Parent {
public:
    void print() {
        cout << "child class" << endl;
    }

    void show() {
        cout << "child class" << endl;
    }
};

int main() {
    Parent *p;
    Child c;

    p = &c;    // Base class pointer pointing to child object

    p->print();   // Calls Child::print() because print() is virtual → runtime polymorphism
    p->show();    // Calls Parent::show() because show() is NOT virtual

    return 0;
}
