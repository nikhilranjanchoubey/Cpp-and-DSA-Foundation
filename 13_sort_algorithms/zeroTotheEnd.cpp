#include <iostream>
#include <vector>
using namespace std;

// Function to push all zeros to the end using bubble sort
void pushZerosToEnd(vector<int>& v) {
    int n = v.size();

    for (int i = n - 1; i >= 0; i--) {
        int j = 0;
        bool flag = false;
        while (j < i) {
            // If current is zero and next is non-zero, swap them
            if (v[j] == 0 && v[j + 1] != 0) {
                swap(v[j], v[j + 1]);
                flag = true;
            }
            j++; // Always increment j to avoid infinite loop
        }

        if(!flag) break;
    }

    return;
}

int main() {
    int n;

    // Input size
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);

    // Input elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Push zeros to end
    pushZerosToEnd(v);

    // Output result
    cout << "Array after pushing zeros to end: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}