#include<iostream>
using namespace std;

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n){

    if(n == 0 or n == 1)
        return n; // Base case: 0th Fibonacci number is 0 &  1st Fibonacci number is 1

    // Recursive call: sum of previous two Fibonacci numbers
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int n;
    cout << "Enter the position (n) in Fibonacci series: " << endl;
    cin >> n;

    int ans = fibonacci(n); // Store the nth Fibonacci number

    cout << "Fibonacci number at position " << n << " is: " << ans << endl;

    return 0;
}