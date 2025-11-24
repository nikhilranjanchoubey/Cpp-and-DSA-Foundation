/* Search element in rotated sorted array with duplicate elements.
Return 1 if the element is found, else return -1.

Input :
0,0,0,1,1,1,2,0,0,0, target = 2

Output :
1 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Time Complexity: O(log n) in average case,
 *                  O(n) in worst case (when many duplicates exist).
 * Space Complexity: O(1)
 */
int searchInRotatedWithDuplicates(vector<int>& input, int target) {
    int lo = 0, hi = input.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // Case 1: Found target
        if (input[mid] == target) return 1;

        // Case 2: If duplicates block decision, shrink search space
        if (input[lo] == input[mid] && input[mid] == input[hi]) {
            lo++;
            hi--;
        }
        // Case 3: Left half is sorted
        else if (input[lo] <= input[mid]) {
            if (target >= input[lo] && target < input[mid]) {
                hi = mid - 1; // target lies in left half
            } else {
                lo = mid + 1; // target lies in right half
            }
        }
        // Case 4: Right half is sorted
        else {
            if (target > input[mid] && target <= input[hi]) {
                lo = mid + 1; // target lies in right half
            } else {
                hi = mid - 1; // target lies in left half
            }
        }
    }

    return -1; // not found
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

    int result = searchInRotatedWithDuplicates(input, target);
    cout << result << "\n";

    return 0;
}