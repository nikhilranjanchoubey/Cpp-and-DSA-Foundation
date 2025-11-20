/* Given two sorted arrays,
Write a program to merge them in a sorted Manner.

Input:
num1[] = { 5, 8, 10 },
num2[] = { 2, 7, 8 }

Output:
num3[] = { 2, 5, 7, 8, 8, 10 } */

#include <iostream>
using namespace std;

// Function to merge two sorted arrays into a third sorted array
void merge(int arr1[], int n1, int arr2[], int n2, int arr3[]) {
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2
    int k = 0; // Pointer for arr3

    // Merge elements from both arrays in sorted order
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1 (if any)
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2 (if any)
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {5, 8, 10, 11, 12};
    int arr2[] = {2, 7, 8};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int n3 = n1 + n2;
    int arr3[n3]; // Resultant merged array

    merge(arr1, n1, arr2, n2, arr3);

    cout << "Merged sorted array: ";
    for (int i = 0; i < n3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}