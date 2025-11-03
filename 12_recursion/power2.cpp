#include <iostream>
using namespace std;

// Function to calculate p raised to the power q using Exponentiation by Squaring
int power(int base, int exponent) {
    // Base Case: any number raised to power 0 is 1
    if (exponent == 0) return 1;

    // If exponent is even: p^q = (p^(q/2))^2
    if (exponent % 2 == 0) {
        int halfPower = power(base, exponent / 2);
        return halfPower * halfPower;
    }
    // If exponent is odd: p^q = p * (p^((q-1)/2))^2
    else {
        int halfPower = power(base, (exponent - 1) / 2);
        return base * halfPower * halfPower;
    }
}

int main() {
    int base, exponent;

    // Enter base and exponent
    cout << "Enter base: ";
    cin >> base;

    cout << "Enter exponent: ";
    cin >> exponent;

    int result = power(base, exponent);

    cout << base << " raised to the power " << exponent << " is: " << result << endl;

    return 0;
}