#include<iostream>
using namespace std;

// Recursive function to calculate the sum of digits of a number
int f(int n) {
    // Base case: if n is a single-digit number (0 to 9), return it directly
    if(n >= 0 && n <= 9) 
        return n;

    // Recursive case: add the last digit (n % 10) to the sum of digits of the remaining number (n / 10)
    return f(n / 10) + (n % 10);
}

int main() {
    int n;

    // Enter a number
    cout << "Enter a number: ";
    cin >> n;

    // Call the recursive function to compute the sum of digits
    int result = f(n);

    // Display the result
    cout << "Sum of digits is: " << result << endl;

    return 0;
}