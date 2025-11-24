/* Given an array of integers ‘a’ that is sorted in non-decreasing order.
Find the first and the last position of the given ‘target’ element in the sorted array.
Follow 0-based indexing.
If ‘target’ is not found in the array, return [-1, -1].

Input :
Array = [1, 2, 3, 3, 3, 5, 11] , target = 3

Output :
[2, 4] */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Function: lowerbound
 * --------------------
 * Finds the first index in the sorted array where the value is 
 * greater than or equal to the target.
 *
 * Time Complexity: O(log n)  (binary search)
 * Space Complexity: O(1)
 */
int lowerbound(vector<int> &input, int target) { 
    int lo = 0, hi = input.size() - 1;
    int ans = -1; // default if not found
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // avoid overflow
        if (input[mid] >= target) {
            ans = mid;       // possible answer
            hi = mid - 1;    // look for earlier occurrence
        } else {
            lo = mid + 1;    // search right half
        }
    }
    return ans;
}

/*
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
int upperbound(vector<int> &input, int target) { 
    int lo = 0, hi = input.size() - 1;
    int ans = -1; // default if not found
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (input[mid] > target) {
            ans = mid;       // possible answer
            hi = mid - 1;    // look for earlier occurrence
        } else {
            lo = mid + 1;    // search right half
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n; // size of array

    vector<int> input;
    input.reserve(n); // optional optimization

    // Read n elements into the vector
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        input.push_back(x);
    }

    int target;
    cin >> target; // read target value

    vector<int> result;
    int lb = lowerbound(input, target);

    // If target not found in array
    if (lb == -1 || input[lb] != target) {
        result.push_back(-1);
        result.push_back(-1);
    } else {
        int ub = upperbound(input, target);
        result.push_back(lb);       // first occurrence
        result.push_back(ub - 1);   // last occurrence
    }

    // Print result: first and last index of target
    cout << result[0] << " " << result[1] << "\n";

    return 0;
}
