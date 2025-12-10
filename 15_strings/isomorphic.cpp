/* Given two strings s and t, Determine if they are isomorphic.

Input: s = 'egg', t = 'add'
Output: yes */

/*
Isomorphic Strings:
Two strings s and t are called isomorphic if each character in s can be
mapped to a unique character in t, such that the pattern of characters
remains the same in both strings.
Characters can be different, but their pattern must match.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to check if two strings are isomorphic
bool isIsomorphic(string s1, string s2)
{
    // Step 1: If lengths differ, they cannot be isomorphic
    if (s1.size() != s2.size())
        return false;

    // Step 2: Create two arrays to track last occurrence index of characters
    // v1 for s1 characters, v2 for s2 characters
    vector<int> v1(128, -1); // ASCII size 128
    vector<int> v2(128, -1);

    // Step 3: Traverse both strings simultaneously
    for (int i = 0; i < s1.size(); i++)
    {
        // If last occurrence index does not match, mapping is inconsistent
        if (v1[s1[i]] != v2[s2[i]])
            return false;

        // Update last occurrence index for both characters
        v1[s1[i]] = v2[s2[i]] = i;
    }

    // Step 4: If no mismatch found, strings are isomorphic
    return true;
}

int main()
{
    string s1, s2;

    // Input: Read two strings
    cout << "Enter two strings: ";
    cin >> s1 >> s2;

    // Output: Display result
    if (isIsomorphic(s1, s2))
        cout << "they are isomorphic" << endl;
    else
        cout << "they are not isomorphic" << endl;

    return 0;
}
