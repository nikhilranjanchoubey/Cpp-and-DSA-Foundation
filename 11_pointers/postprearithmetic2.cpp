#include<iostream>
using namespace std;

int main(){

    int arr[2] = {5, 4};        // Declare and initialize an array with two elements

    int *ptr = &arr[0];         // Pointer to the first element of the array

    // Postfix increment: (*ptr)++ means increment the value at ptr AFTER using it
    cout << (*ptr)++ << endl;   // Output: 5, then arr[0] becomes 6

    // Print updated array values
    cout << arr[0] << " " << arr[1] << endl;  // Output: 6 4

    return 0;
}