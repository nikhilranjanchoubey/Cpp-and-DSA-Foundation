#include <iostream>
#include <vector>
using namespace std;

// Function to perform Selection Sort in descending order
void selectionsort(vector<int>& v) {
    int n = v.size();

    // Traverse the array from beginning to second-last element
    for (int i = 0; i < n - 1; i++) {

        // Assume the current index holds the maximum value
        int max_index = i;

        // Find the index of the maximum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (v[j] > v[max_index]) {
                max_index = j; // Update max_index if a larger element is found
            }
        }

        // Swap the found maximum element with the element at current index
        if (i != max_index) {
            swap(v[i], v[max_index]);
        }
    }
    // No return needed as vector is modified in place
}

int main() {
    int n;

    // Input the number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);

    // Input the elements of the array
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call the selection sort function
    selectionsort(v);

    // Output the sorted array in descending order
    cout << "Sorted array (descending): ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}