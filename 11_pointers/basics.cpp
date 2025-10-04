#include<iostream>
using namespace std;

int main(){

   int n = 10; // Declare an integer variable 'n' and initialize it with 10

    // Print the value stored in 'n'
    cout << "Value: " << n << endl; // Output: Value: 10

    // Print the memory address of variable 'n'
    cout << "Address: " << &n << endl; // Output: Address: (some hexadecimal address)

    // Declare a pointer 'ptr' that stores the address of 'n'
    int *ptr = &n;

    // Print the value of the pointer (i.e., the address it holds)
    cout << "Pointer: " << ptr << endl; // Output: Pointer: (same address as &n)

    // Dereference the pointer to access the value stored at that address
    cout << "Pointer: " << *ptr << endl; // Output: Pointer: 10

    return 0; // Exit the program
}

