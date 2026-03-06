/* Given an array of strings.
You can move any number of characters from one string to any other string any number of times.
You just have to make all of them equal.
Print "Yes" if you can make every string in the array equal by using any number of operations otherwise print "No".

Input: ["collegeee", "coll", "collegge"]
Output: Yes
Explanation: string at 1 index can take two ‘e’ from 0 index string and one ‘g’ from 2 index string.

Input: ["wall", "ah", "wallahah"]
Output: No
Explanation: Here we don't have enough number of characters to make all strings equal. */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to check whether all strings can be made equal
bool canMakeEqual(vector<string> &v)
{
    // Hashmap to store frequency of each character
    unordered_map<char, int> m;

    // Count frequency of every character from all strings
    for (auto str : v)
    {
        for (char c : str)
        {
            m[c]++; // increase count of character
        }
    }

    // Total number of strings
    int n = v.size();

    // Check if each character frequency is divisible by number of strings
    for (auto ele : m)
    {
        if (ele.second % n != 0)
        {
            // If not divisible, equal distribution is impossible
            cout << "Character '" << ele.first << "' cannot be equally distributed among all strings." << endl;
            return false;
        }
    }

    // If all characters can be equally distributed
    return true;
}

int main()
{
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> v(n);

    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // Calling function
    if (canMakeEqual(v))
    {
        cout << "Yes - All strings can be made equal." << endl;
    }
    else
    {
        cout << "No - Strings cannot be made equal." << endl;
    }

    return 0;
}