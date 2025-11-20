#include <iostream>
#include <vector>
using namespace std;

// Recursive Binary Search function
int binarySearchRecursive(const vector<int> &input, int target, int lo, int hi) {
    if (lo > hi) return -1; // Base case: not found

    int mid = lo + (hi - lo) / 2; // Prevents overflow

    if (input[mid] == target) return mid; // Target found

    if (input[mid] < target) {
        return binarySearchRecursive(input, target, mid + 1, hi); // Search right half
    } else {
        return binarySearchRecursive(input, target, lo, mid - 1); // Search left half
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> input(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    int index = binarySearchRecursive(input, target, 0, n - 1);

    if (index != -1)
        cout << "Element " << target << " found at index " << index << ".\n";
    else
        cout << "Element " << target << " not found in the array.\n";

    return 0;
}