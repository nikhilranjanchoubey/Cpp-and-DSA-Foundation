/* Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Constraints: String s and t will only contain lowercase alphabetical characters.

Input 1: s = "anagram", t = "nagaram"
Output 1: yes

Input 2: s = "bank", t = "atm"
Output 2: no */

/* An anagram means:
A word or phrase formed by rearranging the letters of another word or phrase, using all letters exactly once.

Examples:
"listen" → "silent"
"anagram" → "nagaram"
"army" → "mary"

Not anagrams:
"bank" and "atm" → letters don’t match
"cat" and "taco" → different number of letters */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to check if two strings are anagrams
bool isAnagram(string s1, string s2)
{
    // Step 1: If lengths differ, they cannot be anagrams
    if (s1.length() != s2.length())
    {
        return false;
    }

    // Step 2: Create a frequency array for 26 lowercase letters
    vector<int> freq(26, 0);

    // Step 3: Traverse both strings simultaneously
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++; // increment count for s1 character
        freq[s2[i] - 'a']--; // decrement count for s2 character
    }

    // Step 4: If all frequencies are zero, strings are anagrams
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return false; // mismatch found
        }
    }

    return true; // all matched
}

int main()
{
    string s1, s2;

    // Input: Read two strings
    cout << "Enter two strings (lowercase only): ";
    cin >> s1 >> s2;

    // Output: Check and display result
    if (isAnagram(s1, s2))
    {
        cout << "yes" << endl; // matches problem statement output
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}