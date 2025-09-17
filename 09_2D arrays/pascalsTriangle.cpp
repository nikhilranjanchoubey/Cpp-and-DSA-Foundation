/*Given an integer n, return the first n rows of Pascal's triangle.*/

#include<iostream>
#include<vector>
using namespace std;

// Function to generate Pascal's Triangle up to n rows
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> pascal(n); // Outer vector to hold all rows

    for (int i = 0; i < n; i++) {
        pascal[i].resize(i + 1); // Resize current row to hold i+1 elements

        for (int j = 0; j <= i; j++) {
            // First and last elements of each row are always 1
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            } else {
                // Each middle element is sum of two elements above it
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }

    return pascal;
}

int main() {
    int n;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> n;

    vector<vector<int>> ans = pascalTriangle(n);

    // Print the triangle row by row
    for (const auto& row : ans) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}