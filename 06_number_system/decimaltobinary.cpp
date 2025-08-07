#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;

    vector<int> binary; // To store binary digits

    if (n == 0) {
        binary.push_back(0);
    }

    while (n > 0) {
        binary.push_back(n % 2); // Store remainder
        n /= 2; // Divide by 2
    }

    cout << "Number in binary number system: ";
    for (int i = binary.size() - 1; i >= 0; i--) {
        cout << binary[i];
    }
    cout << endl;

    return 0;
}