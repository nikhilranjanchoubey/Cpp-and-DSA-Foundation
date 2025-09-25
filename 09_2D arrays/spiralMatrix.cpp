/*Given an nxm matrix 'a',return all elements of the matrix in spiral order.*/

#include <iostream>
#include <vector>
using namespace std;

// Function to print matrix elements in spiral order
void spiralOrder(const vector<vector<int>>& matrix) {
    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    int direction = 0;

    cout << "\nMatrix in Spiral Order:\n";

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            // Traverse Left → Right
            for (int col = left; col <= right; col++) {
                cout << matrix[top][col] << " ";
            }
            top++;
        }
        else if (direction == 1) {
            // Traverse Top → Bottom
            for (int row = top; row <= bottom; row++) {
                cout << matrix[row][right] << " ";
            }
            right--;
        }
        else if (direction == 2) {
            // Traverse Right → Left
            for (int col = right; col >= left; col--) {
                cout << matrix[bottom][col] << " ";
            }
            bottom--;
        }
        else {
            // Traverse Bottom → Top
            for (int row = bottom; row >= top; row--) {
                cout << matrix[row][left] << " ";
            }
            left++;
        }

        // Cycle direction: 0 → 1 → 2 → 3 → 0 ...
        direction = (direction + 1) % 4;
    }

    cout << endl;
}

int main() {
    int n, m;

    // Input matrix dimensions
    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;

    // Declare and input matrix
    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter elements of the matrix (" << n << "x" << m << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // Call function to print spiral order
    spiralOrder(matrix);

    return 0;
}
