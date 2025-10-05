#include<iostream>
using namespace std;

int main(){

    int arr[2] = {7, 5};        // Declare and initialize an array with two elements

    int *ptr = &arr[0];         // Pointer to the first element of the array (arr[0])

    // Pre-increment: ++ptr moves the pointer to the next element BEFORE dereferencing
    cout << *++ptr << endl;     // Output: 5 (value at arr[1])

    // Print array values directly to show they remain unchanged
    cout << arr[0] << " " << arr[1] << endl;  // Output: 7 5

    return 0;
}