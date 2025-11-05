#include <iostream>
using namespace std;

// Recursive function to remove all 'a' characters from the string
string removeA(string &s, int idx, int n) {
    // Base case: if index reaches the end of the string, return empty string
    if (idx == n) return "";

    // Get current character
    string curr = "";
    curr += s[idx];

    // If current character is 'a', skip it; otherwise include it
    return ((s[idx] == 'a') ? "" : curr) + removeA(s, idx + 1, n);
}

int main() {
    
    string s = "abcax";
    int n = s.size();

    // Output
    cout << "New string: " << removeA(s, 0, n) << endl;

    return 0;
}