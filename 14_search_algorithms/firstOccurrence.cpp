/* Find the first occurrence of a given element x, given array is sorted.
If no occurrence of x is found then return -1.

Input
arr = [2,5,5,5,6,6,8,9,9,9]
 x = 5
Output
1
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the first occurrence of target using Binary Search
int firstOccurrence(vector<int> &input, int target) {
    /*   Time Complexity: O(\log n)
         Space Complexity: O(1) */
    int lo = 0, hi = input.size() - 1;
    int ans = -1; // Default: not found

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Prevents overflow

        if (input[mid] == target) {
            ans = mid;      // Update answer (possible first occurrence)
            hi = mid - 1;   // Continue searching in the left half
        } 
        else if (input[mid] > target) {
            hi = mid - 1;   // Target lies in the left half
        } 
        else {
            lo = mid + 1;   // Target lies in the right half
        }
    }

    return ans; // Returns index of first occurrence or -1 if not found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target element: ";
    cin >> target;

    int index = firstOccurrence(arr, target);

    if (index != -1)
        cout << "First occurrence of " << target << " is at index " << index << ".\n";
    else
        cout << "Element " << target << " not found in the array.\n";

    return 0;
}