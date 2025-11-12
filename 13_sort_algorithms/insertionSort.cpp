#include <iostream>
#include <vector>
using namespace std;

// Function to perform Insertion Sort 
void insertionSort(vector<int> &v) {
    int n = v.size();

    // Start from the second element (index 1) and move forward
    for (int i = 1; i < n; i++) {
        int current_ele = v[i]; // Element to be placed correctly

        // Find the correct position for current_ele in the sorted part of the array
        int j = i - 1;
        while (j >= 0 && v[j] > current_ele) {
            v[j + 1] = v[j]; // Shift larger elements one position to the right
            j--;
        }

        // Insert current_ele at its correct position
        v[j + 1] = current_ele;
    }
    // No return needed as the vector is modified in place
}

int main() {
    int n;

    // Input the number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);

    // Input the elements
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Sort the array using insertion sort
    insertionSort(v);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}