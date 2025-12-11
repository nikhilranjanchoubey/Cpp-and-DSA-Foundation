/* Given an array of strings.
Find the longest common prefix string amongst an array of strings.

Input: arr = [“flower”,“flight”,“flask”]
Output: “fl” */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // required for sort
using namespace std;

// // Function to find the longest common prefix
// string LongestCommonPrefix(vector<string> &str)
// {
//     // Step 1: Sort the array of strings
//     sort(str.begin(), str.end());

//     // Step 2: Take the first and last string after sorting
//     string s1 = str[0];              // first string
//     string s2 = str[str.size() - 1]; // last string

//     string ans = "";
//     int i = 0, j = 0;

//     // Step 3: Compare characters of s1 and s2
//     while (i < s1.size() && j < s2.size())
//     {
//         if (s1[i] == s2[j])
//         {
//             ans += s1[i]; // add matching character to answer
//             i++;
//             j++;
//         }
//         else
//         {
//             break; // stop when mismatch occurs
//         }
//     }

//     // Step 4: Return the longest common prefix
//     return ans;
// }

// Function to find the longest common prefix among given strings
string LongestCommonPrefix(vector<string> &str)
{

    // Step 1: Take the first string as reference
    string s1 = str[0];
    int ans_length = s1.size(); // initially assume full length of s1 is the prefix

    // Step 2: Compare s1 with every other string
    for (int i = 1; i < str.size(); i++)
    {

        int j = 0;
        // Step 3: Compare characters of s1 and str[i] until mismatch
        while (j < s1.size() && j < str[i].size() && s1[j] == str[i][j])
        {
            j++;
        }

        // Step 4: Update the length of the common prefix found so far
        ans_length = min(ans_length, j);
    }

    // Step 5: Extract the prefix substring from s1
    string ans = s1.substr(0, ans_length);
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