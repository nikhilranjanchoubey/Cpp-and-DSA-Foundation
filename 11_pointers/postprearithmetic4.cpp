#include<iostream>
using namespace std;

int main(){

    int arr[2] = {8, 2};        // Declare and initialize an array with two elements

    int *ptr = &arr[0];         // Pointer to the first element of the array

    // Pre-increment the value at the pointer location
    // ++*ptr means: increment the value pointed to by ptr BEFORE using it
    cout << ++*ptr << endl;     // Output: 9 (arr[0] becomes 9)

    // Print updated array values
    cout << arr[0] << " " << arr[1];  // Output: 9 2

    return 0;
}