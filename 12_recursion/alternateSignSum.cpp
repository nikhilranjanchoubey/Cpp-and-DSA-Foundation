#include <iostream>
using namespace std;

// Recursive function to calculate the sum of first n natural numbers with alternating signs
int alternatingSum(int n) {
    // Base case: sum of 0 numbers is 0
    if (n == 0) return 0;

    // Recursive case:
    // If n is even, subtract it; if odd, add it
    return alternatingSum(n - 1) + ((n % 2 == 0) ? (-n) : n);
}

int main() {
    int n;

    cout<<"Enter a number: ";
    cin>>n;

    // Calculate and print the alternating sum
    cout << "Alternating sum of first " << n << " natural numbers: " << alternatingSum(n) << endl;

    return 0;
}