#include <iostream>
using namespace std;

void showMessage() {
    int localVar = 42;  // Local variable
    cout << "Inside showMessage, localVar = " << localVar << endl;
}

int main() {
    showMessage();

    // Trying to access localVar here would cause an error
    // cout << localVar;  // Error: 'localVar' was not declared in this scope

    for (int i = 0; i < 3; i++) {
        int loopVar = i * 2;  // Local to the loop block
        cout << "loopVar = " << loopVar << endl;
    }

    // cout << loopVar;  // Error: 'loopVar' was not declared in this scope

    return 0;
}