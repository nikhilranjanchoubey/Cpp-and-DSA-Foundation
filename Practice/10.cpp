#include<iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of terms: ";
    cin >> n;

    // First two terms of Fibonacci series
    int first = 0, second = 1, next;

    
    if(n <= 0) {
        cout << "Please enter a positive number.";
    }
    else if(n == 1) {
        cout << "Fibonacci series up to " << n << " term: " << first;
    }
    else {
        cout << "Fibonacci series up to " << n << " terms: ";
        cout << first << " " << second << " ";

        // remaining terms
        for(int i = 3; i <= n; i++) {
            next = first + second;
            cout << next << " ";
            first = second;
            second = next;
        }
    }

    return 0;
}