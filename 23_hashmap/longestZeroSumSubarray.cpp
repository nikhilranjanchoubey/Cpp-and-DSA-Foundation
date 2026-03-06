/* Given an array arr[] of length N,
find the length of the longest subarray with a sum equal to 0.

Input 1:
n = 8
arr[] = {15, -2, 2, -8, 1, 7, 10, 23}

Output 1:
5

Input 2:
n = 3
arr[] = {1, 2, 3}

Output 2:
0 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int maxLengthZeroSumSubarray(vector<int> &v)
{
    unordered_map<int, int> m; // stores prefixSum -> first index
    int prefixsum = 0;
    int maxlen = INT_MIN;

    for (int i = 0; i < v.size(); i++)
    {
        prefixsum += v[i];

        // Case 1: if prefix sum becomes 0
        if (prefixsum == 0)
        {
            maxlen = i + 1;
        }

        // Case 2: prefix sum already seen before
        if (m.find(prefixsum) != m.end())
        {

            int length = i - m[prefixsum];
            maxlen = max(maxlen, length);
        }

        // Store prefix sum first occurrence
        else
        {
            m[prefixsum] = i;
        }
    }

    return maxlen;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int result = maxLengthZeroSumSubarray(v);

    if (result == INT_MIN)
        cout << "No zero sum subarray found" << endl;
    else
        cout << "Length of longest zero sum subarray = " << result << endl;
}