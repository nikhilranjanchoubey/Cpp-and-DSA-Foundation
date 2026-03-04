/* Check if string has all English alphabets

Given a string.
You have to check if it has all English alphabets from a–z.

Input 1:
abcdEfGHIJKLMnopqrstuvWXYZ

Output 1:
Yes

Input 2:
PhysicsWallah

Output 2:
No

Explanation:
Input-1 has all the alphabets irrespective of upper or lower case, so the output is Yes.
But in case of Input-2, it doesn’t contain all the alphabets, hence No. */

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool checkAllAlphabets(string s)
{
    if (s.length() < 26)
    {
        return false;
    }

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    set<char> alphabets;
    for (auto ch : s)
    {
        alphabets.insert(ch);
    }
    return (alphabets.size() == 26);
}

int main()
{

    string input;
    cout << "Enter String: ";
    cin >> input;

    if (checkAllAlphabets(input))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}