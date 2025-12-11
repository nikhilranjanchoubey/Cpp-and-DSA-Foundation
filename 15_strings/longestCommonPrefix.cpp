/* Given an array of strings.
Find the longest common prefix string amongst an array of strings.

Input: arr = [“flower”,“flight”,“flask”]
Output: “fl” */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // required for sort
using namespace std;

// Function to find the longest common prefix
string LongestCommonPrefix(vector<string> &str)
{
    // Step 1: Sort the array of strings
    sort(str.begin(), str.end());

    // Step 2: Take the first and last string after sorting
    string s1 = str[0];                  // first string
    string s2 = str[str.size() - 1];     // last string

    string ans = "";
    int i = 0, j = 0;

    // Step 3: Compare characters of s1 and s2
    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] == s2[j])
        {
            ans += s1[i]; // add matching character to answer
            i++;
            j++;
        }
        else
        {
            break; // stop when mismatch occurs
        }
    }

    // Step 4: Return the longest common prefix
    return ans;
}

int main()
{
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    cout << "Enter strings: ";
    vector<string> str(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    // Output the result
    string result = LongestCommonPrefix(str);
    if (result.empty())
        cout << "No common prefix found." << endl;
    else
        cout << "Longest common prefix: " << result << endl;

    return 0;
}