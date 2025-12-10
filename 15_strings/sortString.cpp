/* Given a string str, sort the given string.

Constraints: The string will contain only alphabetical characters from a–z.

Input 1: "codingwallah"
Output 1: "aacdghillnow"

Input 2: "star"
Output 2: "arst" */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to sort a string using counting sort
string countSort(string str)
{
    // Step 1: Create a frequency array of size 26 (for 'a' to 'z')
    vector<int> freq(26, 0);

    // Step 2: Count frequency of each character in the string
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a'; // Convert character to index (0 for 'a', 1 for 'b', etc.)
        freq[index]++;            // Increment frequency of that character
    }

    // Step 3: Build the sorted string using the frequency array
    int j = 0;                   // Pointer to place characters back into the string
    for (int i = 0; i < 26; i++) // Traverse all possible characters from 'a' to 'z'
    {
        while (freq[i] > 0) // If character i exists in the string
        {
            str[j++] = i + 'a'; // Place the character back into the string
            freq[i]--;          // Decrease its frequency
        }
    }

    // Step 4: Return the sorted string
    return str;
}

int main()
{
    string str;

    // Input: Read a string from the user
    cout << "Enter a string (only lowercase letters a-z): ";
    cin >> str;

    // Output: Print the sorted string
    cout << "Sorted string: " << countSort(str) << endl;

    return 0;
}