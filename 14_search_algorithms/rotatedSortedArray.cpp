/* A rotated sorted array is a sorted array
on which rotation operation has been performed some number of times.
Given a rotated sorted array,
find the index of the minimum element in the array.
Follow 0-based indexing.
It is guaranteed that all the elements in the array are unique.

Input :
Array = [3, 4, 5, 1, 2]

Output :
3 */

 #include <iostream>
#include <vector>
using namespace std;

/*
  Time Complexity: O(log n)
  Space Complexity: O(1)
 */
int findMinimumInSortedRotated(vector<int> &input) {
    // Case 1: Only one element
    if (input.size() == 1) return input[0];

    int lo = 0, hi = input.size() - 1;

    // Case 2: Already sorted (no rotation)
    if (input[lo] < input[hi]) {
        return input[lo]; // return value, not index
    }

    // Binary search for pivot
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // Check if mid+1 is pivot
        if (mid < hi && input[mid] > input[mid + 1]) {
            return input[mid + 1];
        }

        // Check if mid itself is pivot
        if (mid > lo && input[mid] < input[mid - 1]) {
            return input[mid];
        }

        // Decide which half to search
        if (input[mid] >= input[lo]) {
            // Left half is sorted, pivot must be in right half
            lo = mid + 1;
        } else {
            // Right half is sorted, pivot must be in left half
            hi = mid - 1;
        }
    }

    return -1; // should never reach here if input is valid rotated array
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> input;
    input.reserve(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        input.push_back(x);
    }

    int minimum = findMinimumInSortedRotated(input);
    cout << "Minimum element in the array: " << minimum << "\n";

    return 0;
}