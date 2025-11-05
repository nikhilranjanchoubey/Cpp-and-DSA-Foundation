#include <iostream>
using namespace std;

// Function to find the maximum element in the array recursively
int findMax(int idx, int n, int arr[]) {
    // Base case: if we're at the last element, return it
    if (idx == n - 1) {
        return arr[idx];
    }

    // Recursive call: find max in the rest of the array
    int maxInRest = findMax(idx + 1, n, arr);

    // Compare current element with max from rest
    return max(arr[idx], maxInRest);
}

int main() {
    int n;

    // Enter array size
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Input array elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find the maximum
    int maxElement = findMax(0, n, arr);

    // Output
    cout << "Maximum element in the array is: " << maxElement << endl;

    return 0;
}