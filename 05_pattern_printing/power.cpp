// Given 2 numbers a and b.
// Find a raise to the power b.

#include<iostream>
using namespace std;

int main () {
    int a, b;
    cout << "Enter base (a): ";
    cin >> a;
    
    cout << "Enter exponent (b): ";
    cin >> b;

    int power = 1;
    for (int i = 1; i <= b; i++) {
        power *= a;
    }

    cout << a << " raised to the power " << b << " is: " << power << endl;

    return 0;
}