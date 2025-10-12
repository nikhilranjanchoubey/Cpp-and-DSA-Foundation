#include<iostream>
using namespace std;

int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    int binaryResult = 0;     
    int placeValue = 1;     

    while (decimalNumber > 0) {
        int remainder = decimalNumber % 2;       
        binaryResult += remainder * placeValue;  
        placeValue *= 10;                        
        decimalNumber /= 2;                     
    }

    cout << "The number in binary number system is " << binaryResult << endl;

    return 0;
}
