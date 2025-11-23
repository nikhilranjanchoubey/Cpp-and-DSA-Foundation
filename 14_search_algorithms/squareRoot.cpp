/* Find the square root of the given non negative value x.
Round it off to the nearest floor integer value.

Input: x = 4
Output: 2

Input: x = 11
Output: 3 */

#include <iostream>
using namespace std;

// Function to compute the integer square root of x
// (largest integer y such that y*y <= x)
int integerSqrt(int x) {
    /* Complexity:-
       Time: o(logn)
       Space: o(1)*/
    int lo = 1, hi = x;
    int ans = 0; // Default answer

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; 

        if (mid * mid <= x) {
            ans = mid;       // mid is a valid candidate
            lo = mid + 1;    // Try to find a larger one
        } else {
            hi = mid - 1;    // mid*mid > x, reduce search space
        }
    }

    return ans;
}

int main() {
    int num = 40;
    cout << "Integer square root of " << num << " is " << integerSqrt(num) << endl;
    return 0;
}