#include <iostream>
using namespace std;

// Recursive function to calculate GCD using Euclidean algorithm
int findGCD(int a, int b) {
    if (b > a) return findGCD(b, a); // Ensure a ≥ b
    if (b == 0) return a;            // Base case
    return findGCD(b, a % b);        // Recursive step
}

int main() {
    int num1, num2;

    // Enter two numbers
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Call the GCD function and print the result
    cout << "GCD of " << num1 << " and " << num2 << " is: " << findGCD(num1, num2) << endl;

    return 0;
}