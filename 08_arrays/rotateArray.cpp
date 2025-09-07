// Rotate the given array 'a' by k steps,
// where k is non-negative.
// Note: k can be greater than n as well 
// where n is the size of array 'a'.

#include<iostream>
using namespace std;

int main() {
    // Original array
    int array[] = {1, 2, 3, 4, 5};
    int n = 5;       // Size of the array
    int k = 2;       // Number of rotation steps

    // Normalize k to avoid overflow (e.g., if k > n)
    k = k % n;

    // Array to store the rotated result
    int ansarray[5];
    int j = 0; // Index for ansarray

    //Insert last 'k' elements from original array into ansarray
    for (int i = n - k; i < n; i++) {
        ansarray[j++] = array[i];
        //After this loop, ansarray = [4, 5, _, _, _]
    }

    //Insert first 'n-k' elements from original array into ansarray
    for (int i = 0; i < n - k; i++) {
        ansarray[j++] = array[i];
        // After this loop, ansarray = [4, 5, 1, 2, 3]
    }

    //Print the rotated array
    cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
        cout << ansarray[i] << " ";
        // After this loop, Rotated array: [4, 5, 1, 2, 3]
    }
    cout << endl;

    return 0;
}