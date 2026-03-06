/* Check whether two Strings are anagram of each other.
Return true if they are else return false.

An anagram of a string is another string
that contains the same characters,
only the order of characters can be different.
For example, "abcd" and "dabc" are an anagram of each other.

Input 1:
triangle
integral

Output 1:
True

Input 2:
anagram
grams

Output 2:
False */

#include <iostream>
#include <unordered_map>
using namespace std;

// Function to check if two strings are anagrams
bool checkAnagram(string s1, string s2)
{
    // If lengths are different, they cannot be anagrams
    if (s1.length() != s2.length())
    {
        cout << "Strings have different lengths, so they cannot be anagrams." << endl;
        return false;
    }

    // Hashmap to store frequency of characters
    unordered_map<char, int> m;

    // Count frequency of characters in first string
    for (char c : s1)
    {
        m[c]++;
    }

    // Reduce frequency using second string
    for (char c : s2)
    {
        m[c]--;
    }

    // Check if all frequencies became zero
    for (auto ele : m)
    {
        if (ele.second != 0)
        {
            cout << "Character frequency mismatch found." << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    // Function call
    if (checkAnagram(s1, s2))
    {
        cout << "True - The strings are anagrams." << endl;
    }
    else
    {
        cout << "False - The strings are not anagrams." << endl;
    }

    return 0;
}