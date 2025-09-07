// Rotate the given array 'a' by k steps,
// where k is non-negative.
// Note: k can be greater than n as well 
// where n is the size of array 'a'.

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

int main() {
    vector<int> array = {1, 2, 3, 4, 5};
    int n = array.size();
    int k = 2;

    // Normalize k to avoid overflow
    k = k % n;

    //Reverse the entire array
    reverse(array.begin(), array.end()); // [5, 4, 3, 2, 1]

    //Reverse the first 'k' elements
    reverse(array.begin(), array.begin() + k); // [4, 5, 3, 2, 1]

    //Reverse the remaining 'n-k' elements
    reverse(array.begin() + k, array.end()); // [4, 5, 1, 2, 3]

    // Print the rotated array
    cout << "Rotated array: ";
    for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}