#include<iostream>
using namespace std;

// Function to find the first and last index of a character in a string
// Uses pointers to update 'first' and 'last' directly in memory
void findfirstAndlastIndex(string s, char ch, int *first, int *last) {
    
    // Loop from start to find the first occurrence
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ch) {
            *first = i;  // Dereference pointer to update actual 'first' variable
            break;       // Stop after finding the first match
        }
    }

    // Loop from end to find the last occurrence
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == ch) {
            *last = i;   // Dereference pointer to update actual 'last' variable
            break;       // Stop after finding the last match
        }
    }
}

int main() {
    string s = "aaabac";   // Input string
    char ch = 'a';         // Character to search for

    int first = -1;        // Initialize first index to -1 (not found)
    int last = -1;         // Initialize last index to -1 (not found)

    int *pf = &first;      // Pointer to 'first'
    int *pl = &last;       // Pointer to 'last'

    // Call function with pointers to update 'first' and 'last'
    findfirstAndlastIndex(s, ch, pf, pl);

    // Print values using pointers (dereferencing)
    cout << *pf << " " << *pl << endl;

    // Print values directly (same result)
    cout << first << " " << last << endl;

    return 0;
}