/* Given the rotated sorted array of integers,
which contains distinct elements,and an integer target,
return the index of target if it is in the array.
Otherwise return -1.

Input :
Array = [3, 4, 5, 1, 2] , target = 4

Output :
1 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Function: binarySearchSortedRotated
 * -----------------------------------
 * Searches for a target element in a sorted rotated array.
 *
 * Key idea:
 * - A rotated sorted array has two sorted halves.
 * - At each step, check which half is sorted (left or right).
 * - Decide whether the target lies in that half.
 * - Narrow the search space accordingly.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int binarySearchSortedRotated(vector<int>& input, int target) {
    int lo = 0, hi = input.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // Case 1: Found target
        if (input[mid] == target) return mid;

        // Case 2: Left half is sorted
        if (input[mid] >= input[lo]) {
            if (target >= input[lo] && target <= input[mid]) {
                hi = mid - 1; // target lies in left half
            } else {
                lo = mid + 1; // target lies in right half
            }
        }
        // Case 3: Right half is sorted
        else {
            if (target >= input[mid] && target <= input[hi]) {
                lo = mid + 1; // target lies in right half
            } else {
                hi = mid - 1; // target lies in left half
            }
        }
    }

    return -1; // target not found
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

    int target;
    cout << "Enter target value: ";
    cin >> target;

    int result = binarySearchSortedRotated(input, target);

    if (result != -1) {
        cout << "Target found at index: " << result << "\n";
    } else {
        cout << "Target not found in array.\n";
    }

    return 0;
}