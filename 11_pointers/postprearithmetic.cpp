#include<iostream>
using namespace std;

int main(){

    int arr[2] = {1, 12};        // Declare and initialize an array of two integers
    int *ptr = &arr[0];          // Pointer to the first element of the array

    // Print the address stored in ptr and the value at that address
    cout << ptr << " " << *ptr << endl;          // Output: address of arr[0], value = 1

    // Print the address of the next element and its value
    cout << (ptr + 1) << " " << *(ptr + 1) << endl;  // Output: address of arr[1], value = 12

    // Post-increment: print value at ptr, then move ptr to next element
    cout << *ptr++ << endl;       // Output: 1, then ptr now points to arr[1]

    // Print array values directly
    cout << arr[0] << " " << arr[1] << endl;     // Output: 1 12

    // Print updated pointer and value it now points to
    cout << ptr << " " << *ptr << endl;          // Output: address of arr[1], value = 12

    return 0;
}