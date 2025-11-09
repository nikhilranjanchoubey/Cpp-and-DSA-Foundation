/*Given a string containing digits from 2–9 inclusive,
return all possible letter combinations that the number could represent.
Return the answer in any order.

Input: digits = "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]*/ 

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all letter combinations
void f(string &str, int i, string result, vector<string> &li, vector<string> &v) {
    // Base case: if we've processed all digits, store the result
    if(i == str.size()) {
        li.push_back(result);
        return;
    }

    int digit = str[i] - '0'; // Convert char to int
    if(digit <= 1) {
        // Digits 0 and 1 don't map to any letters
        f(str, i + 1, result, li, v);
        return;
    }

    // Explore all letters mapped to the current digit
    for(int j = 0; j < v[digit].size(); j++) {
        f(str, i + 1, result + v[digit][j], li, v);
    }
}

int main() {
    // Mapping digits to corresponding letters (like on a phone keypad)
    vector<string> v = {"*", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string str = "23"; // Input digit string
    vector<string> li; // To store all combinations

    f(str, 0, "", li, v); // Start recursive generation

    // Print all combinations
    for(int i = 0; i < li.size(); i++) {
        cout << li[i] << " ";
    }

    return 0;
}