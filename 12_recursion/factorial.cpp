#include<iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n){
    if(n == 1)
        return 1; // Base case: factorial of 1 is 1

    int ans = n * factorial(n - 1); // Recursive call
    return ans; // Return the computed factorial
}

int main(){
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;

    int ans = factorial(n); // Store the result of factorial in 'ans'

    cout << "Factorial of " << n << " is: " << ans << endl;

    return 0;
}