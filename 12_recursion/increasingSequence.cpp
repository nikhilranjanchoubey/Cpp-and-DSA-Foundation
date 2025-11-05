#include <iostream>
using namespace std;

// Recursive function to print numbers from 1 to n
void number(int n) {
    // Base case: stop when n drops below 1
    if (n < 1) return;

    // Recursive call first (goes deep to 1)
    number(n - 1);

    // Print after recursion (backtracking phase)
    cout << n << " ";
}

int main() {
    number(5); // Output: 1 2 3 4 5
    return 0;
}