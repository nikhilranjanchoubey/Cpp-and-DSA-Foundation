#include <iostream>
using namespace std;

class Parent
{
public:
    int x; // Accessible everywhere

protected:
    int y; // Accessible in Parent and derived classes

private:
    int z; // Accessible only inside Parent
};

// Public Inheritance:
// - public members stay public
// - protected members stay protected
// - private members remain inaccessible
class Child1 : public Parent
{
    // x → public
    // y → protected
    // z → inaccessible
};

// Private Inheritance:
// - public and protected members become private
// - private members remain inaccessible
class Child2 : private Parent
{
    // x → private
    // y → private
    // z → inaccessible
};

// Protected Inheritance:
// - public and protected members become protected
// - private members remain inaccessible
class Child3 : protected Parent
{
    // x → protected
    // y → protected
    // z → inaccessible
};

int main()
{
    Parent p;
    p.x; // Accessible (public member)

    // p.y; Not accessible (protected)
    // p.z; Not accessible (private)

    return 0;
}
