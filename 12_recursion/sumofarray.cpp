 #include <iostream>
using namespace std;

// Function to calculate the sum of array elements recursively
int sumArray(int idx, int n, int arr[]) {
    // Base case: if we're at the last element(array has only one element), return it
    if (idx == n - 1) {
        return arr[idx];
    }

    // Recursive call: sum of current + sum of rest
    int sumRest = sumArray(idx + 1, n, arr);
    return arr[idx] + sumRest;
}

int main() {
    int n;

    // Enter array size
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Input array elements
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find the sum
    int totalSum = sumArray(0, n, arr);

    // Output
    cout << "Sum of array elements is: " << totalSum << endl;

    return 0;
}