/* Given a binary string and an integer k,
return the maximum number of consecutive 1's in the string if you can flip at most k 0's.

Input : "0001101011", k = 2
Output: 7 */

/* Sliding Window is a technique where we use two pointers
to create a moving window over an array/string,
adjusting its size dynamically to satisfy a condition and
find the required result efficiently.*/

// Sliding Window Technique:
// We use two pointers (start and end) to maintain a window that contains
// at most k zeros. We expand the window by increasing 'end', and if the
// zero count becomes more than k, we shrink the window from the left by
// moving 'start'. The largest valid window gives the maximum consecutive 1s.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to find longest consecutive 1s with at most k flips
int longestOnes(string str, int k) {
    if(str.empty()) return 0;

    int start = 0;
    int zero_count = 0;
    int max_length = 0;

    for(int end = 0; end < str.size(); end++) {
        if(str[end] == '0') zero_count++;

        // Shrink window if zero_count exceeds k
        while(zero_count > k) {
            if(str[start] == '0') zero_count--;
            start++;
        }

        // Update max length of valid window
        max_length = max(max_length, end - start + 1);
    }

    return max_length;
}

int main() {
    string str;
    cout << "Enter binary string: ";
    cin >> str;

    int k;
    cout << "Enter max flips: ";
    cin >> k;

    cout << "Longest consecutive 1s (with flips): " << longestOnes(str, k) << endl;
    return 0;
}
