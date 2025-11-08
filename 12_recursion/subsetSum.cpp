#include<iostream>
#include<vector>
using namespace std;

/*
 * Function: generateSubsetSums
 * ----------------------------
 * Recursively generates all possible subset sums from the array.
 *
 * Parameters:
 * - arr: pointer to the input array
 * - size: total number of elements in the array
 * - index: current index being considered
 * - currentSum: sum accumulated so far
 * - result: vector to store all subset sums
 */
void generateSubsetSums(int *arr, int size, int index, int currentSum, vector<int> &result) {
    // Base case: if we've considered all elements
    if (index == size) {
        result.push_back(currentSum);
        return;
    }

    // Include current element in the sum
    generateSubsetSums(arr, size, index + 1, currentSum + arr[index], result);

    // Exclude current element from the sum
    generateSubsetSums(arr, size, index + 1, currentSum, result);
}

int main() {
    int arr[] = {2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> subsetSums;

    // Generate all subset sums
    generateSubsetSums(arr, size, 0, 0, subsetSums);

    // Print the result
    cout << "Subset sums: ";
    for (int sum : subsetSums) {
        cout << sum << " ";
    }

    return 0;
}