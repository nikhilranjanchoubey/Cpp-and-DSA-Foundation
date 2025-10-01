#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Space used: array of size n
    int arr[n];  // O(n) space

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // storing input
    }

    int sum = 0;  // O(1) space
    for (int i = 0; i < n; i++) {
        sum += arr[i];  // summing elements
    }

    cout << "Sum = " << sum << endl;
    return 0;
}