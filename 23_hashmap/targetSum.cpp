/* Given an array of length n and a target,
return a pair whose sum is equal to the target.
If there is no pair present, return -1.

Input 1:
n = 7
Elements = [1, 4, 5, 11, 13, 10, 2]
Target = 13

Output 1:
[3, 6]

Input 2:
n = 5
Elements = [9, 10, 2, 3, 5]
Target = 15

Output 2:
[1, 4] */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Function: targetSumPair
Purpose : Find indices of two elements whose sum equals target
Logic   : Use HashMap to store element -> index
Time    : O(n)
*/

vector<int> targetSumPair(vector<int> &v, int targetsum)
{
    unordered_map<int, int> m; // stores value -> index
    vector<int> ans(2, -1);    // default answer if pair not found

    for (int i = 0; i < v.size(); i++)
    {

        int complement = targetsum - v[i];

        // Check if complement already exists in hashmap
        if (m.find(complement) != m.end())
        {

            cout << "Pair found: " << v[i] << " + " << complement
                 << " = " << targetsum << endl;

            ans[0] = m[complement]; // index of complement
            ans[1] = i;             // current index

            return ans;
        }

        // Store current value and its index
        m[v[i]] = i;
    }

    cout << "No pair found whose sum equals " << targetsum << endl;
    return ans;
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

    int targetsum;
    cout << "Enter target sum: ";
    cin >> targetsum;

    // Calling function
    vector<int> ans = targetSumPair(v, targetsum);

    // Printing result
    if (ans[0] == -1)
    {
        cout << "Output: -1 (No valid pair exists)" << endl;
    }
    else
    {
        cout << "Indices of elements whose sum equals target: ";
        cout << ans[0] << ", " << ans[1] << endl;
    }

    return 0;
}