// Given an integer array 'a' sorted in non-decreasing order,
// Return an array of the square of each number sorted in non-decreasing order.

#include<iostream>
#include<vector>
#include<cmath> // for abs()
using namespace std;

// Function to compute sorted squares of a sorted array
vector<int> sortedSquaredArray(const vector<int> &v) {
    vector<int> ans(v.size());

    int left_ptr = 0;
    int right_ptr = v.size() - 1;
    int index = v.size() - 1;

    // Fill ans[] from the end with largest squares first
    while (left_ptr <= right_ptr) {
        if (abs(v[left_ptr]) < abs(v[right_ptr])) {
            ans[index--] = v[right_ptr] * v[right_ptr];
            right_ptr--;
        } else {
            ans[index--] = v[left_ptr] * v[left_ptr];
            left_ptr++;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v;
    cout << "Enter " << n << " sorted integers: ";
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    // Get the sorted squares
    vector<int> ans = sortedSquaredArray(v);

    // Print the result
    cout << "Sorted squares: ";
    for (int i = 0; i < v.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}