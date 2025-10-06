#include <iostream>
using namespace std;

int main() {
    int a = 10;
    float b = 5.5;

    void *ptr; // Declares a void pointer — can point to any data type

    ptr = &a; // Points to an int
    cout << "Value of a: " << *(int*)ptr << endl;  // Typecast to int before dereferencing

    ptr = &b; // Points to a float
    cout << "Value of b: " << *(float*)ptr << endl; // Typecast to float before dereferencing

    return 0;
}