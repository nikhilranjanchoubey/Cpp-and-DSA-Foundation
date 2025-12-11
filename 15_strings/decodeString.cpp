/* An encoded string (s) is given, and the task is to decode it.
The encoding pattern is that the occurrence of the string is given at the starting of the string
and each string is enclosed by square brackets.

Note: The occurrence of a single string is less than 1000.

Input: s = 1[b]
Output: b

Input: s = 3[b2[ca]]
Output: bcacabcacabcaca */

#include <iostream>
#include <string>
#include <algorithm> // for reverse
using namespace std;

// Function to decode the encoded string
string decodedString(string s)
{
    string result = ""; // acts like a stack to store characters

    // Traverse the encoded string
    for (int i = 0; i < s.length(); i++)
    {

        // If current character is not ']', push it into result
        if (s[i] != ']')
        {
            result.push_back(s[i]);
        }
        else
        {
            // Step 1: Extract the substring inside brackets
            string str = "";
            while (!result.empty() && result.back() != '[')
            {
                str.push_back(result.back());
                result.pop_back();
            }

            // Reverse because we extracted in reverse order
            reverse(str.begin(), str.end());

            // Step 2: Remove the '[' from result
            result.pop_back();

            // Step 3: Extract the number before '['
            string num = "";
            while (!result.empty() && isdigit(result.back()))
            {
                num.push_back(result.back());
                result.pop_back();
            }

            // Reverse the number string
            reverse(num.begin(), num.end());

            // Convert number string to integer
            int n = stoi(num); // stoi converts a numeric string (e.g. "23") into an integer (23)

            // Step 4: Repeat the substring 'n' times and append to result
            while (n--)
            {
                result += str;
            }
        }
    }

    return result;
}

int main()
{
    string str;
    cout << "Enter encoded string: ";
    cin >> str;

    cout << "Decoded string: " << decodedString(str) << endl;

    return 0;
}

// for i = 0 to i < s.length():

//     if (s[i] != ']')
//         insert into result

//     else
//     {
//         1) Extract str from result till '[' found
//         2) Reverse str
//         3) Remove last char
//         4) Extract digit/num from result
//            till s[i] >= '0' && <= '9'
//         5) Reverse num
//         6) Convert num string to int
//         7) Insert str in result, int-num times
//     }
