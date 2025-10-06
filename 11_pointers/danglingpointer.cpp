#include <iostream>
using namespace std;

int main() {

    int *ptr = NULL;
    {
        int x = 10;
        ptr = &x;
    }

    return 0;
}

/* #include <iostream>
using namespace std;

int* createDangling() {
    int x = 42;      // Local variable
    return &x;       // Returning address of local variable — dangerous!
}

int main() {
    int *ptr = createDangling();  // ptr now points to memory that no longer exists

    cout << *ptr << endl;         // Undefined behavior — dangling pointer

    return 0;
} */