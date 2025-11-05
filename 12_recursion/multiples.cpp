#include <iostream>
using namespace std;

// Recursive function to print the multiplication table of a number up to a given limit
void printMultiples(int base, int multiplier) {
    // Base case: stop when multiplier reaches 0
    if (multiplier == 0) return;

    // Recursive call: go down to multiplier 1
    printMultiples(base, multiplier - 1);

    // Print base × multiplier
    cout << base * multiplier << " ";
}

int main() {
    int base = 5;        // The number whose multiples we want to print
    int limit = 7;       // How many multiples to print

    // Print the multiplication table of 'base' up to 'limit'
    printMultiples(base, limit);  // Output: 5 10 15 20 25 30 35

    return 0;
}