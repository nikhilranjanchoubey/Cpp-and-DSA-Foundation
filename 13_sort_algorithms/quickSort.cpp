#include <iostream>
using namespace std;

// Partition function to place the pivot element at its correct position
// and rearrange elements such that those less than pivot are on the left,
// and those greater are on the right.
int partition(int arr[], int first, int last) {
    int pivot = arr[last];       // Choosing the last element as pivot
    int i = first - 1;           // Index for placing elements smaller than pivot
    int j = first;               // Index for scanning the array

    // Traverse through the array and swap elements smaller than pivot
    for (; j < last; j++) {
        if (arr[j] < pivot) {
            i++;                 // Move the boundary for smaller elements
            swap(arr[i], arr[j]); // Swap current element with the boundary element
        }
    }

    // Place the pivot element at its correct sorted position
    swap(arr[i + 1], arr[last]);
    return i + 1;                // Return the pivot index
}

// Recursive QuickSort function to sort the array
void quickSort(int arr[], int first, int last) {
    // Base case: if the subarray has one or no elements, it's already sorted
    if (first >= last) {
        return;
    }

    // Partition the array and get the pivot index
    int pi = partition(arr, first, last);

    // Recursively sort the left subarray
    quickSort(arr, first, pi - 1);

    // Recursively sort the right subarray
    quickSort(arr, pi + 1, last);
}

int main() {
    // Sample array to be sorted
    int arr[] = { 20, 12, 35, 16, 18, 30 };
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements

    // Call QuickSort on the entire array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}