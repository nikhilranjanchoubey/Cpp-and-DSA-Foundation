#include<iostream>
using namespace std;

int main() {
    int n;
    int count = 0;

    cout << "Enter a number: ";
    cin >> n;

    if (n == 0) {
        count = 1;
    } else {
        while (n > 0) {
            n = n / 10;
            count++;
        }
    }

    cout << "No. of digits is: " << count << endl;

    return 0;
}