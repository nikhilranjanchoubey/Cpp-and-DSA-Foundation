#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

// Counting Sort based on digit at 'pos' (1s, 10s, 100s, etc.)
void countSort(vector<int> &arr, int pos) {
    int n = arr.size();

    // Step 1: Frequency array for digits 0–9
    vector<int> freq(10, 0);
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / pos) % 10;
        freq[digit]++;
    }

    // Step 2: Convert frequency to cumulative count
    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
    }

    // Step 3: Build the output array (stable sort)
    vector<int> sorted(n);
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / pos) % 10;
        sorted[--freq[digit]] = arr[i];
    }

    // Step 4: Copy sorted values back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }
}

// Radix Sort driver: sorts based on each digit position
void radixSort(vector<int> &arr) {
    int max_val = INT_MIN;

    // Find the maximum number to determine number of digits
    for (int num : arr) {
        max_val = max(num, max_val);
    }

    // Apply counting sort for each digit position
    for (int pos = 1; max_val / pos > 0; pos *= 10) {
        countSort(arr, pos);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " non-negative integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radixSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}