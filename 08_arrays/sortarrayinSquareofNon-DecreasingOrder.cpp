// Given an integer array 'a' sorted in non-decreasing order,
// Return an array of the square of each number sorted in non-decreasing order.

#include<iostream>
#include<vector>
using namespace std;

// Function to return sorted squares of a sorted array
vector<int> sortedSquares(const vector<int> &a) {
    int n = a.size();
    vector<int> result(n); // Output array
    int left = 0;
    int right = n - 1;
    int index = n - 1; // Start filling from the end

    // Compare absolute values from both ends
    while (left <= right) {
        int leftSquare = a[left] * a[left];
        int rightSquare = a[right] * a[right];

        if (leftSquare > rightSquare) {
            result[index--] = leftSquare;
            left++;
        } else {
            result[index--] = rightSquare;
            right--;
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a;
    cout << "Enter " << n << " sorted integers: ";
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        a.push_back(ele);
    }

    // Display original array
    cout << "Original array: ";
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    // Get sorted squares
    vector<int> squared = sortedSquares(a);

    // Display result
    cout << "Sorted squares: ";
    for (int num : squared) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}