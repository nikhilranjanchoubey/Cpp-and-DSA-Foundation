/* Check whether two Strings are isomorphic of each other.
Return true if they are else return false.

Two strings are isomorphic of each other if there is a one-to-one mapping
possible for every character of the first string to every character of second string
and all occurrences of every character in first string maps to the same character in the second string.

Input 1:
aab
xxy

Output 1:
True

Input 2:
abcdec
viouog

Output 2:
False */

#include <iostream>
#include <unordered_map>
using namespace std;

bool checkNoOneToManyMapping(string s1, string s2)
{
    // Hashmap to store mapping from s1 -> s2
    unordered_map<char, char> m;

    for (int i = 0; i < s1.length(); i++)
    {

        // If character already mapped earlier
        if (m.find(s1[i]) != m.end())
        {

            // If existing mapping does not match current mapping
            if (m[s1[i]] != s2[i])
            {
                cout << "Conflict: '" << s1[i] << "' cannot map to both '"
                     << m[s1[i]] << "' and '" << s2[i] << "'" << endl;
                return false;
            }
        }

        // If character not mapped yet, create mapping
        else
        {
            m[s1[i]] = s2[i];
        }
    }

    return true;
}

/*
Main function that checks if two strings are isomorphic
*/

bool checkIsomorphic(string s1, string s2)
{
    // Step 1: Length check
    if (s1.length() != s2.length())
    {
        cout << "Strings have different lengths → Not Isomorphic" << endl;
        return false;
    }

    // Step 2: Check mapping from s1 → s2
    bool s1s2 = checkNoOneToManyMapping(s1, s2);

    // Step 3: Check mapping from s2 → s1
    bool s2s1 = checkNoOneToManyMapping(s2, s1);

    // Step 4: Both mappings must be valid
    return s1s2 && s2s1;
}

int main()
{
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    if (checkIsomorphic(s1, s2))
        cout << "Strings are Isomorphic" << endl;
    else
        cout << "Strings are NOT Isomorphic" << endl;
}