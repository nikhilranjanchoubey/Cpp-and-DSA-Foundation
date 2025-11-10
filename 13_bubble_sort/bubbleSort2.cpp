#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort function to sort the vector in descending order
void bubbleSortDescending(vector<int>& v) {
    int n = v.size();

    // Outer loop for each pass
    for(int i = 0; i < n - 1; i++) {
        // Inner loop for comparing adjacent elements
        for(int j = 0; j < n - i - 1; j++) {
            // Swap if the left element is smaller than the right
            if(v[j] < v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
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

    // Call bubble sort 
    bubbleSortDescending(v);

    // Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}