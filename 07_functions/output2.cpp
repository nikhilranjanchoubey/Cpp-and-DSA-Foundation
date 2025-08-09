#include<iostream>
using namespace std;

int makeTwice(int p) {
    return p * 2;
}

int main () {
    int p = 24;

    cout << "Twice of 24 is: " << makeTwice(p);

    return 0;
}