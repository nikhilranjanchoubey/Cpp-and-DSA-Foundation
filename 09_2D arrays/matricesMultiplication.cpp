/*Write a program to display multiplication of two matrices entered by the user.*/

#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    // Input dimensions for Matrix 1
    cout << "Enter the number of rows of Matrix 1: ";
    cin >> r1;
    cout << "Enter the number of columns of Matrix 1: ";
    cin >> c1;

    // Input dimensions for Matrix 2
    cout << "Enter the number of rows of Matrix 2: ";
    cin >> r2;
    cout << "Enter the number of columns of Matrix 2: ";
    cin >> c2;

    // Check if multiplication is possible
    if (c1 != r2) {
        cout << "\nMatrix multiplication not possible.";
        return 0;
    }

    int array1[r1][c1];
    int array2[r2][c2];
    int result[r1][c2]; // Resultant matrix dimensions: r1 × c2

    // Input elements of Matrix 1
    cout << "\nEnter elements of Matrix 1:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> array1[i][j];
        }
    }

    // Input elements of Matrix 2
    cout << "\nEnter elements of Matrix 2:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> array2[i][j];
        }
    }

    // Initialize result matrix to zero
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication logic
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }

    // Display the result matrix
    cout << "\nResultant Matrix after multiplication:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}