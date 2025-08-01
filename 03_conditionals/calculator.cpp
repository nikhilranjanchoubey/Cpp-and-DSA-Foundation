// Design a calculator to peform arithmetic operation(+,-,/,*,%)
#include<iostream>
using namespace std;

int main() {
    int n1, n2;
    char op;

    cout << "Enter two integers: ";
    cin >> n1 >> n2;

    cout << "Enter an operator (+, -, /, *, %): ";
    cin >> op;

    switch(op) {
        case '+':
            cout << "Sum is: " << n1 + n2 << endl;
            break;
        case '-':
            cout << "Difference is: " << n1 - n2 << endl;
            break;
        case '*':
            cout << "Product is: " << n1 * n2 << endl;
            break;
        case '/':
            if(n2 != 0)
                cout << "Quotient is: " << n1 / n2 << endl;
            else
                cout << "Error: Division by zero!" << endl;
            break;
        case '%':
            if(n2 != 0)
                cout << "Remainder is: " << n1 % n2 << endl;
            else
                cout << "Error: Modulo by zero!" << endl;
            break;
        default:
            cout << "Invalid operator!" << endl;
    }

    return 0;
}