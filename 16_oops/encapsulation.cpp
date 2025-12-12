#include <iostream>
using namespace std;

/* Encapsulation example:
data is private and accessed through public methods */
class ABC
{
private:
    int x; // private data member

public:
    // Setter function to assign value to x
    void set(int n)
    {
        x = n;
    }

    // Getter function to access the value of x
    int get()
    {
        return x;
    }
};

int main()
{
    ABC obj1;

    obj1.set(3);                // Setting value using setter
    cout << obj1.get() << endl; // Getting value using getter

    return 0;
}
