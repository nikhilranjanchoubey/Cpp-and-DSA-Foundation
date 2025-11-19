#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

// Function to perform Counting Sort on a vector of non-negative integers
void countSort(vector<int> &arr) {
    int n = arr.size();

    // Step 1: Find the maximum element in the array
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++) {
        max_val = max(arr[i], max_val);
    }

    // Step 2: Create and populate the frequency array
    vector<int> freq(max_val + 1, 0);
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Step 3: Convert frequency array to prefix sum array
    for (int i = 1; i <= max_val; i++) {
        freq[i] += freq[i - 1];
    }

    // Step 4: Build the sorted array using the prefix sums
    vector<int> sorted(n);
    for (int i = n - 1; i >= 0; i--) {
        sorted[--freq[arr[i]]] = arr[i];
    }

    // Step 5: Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " non-negative integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    countSort(arr); // Call the sorting function

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}