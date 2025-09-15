/*Given a vector arr[] sorted in increasing order.
Return an array of squares of each number sorted in increasing order.
Where size of vector 1<size<101.*/

#include<iostream>
using namespace std;

int main() {
    int arr[] = {-4, -3, -1, 0, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result[n];
    int i = 0, j = n - 1, k = n - 1;

    // Fill result[] from end to start
    while (i <= j && k >= 0) {
        if (abs(arr[i]) > abs(arr[j])) {
            result[k] = arr[i] * arr[i];
            i++;
            k--;
        } else {
            result[k] = arr[j] * arr[j];
            j--;
            k--;
        }
    }

    // Print the sorted squares
    cout << "Sorted squares: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}