#include <iostream>
using namespace std;

// Function to print array elements recursively
void printArray(int *arr, int idx, int n) {
    // Base case: if index reaches array size, stop recursion
    if (idx == n) return;

    // Print current element
    cout << arr[idx] << "\n";

    // Recursive call to print the next element
    printArray(arr, idx + 1, n);
}

int main() {
    int n;

    // Enter array size
    cout << "Enter number of elements: ";
    cin >> n;

    // Declare array of size n
    int arr[n];

    // Input array elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print array recursively
    cout << "\nArray elements are:\n";
    printArray(arr, 0, n);

    return 0;
}