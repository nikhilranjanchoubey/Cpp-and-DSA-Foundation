/* Find Kth smallest element in an array using QuickSort.

Input
Enter the elements of array
3 5 2 1 4 7 8 6
Enter the value for k
5

Output
K’th smallest element is 5 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Partition function used in QuickSort
int partition(int arr[], int l, int r) {
    int pivot = arr[r]; // Choose last element as pivot
    int i = l;           // Index for smaller element

    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[r]); // Place pivot in correct position
    return i;             // Return pivot index
}

// QuickSelect function to find Kth smallest element
int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int pos = partition(arr, l, r); // Position of pivot

        // If pivot is the Kth smallest
        if (pos - l == k - 1)
            return arr[pos];

        // If Kth smallest is in left partition
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);

        // If Kth smallest is in right partition
        return kthSmallest(arr, pos + 1, r, k - (pos - l + 1));
    }

    return INT_MAX; // Invalid k
}

int main() {
    int arr[] = {3, 5, 2, 1, 4, 7, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k;
    cout << "Enter the value for k: ";
    cin >> k;

    int result = kthSmallest(arr, 0, n - 1, k);
    if (result != INT_MAX)
        cout << "K'th smallest element is " << result << endl;
    else
        cout << "Invalid value of k!" << endl;

    return 0;
}