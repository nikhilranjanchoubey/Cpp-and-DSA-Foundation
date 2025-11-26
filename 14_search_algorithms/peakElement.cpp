/* A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is
always considered to be strictly greater than a neighbor that is outside the array.

Input :
Array = [1, 2, 1, 2, 6, 10, 3]

Output :
Either index 1 or index 5 are the correct output.
At index 1, 2 is the peak element and at index 5, 10 is the peak element. */

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> &input) {
    int n = input.size();
    int lo = 0, hi = n - 1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(mid == 0) {
            if(input[mid] > input[mid+1]) {
                return 0;
            } else {
                return 1;
            }
        }
        else if(mid == n -1) {
            if(input[mid] > input[mid - 1]) {
                return n - 1;
            } else {
                return n - 2;
            }
        }
        else {
            if(input[mid] > input[mid+1] and input[mid] > input[mid-1]) {
                return mid;
            } else if(input[mid] > input[mid-1]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> input;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements of array: ";
    while(n--) {
        int x;
        cin >> x;
        input.push_back(x);
    }
    cout << "Peak Element is "<< findPeak(input) << '\n';
    return 0;
}
