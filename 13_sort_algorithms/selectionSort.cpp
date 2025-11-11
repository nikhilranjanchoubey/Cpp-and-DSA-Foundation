#include <iostream>
#include <vector>
using namespace std;

// Function to perform Selection Sort on the vector
void selectionsort(vector<int>& v) {
    int n = v.size();

    // Traverse the array from the beginning to the second-last element
    for (int i = 0; i < n - 1; i++) {

        // Assume the current index holds the minimum value
        int min_index = i;

        // Find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_index]) {
                min_index = j; // Update min_index if a smaller element is found
            }
        }

        // Swap the found minimum element with the element at current index
        if (i != min_index) {
            swap(v[i], v[min_index]);
        }
    }
    // No return value needed as the vector is modified in place
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

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}