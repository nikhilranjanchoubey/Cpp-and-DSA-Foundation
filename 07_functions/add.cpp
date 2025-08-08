#include<iostream>
using namespace std;

// Integer overloads
int add(int num1, int num2) {
    return num1 + num2;
}

int add(int num1, int num2, int num3) {
    return num1 + num2 + num3;
}

// Float overloads
float add(float num1, float num2) {
    return num1 + num2;
}

float add(float num1, float num2, float num3) {
    return num1 + num2 + num3;
}

int main() {
    float a, b, c;
    cout << "Enter three numbers (use 0 for third if not needed): ";
    cin >> a >> b >> c;

    // Check if third number is zero (assuming user enters 0 if they want to add only two numbers)
    if (c == 0.0f) {
        cout << "Sum of two numbers is: " << add(a, b) << endl;
    } else {
        cout << "Sum of three numbers is: " << add(a, b, c) << endl;
    }

    return 0;
}