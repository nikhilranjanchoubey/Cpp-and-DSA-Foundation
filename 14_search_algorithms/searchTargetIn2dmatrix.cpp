/* Search the ‘target’ value in a 2d integer matrix of dimensions n x m and
return 1 if found, else return 0. This matrix has the following properties:

Integers in each row are sorted from left to right.

The first integer of each row is greater than the last integer of the
previous row.

Input :
Matrix = [[1,3,5,7], [10,11,16,20], [23,30,34,60]],
target = 3

Output :
1 */

#include <iostream>
#include <vector>
using namespace std;

// Function to search for a target value in a 2D matrix
// The matrix is assumed to be sorted row-wise and column-wise
bool searchMatrix(vector<vector<int>> &a, int target) {
    int n = a.size();        // number of rows in the matrix
    int m = a[0].size();     // number of columns in the matrix

    // Treat the 2D matrix as a flattened 1D array
    int lo = 0, hi = n * m - 1;  // search space: from first element to last

    // Standard binary search loop
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;  // middle index (avoid overflow)
        
        // Convert 1D index 'mid' back into 2D coordinates (row, col)
        int x = mid / m;   // row index
        int y = mid % m;   // column index

        // Check if the middle element matches the target
        if (a[x][y] == target) {
            return true;   // target found
        } 
        // If target is greater, move to the right half
        else if (a[x][y] < target) {
            lo = mid + 1;
        } 
        // If target is smaller, move to the left half
        else {
            hi = mid - 1;
        }
    }

    // If loop ends, target was not found
    return false;
}

int main() {
    // Example matrix (sorted row-wise)
    vector<vector<int>> a = {
        {1, 3, 5, 7}, 
        {10, 11, 16, 20}, 
        {23, 30, 34, 60}
    };

    int target;  
    cout << "Enter the number you want to search: ";  
    cin >> target;   // user input for target value

    // Call the search function and print result
    if (searchMatrix(a, target)) {
        cout << "Target " << target << " found in matrix!" << endl;
    } else {
        cout << "Target " << target << " not found in matrix." << endl;
    }

    return 0;
}

