#include <iostream>
using namespace std;

class Number {
private:
    int x;

public:
    Number(int a) {
        x = a;
    }

    // Friend function declaration
    friend void showValue(Number n);
};

// Friend function definition
void showValue(Number n) {
    // Can access private member x
    cout << "Value of x = " << n.x << endl;
}

int main() {
    Number obj(10);

    showValue(obj);  // calling friend function

    return 0;
}
