/* Find the minimum number of brackets
that we need to remove to make the
given bracket sequence balanced. */

#include <iostream>
#include <stack>
using namespace std;

int minimumBracketsToRemove(string s) {
    stack<char> st;

    for(char ch : s) {
        if(ch == '(') {
            st.push(ch);
        }
        else if(ch == ')') {
            if(!st.empty() && st.top() == '(') {
                st.pop();   // matched pair
            }
            else {
                st.push(ch); // unmatched closing bracket
            }
        }
    }

    // Remaining elements in stack are unmatched brackets
    return st.size();
}

int main() {
    string s;
    cin >> s;

    cout << minimumBracketsToRemove(s);

    return 0;
}