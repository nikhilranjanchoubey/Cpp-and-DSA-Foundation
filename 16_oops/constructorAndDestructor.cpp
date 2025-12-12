#include <iostream>
using namespace std;

class Rectangle
{
public:
    int length;
    int breadth;

    Rectangle()
    { // default constructor - no arguments passed
        length = 0;
        breadth = 0;
    }

    Rectangle(int x, int y)
    {
        // parameterised constructor - arguments passed
        length = x;
        breadth = y;
    }

    Rectangle(Rectangle &r)
    {
        // copy constructor - initialise an object by another existing object
        length = r.length;
        breadth = r.breadth;
    }

    ~Rectangle(){ // Destructor
        cout<<"Destructor is Called"<<endl;
    }
};

int main()
{
    // Calls default constructor
    Rectangle r1;
    cout << r1.length << " " << r1.breadth << endl; // output:- 0 0

    // Calls parameterized constructor
    Rectangle r2(5, 6);
    cout << r2.length << " " << r2.breadth << endl; // output:- 5 6

    // Calls copy constructor
    Rectangle r3 = r2;
    cout << r3.length << " " << r3.breadth << endl; // output:- 5 6

    return 0;
}