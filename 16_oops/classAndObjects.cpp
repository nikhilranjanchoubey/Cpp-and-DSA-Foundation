#include <iostream>  
using namespace std;

// Class definition for Fruit
class Fruit
{
public:
    string name;   // Data member to store the name of the fruit
    string color;  // Data member to store the color of the fruit
};

int main()
{
    // Creating an object of Fruit class (stack allocation)
    Fruit apple;  
    apple.name = "Apple";   // Assigning name to the apple object
    apple.color = "Red";    // Assigning color to the apple object

    // Displaying apple's details
    cout << apple.name << " - " << apple.color << endl;

    // Creating an object of Fruit class using dynamic memory allocation
    Fruit *mango = new Fruit();  
    mango->name = "Mango";   // Assigning name to the mango object
    mango->color = "Yellow"; // Assigning color to the mango object

    // Displaying mango's details
    cout << mango->name << " - " << mango->color << endl;

    return 0;
}