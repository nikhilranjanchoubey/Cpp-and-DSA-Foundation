#include <iostream>
using namespace std;

int power(int base, int exponent) {
    // Base Case: any number raised to power 0 is 1
    if (exponent == 0) return 1;

    // Recursive Case: base^exponent = base * base^(exponent - 1)
    return base * power(base, exponent - 1);
}

int main() {
    int base, exponent;

    // Enter base and exponent values
    cout << "Enter base: ";
    cin >> base;

    cout << "Enter exponent: ";
    cin >> exponent;

    int result = power(base, exponent);

    cout << base << " raised to the power " << exponent << " is: " << result << endl;

    return 0;
}