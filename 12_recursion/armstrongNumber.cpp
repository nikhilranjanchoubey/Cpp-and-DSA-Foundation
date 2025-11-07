// Armstrong number checker using recursion
#include <iostream>
using namespace std;

// Efficient recursive function to calculate base^exponent
int power(int base, int exponent) {
    if (exponent == 0) return 1; // Any number to power 0 is 1

    // If exponent is even: use (base^e/2)^2
    if (exponent % 2 == 0) {
        int halfPower = power(base, exponent / 2);
        return halfPower * halfPower;
    }

    // If exponent is odd: use base * (base^((e-1)/2))^2
    int halfPower = power(base, (exponent - 1) / 2);
    return base * halfPower * halfPower;
}

// Recursive function to calculate sum of digits raised to 'd'
int digitPowerSum(int n, int d) {
    if (n == 0) return 0; // Base case

    // Extract last digit, raise to power d, and recurse on remaining digits
    return power(n % 10, d) + digitPowerSum(n / 10, d);
}

int main() {
    int n;
    cin >> n;

    // Count number of digits
    int no_of_digits = 0;
    int temp = n;
    while (temp > 0) {
        temp /= 10;
        no_of_digits++;
    }

    // Check if number is equal to sum of its digits raised to 'no_of_digits'
    int result = digitPowerSum(n, no_of_digits);
    if (result == n) {
        cout << "YES"; // It's an Armstrong number
    } else {
        cout << "NO";  // Not an Armstrong number
    }

    return 0;
}