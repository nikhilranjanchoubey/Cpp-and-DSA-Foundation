// Given an array of integers 'a',
// Move all the Even integers at the beginning of the array followed by all the Odd integers.
// The relative order of odd or even integers does not matter.
// Return any array that satisfies the condition.

#include<iostream>
#include<vector>
using namespace std;

// Function to rearrange array: evens first, then odds
void segregateEvenOdd(vector<int> &v) {
    int left_ptr = 0;
    int right_ptr = v.size() - 1;

    // Loop until pointers meet
    while (left_ptr < right_ptr) {
        // If left is odd and right is even, swap them
        if (v[left_ptr] % 2 != 0 && v[right_ptr] % 2 == 0) {
            swap(v[left_ptr], v[right_ptr]);
            left_ptr++;
            right_ptr--;
        }

        // If left is already even, move forward
        if (v[left_ptr] % 2 == 0) {
            left_ptr++;
        }

        // If right is already odd, move backward
        if (v[right_ptr] % 2 != 0) {
            right_ptr--;
        }
    }
}

int main() {
    int n;

    // Input: Size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v;

    // Input: Array elements (any integers)
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    // Display array before rearrangement
    cout << "Before rearrangement: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Call the rearrangement function
    segregateEvenOdd(v);

    // Display array after rearrangement
    cout << "After rearrangement (evens first): ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}