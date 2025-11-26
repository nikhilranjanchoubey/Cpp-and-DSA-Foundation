/* Given a mountain array ‘a’ of length greater than 3, return the index ‘i’
such that arr[0] < arr[1] < … < arr[i - 1] < arr[i] > arr[i + 1] > … > arr[arr.length - 1].
This index is known as the peak index.

Input :
Array = [0, 4, 1, 0]

Output :
1 */

#include <iostream>
#include <vector>
using namespace std;

// Function to find peak index in a mountain array
int peakInMountainArray(vector<int> &input) {
    int lo = 0, hi = input.size() - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (input[mid] < input[mid + 1]) {
            // Peak lies to the right
            lo = mid + 1;
        } else {
            // Peak lies to the left or at mid
            hi = mid;
        }
    }

    return lo; // lo == hi at the peak index
}

int main() {
    vector<int> input = {0, 2, 4, 3, 0, -1};
    cout << "Peak index: " << peakInMountainArray(input) << '\n';
    cout << "Peak value: " << input[peakInMountainArray(input)] << '\n';
    return 0;
}

