//Sort an Array cosisting of only 0s and 1s.

#include<iostream>
#include<vector>
using namespace std;

// Function to sort the array containing only 0s and 1s using two-pointer approach
void sortZerosAndOnes(vector<int> &v) {
    int left_ptr = 0;
    int right_ptr = v.size() - 1;

    // Loop until the two pointers meet
    while (left_ptr < right_ptr) {
        // If left is 1 and right is 0, swap them
        if (v[left_ptr] == 1 && v[right_ptr] == 0) {
            v[left_ptr++] = 0;
            v[right_ptr--] = 1;
        }

        // If left is already 0, move left pointer forward
        if (v[left_ptr] == 0) {
            left_ptr++;
        }

        // If right is already 1, move right pointer backward
        if (v[right_ptr] == 1) {
            right_ptr--;
        }
    }
}

// Main function to drive the program
int main() {
    int n;

    // Input: Size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v;

    // Input: Array elements (only 0s and 1s)
    cout << "Enter " << n << " elements (only 0s and 1s): ";
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    // Display array before sorting
    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Call the sorting function
    sortZerosAndOnes(v);

    // Display array after sorting
    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}