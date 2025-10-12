#include<iostream>
using namespace std;

int main() {
    int n, original, reversed = 0;
    cout << "Enter a number: ";
    cin >> n;

    original = n;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }

    if (original == reversed) {
        cout << "Palindrome number" << endl;
    } else {
        cout << "Not a palindrome number" << endl;
    }

    return 0;
}