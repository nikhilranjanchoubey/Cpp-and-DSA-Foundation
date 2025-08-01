#include<iostream>
using namespace std;

int main() {
    // Initialize two integers
    int a = 1;
    int b = 1;

    // Logical OR (||) short-circuits: since 'a' is non-zero (true), '--b' is not evaluated
    // So b remains 1, and c is assigned true (1)
    int c = a || --b; // 'c' becomes 1, b remains 1

    // Logical AND (&&) requires both sides to be true
    // a-- is true (1), then it gets post-decremented (a becomes 0 after this line)
    // Since left side is true, '--b' is evaluated: b becomes 0
    // Since both sides were true during evaluation, 'd' is assigned true (1)
    int d = a-- && --b; // 'd' becomes 1, a becomes 0, b becomes 0

    // Output the final values of a, b, c, d
    cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << endl;

    return 0;
}