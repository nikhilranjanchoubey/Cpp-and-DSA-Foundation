#include<iostream>
using namespace std;

int main(){
    
    int x = 20;           // Declare an integer variable
    double dec = 9.8;     // Declare a double variable

    int *ptr = &x;        // Pointer to integer x
    double *ptrd = &dec;  // Pointer to double dec

    // Display the size (in bytes) of each variable
    cout << "Size of x is: " << sizeof(x) << endl;       // Typically 4 bytes
    cout << "Size of dec is: " << sizeof(dec) << endl;   // Typically 8 bytes

    // Show pointer arithmetic: adding 1 moves the pointer by the size of the data type
    cout << ptr << "  " << (ptr + 1) << endl;     // Moves 4 bytes forward
    cout << ptrd << "  " << (ptrd + 1) << endl;   // Moves 8 bytes forward

    return 0;
}