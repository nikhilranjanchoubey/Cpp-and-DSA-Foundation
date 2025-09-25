/*Given a positive integer n, generate an nxn matrix
filled with elements from 1 to n2 in spiral order.*/

#include <iostream>
#include <vector>
using namespace std;

// Function to generate an n x n matrix filled in spiral order
vector<vector<int>> createSpiralMatrix(int n) {
    // Initialize an empty n x n matrix with zeros
    vector<vector<int>> matrix(n, vector<int>(n));

    // Define boundaries
    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = n - 1;

    int direction = 0; // 0 → right, 1 ↓, 2 ←, 3 ↑
    int value = 1;     // Start filling from 1 to n^2

    while (left <= right && top <= bottom) {
        if (direction == 0) {
            // Traverse Left → Right
            for (int i = left; i <= right; i++) {
                matrix[top][i] = value++;
            }
            top++;
        }
        else if (direction == 1) {
            // Traverse Top → Bottom
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = value++;
            }
            right--;
        }
        else if (direction == 2) {
            // Traverse Right → Left
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value++;
            }
            bottom--;
        }
        else {
            // Traverse Bottom → Top
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }

        // Cycle direction: 0 → 1 → 2 → 3 → 0 ...
        direction = (direction + 1) % 4;
    }

    return matrix;
}

int main() {
    int n;

    // Input matrix size
    cout << "Enter the size of the matrix (n): ";
    cin >> n;

    // Generate spiral matrix
    vector<vector<int>> matrix = createSpiralMatrix(n);

    // Display the matrix
    cout << "\nSpiral Matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}