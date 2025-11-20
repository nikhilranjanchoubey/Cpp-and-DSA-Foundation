#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search on a sorted vector
int binarySearch(const vector<int> &input, int target) {
    int lo = 0;                      // Start of search space
    int hi = input.size() - 1;       // End of search space

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Prevents potential overflow

        if (input[mid] == target) {
            return mid; // Target found at index mid
        } else if (input[mid] < target) {
            lo = mid + 1; // Discard left half
        } else {
            hi = mid - 1; // Discard right half
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> input {2, 4, 5, 7, 15, 24, 45, 50};
    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    int index = binarySearch(input, target);

    if (index != -1)
        cout << "Element " << target << " found at index " << index << ".\n";
    else
        cout << "Element " << target << " not found in the array.\n";

    return 0;
}