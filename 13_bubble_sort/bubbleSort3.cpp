#include <iostream>
#include <vector>
using namespace std;

// Optimized Bubble Sort function with early exit using a flag
void bubbleSort(vector<int>& v) {
    int n = v.size();
    bool flag;  // Flag to check if any swaps occurred

    // Outer loop for each pass
    for(int i = 0; i < n - 1; i++) {
        flag = false;  // Assume no swaps this pass

        // Inner loop for comparing adjacent elements
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                flag = true;  // Swap occurred
            }
        }

        // If no swaps occurred, array is already sorted
        if(!flag) {
            break;
        }
    }
}

int main() {
    int n;

    // Enter number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    // Declare vector of size n
    vector<int> v(n);

    // Input elements from user
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Call optimized bubble sort
    bubbleSort(v);

    // Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}