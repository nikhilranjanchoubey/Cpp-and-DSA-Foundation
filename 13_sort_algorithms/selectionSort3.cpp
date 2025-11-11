#include <iostream>
#include <vector>
using namespace std;

// Selection Sort: placing maximum element at the end in each pass
void selectionsort(vector<int>& v) {
    int n = v.size();

    // Traverse the array from end to beginning
    for (int i = n - 1; i > 0; i--) {

        // Assume the first element is the maximum
        int max_index = 0;

        // Find the index of the maximum element in the unsorted part
        for (int j = 1; j <= i; j++) {
            if (v[j] > v[max_index]) {
                max_index = j;
            }
        }

        // Swap the maximum element with the element at current end position
        if (max_index != i) {
            swap(v[i], v[max_index]);
        }
    }
    // Vector is now sorted 
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

    // Sort the array using selection sort (max to end)
    selectionsort(v);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}